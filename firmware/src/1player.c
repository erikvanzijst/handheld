#include <compiler.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <util/delay.h>

#include "../include/1player.h"
#include "../include/button.h"
#include "../include/font.h"
#include "../include/hiscore.h"
#include "../include/melody.h"
#include "../include/next.h"
#include "../include/screen.h"
#include "../include/sound.h"
#include "../include/tetrominos.h"
#include "../include/wallclock.h"
#include "../include/util.h"
#include "../include/tetris.h"

void draw_hold(uint8_t brick_id) {
    // clear hold area:
    for (uint8_t row = 0; row < 5; row++) {
        screen[row][0] &= 0x3;
    }
    for (uint8_t i = 0; i < 4; i++) {
        set_pixel(brickdefs[brick_id].shape[0].vertex[i].x + 2,
                  brickdefs[brick_id].shape[0].vertex[i].y + 1,
                  true);
    }
}

void print_brick(fallingbrick_t *brick) {
    shape_t shape;
    materialize(&shape, brick);
    printf("Tetromino %d: [rotation: %d] ", brick->id, brick->rotation);
    for (uint8_t i = 0; i < 4; i++) {
        printf("(%d, %d) ", shape.vertex[i].x, shape.vertex[i].y);
    }
    printf("\r\n");
}

void drawboard(uint16_t *board, fallingbrick_t *brick) {
    shape_t shape;
    materialize(&shape, brick);

    for (uint8_t i = 0; i < ROWS; i++) {
        // clear the board section of the screen line:
        screen[i][0] &= 0xfe;
        screen[i][1] = 0;
        screen[i][2] &= 0x7f;

        // project the new board line:
        screen[i][0] |= (board[i] >> 15);
        screen[i][1] |= (board[i] >> 7);
        screen[i][2] |= (board[i] << 1);
    }

    // paint the brick that is in motion:
    for (uint8_t i = 0; i < 4; i++) {
        set_pixel(shape.vertex[i].x + 7, shape.vertex[i].y, true);
    }
}

/*
 * Enters the Tetris main loop. This function does not return until the game
 * exits.
 */
void single_player() {

    printf("Clear screen\r\n");
    clear_screen();

    uint16_t lines = 0;
    uint32_t score = 0;
    uint16_t speed = get_speed(lines);
    uint64_t now = millis();
    uint16_t board[ROWS];
    memset(board, 0, sizeof(uint16_t) * ROWS);

    // initialize the upcoming queue:
    initialize_upcoming();

    // paint background:
    printf("Drawing background...\r\n");
    for (uint8_t row = 0; row < ROWS; row++)
    {
        screen[row][0] = 2;
        screen[row][1] = 0;
        screen[row][2] = 64;
    }

    fallingbrick_t brick = {
            .id = take_upcoming(),
            .rotation = 0,
            .location = {.x = 4, .y = 0}
    };
    fallingbrick_t copy;
    uint8_t hold = take_upcoming();
    bool hold_allowed = true;

    draw_upcoming();
    draw_hold(hold);

    play_melody(&tetris_melody, -1);
    printf("Game started...\r\n");

    uint64_t last_press = 0;
    while (true) {
        pause();

        if (was_pressed(&btn_left)) {
            if (move(&copy, &brick, 0, &left, board)) {
                memcpy(&brick, &copy, sizeof(fallingbrick_t));
                drawboard(board, &brick);
            }
            last_press = millis();
        }
        if (was_pressed(&btn_right)) {
            if (move(&copy, &brick, 0, &right, board)) {
                memcpy(&brick, &copy, sizeof(fallingbrick_t));
                drawboard(board, &brick);
            }
            last_press = millis();
        }
        if (was_pressed(&btn_b)) {
            if (move(&copy, &brick, 1, &identity, board)) {
                memcpy(&brick, &copy, sizeof(fallingbrick_t));
                drawboard(board, &brick);
            }
            last_press = millis();
        }
        if (was_pressed(&btn_x)) {
            if (move(&copy, &brick, -1, &identity, board)) {
                memcpy(&brick, &copy, sizeof(fallingbrick_t));
                drawboard(board, &brick);
            }
            last_press = millis();
        }

        if (was_pressed(&btn_up)) {   // hold pressed
            memcpy(&copy, &brick, sizeof(fallingbrick_t));
            copy.id = hold;
            if (hold_allowed && fits(&copy, board)) {
                // Swap the current and hold bricks
                hold = brick.id;
                memcpy(&brick, &copy, sizeof(fallingbrick_t));
                drawboard(board, &brick);
                draw_hold(hold);
                hold_allowed = false;
            }
        }

        if (was_pressed(&btn_select)) {
            mute(!is_muted());
        }
        if (was_pressed(&btn_a)) {
            now -= speed;
        } else if (long_pressed(&btn_a)) {
            speed = 40;
        } else {
            speed = get_speed(lines);
        }

        if ((millis() - now) > speed) {

            if (move(&copy, &brick, 0, &down, board)) {
                now = millis();
                printf("Brick moved down. ");
                print_brick(&brick);
                memcpy(&brick, &copy, sizeof(fallingbrick_t));
            }
            else if (last_press > now) {
                // we hit the ground, but as long as we keep pressing buttons, we delay merging:
                now += last_press - now;
            }
            else {
                now = millis();
                printf("Could not move down; merging.\r\n");
                const uint8_t removed = merge(&brick, board);
                lines += removed;
                score += linevalue[min(removed, 4)] + 1;

                brick.id = take_upcoming();
                brick.rotation = 0;
                brick.location.x = 4;
                brick.location.y = 0;
                draw_upcoming();
                hold_allowed = true;

                if (!move(&copy, &brick, 0, &down, board)) {
                    stop_melody();
                    const uint32_t hiscore = get_and_set_hiscore(score);
                    printf("Game over! Score: %d, highest: %d\r\n", score, hiscore);
                    gameover(score, hiscore);
                    return;
                }
            }
            drawboard(board, &brick);
        }
    }
}
