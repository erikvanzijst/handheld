#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/2player.h"
#include "../include/button.h"
#include "../include/hiscore.h"
#include "../include/melody.h"
#include "../include/next.h"
#include "../include/screen.h"
#include "../include/sound.h"
#include "../include/tetrominos.h"
#include "../include/wallclock.h"
#include "../include/util.h"
#include "../include/tetris.h"
#include "../utils/atomic.h"

uint16_t their_board[ROWS];

void irda_receive(uint8_t *buf, uint16_t len) {
    memcpy(their_board, buf, min(sizeof(their_board), len));
}

void draw_us(uint16_t *board, fallingbrick_t *brick) {
    shape_t shape;
    materialize(&shape, brick);

    uint16_t us[ROWS];
    uint16_t them[ROWS];

    DISABLE_INTERRUPTS();
    memcpy(them, their_board, sizeof(their_board));
    ENABLE_INTERRUPTS();
    memcpy(us, board, sizeof(us));

    // paint the brick that is in motion onto our board copy:
    for (uint8_t i = 0; i < 4; i++) {
        us[shape.vertex[i].y] |= (0x8000 >> (shape.vertex[i].x));
    }

    for (uint8_t i = 0; i < ROWS; i++) {
        // clear the left board section of the screen line:
        screen[i][0] &= 0x80;
        screen[i][1] &= 0x18;
        screen[i][2] &= 0x01;

        // project our side of the new board line:
        screen[i][0] |= (us[i] >> 9);
        screen[i][1] |= (us[i] >> 1);

        // project their side of the new board line:
        screen[i][1] |= (them[i] >> 13);
        screen[i][2] |= (them[i] >> 5);
    }

    if (irda_write_available()) {
        irda_write((uint8_t *)us, sizeof(us));
    }
}

/*
 * Enters the Tetris main loop. This function does not return until the game
 * exits.
 */
void multi_player() {

    printf("Clear screen\r\n");
    clear_screen();
    printf("Scrolling banner...\r\n");
//    scroll("TETRIS      ", "", -1);
    srand((unsigned int)millis()); // use human button press delay as random seed

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
    for (uint8_t row = 0; row < ROWS; row++) {
        screen[row][0] = 0x80;
        screen[row][1] = 0x18;
        screen[row][2] = 0x01;
    }

    fallingbrick_t brick = {
            .id = take_upcoming(),
            .rotation = 0,
            .location = {.x = 4, .y = 0}
    };
    fallingbrick_t copy;

    printf("Game started...\r\n");

    uint64_t last_press = 0;

    irda_enable(irda_receive);
    while (true) {
        if (was_pressed(&btn_left)) {
            if (move(&copy, &brick, 0, &left, board)) {
                memcpy(&brick, &copy, sizeof(fallingbrick_t));
            }
            last_press = millis();
        }
        if (was_pressed(&btn_right)) {
            if (move(&copy, &brick, 0, &right, board)) {
                memcpy(&brick, &copy, sizeof(fallingbrick_t));
            }
            last_press = millis();
        }
        if (was_pressed(&btn_b)) {
            if (move(&copy, &brick, 1, &identity, board)) {
                memcpy(&brick, &copy, sizeof(fallingbrick_t));
            }
            last_press = millis();
        }
        if (was_pressed(&btn_x)) {
            if (move(&copy, &brick, -1, &identity, board)) {
                memcpy(&brick, &copy, sizeof(fallingbrick_t));
            }
            last_press = millis();
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
//                printf("Brick moved down.\r\n");
                memcpy(&brick, &copy, sizeof(fallingbrick_t));
            } else if (last_press > now) {
                // we hit the ground, but as long as we keep pressing buttons, we delay merging:
                now += last_press - now;
            } else {
                now = millis();
                printf("Could not move down; merging.\r\n");
                const uint8_t removed = merge(&brick, board);
                lines += removed;
                score += linevalue[min(removed, 4)] + 1;

                brick.id = take_upcoming();
                brick.rotation = 0;
                brick.location.x = 4;
                brick.location.y = 0;

                if (!move(&copy, &brick, 0, &down, board)) {
                    stop_melody();
                    const uint32_t hiscore = get_and_set_hiscore(score);
                    printf("Game over! Score: %d, highest: %d\r\n", score, hiscore);
//                    gameover(score, hiscore);
                    return;
                }
            }
        }
        draw_us(board, &brick);
    }
}
