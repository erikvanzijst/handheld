#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/2player.h"
#include "../include/button.h"
#include "../include/melody.h"
#include "../include/next.h"
#include "../include/screen.h"
#include "../include/sound.h"
#include "../include/tetrominos.h"
#include "../include/wallclock.h"
#include "../include/util.h"
#include "../include/tetris.h"
#include "../utils/atomic.h"

typedef struct {
    /*
     * The player's tetris board.
     */
    uint16_t board[ROWS];

    /*
     * The total number of lines cleared by the player since the start of the
     * game.
     */
    uint16_t lines;
} game_state_t;

volatile game_state_t peer_game_state;

void irda_receive(uint8_t *buf, uint16_t len) {
    memcpy((uint8_t *)&peer_game_state, buf, min(sizeof(peer_game_state), len));
}

uint64_t last_stats = 0;
void print_irda_stats() {
    uint64_t now = millis();
    if (now - last_stats > 4000) {
        link_stats_t stats;
        irda_stats(&stats);
        printf("IrDA:\r\n");
        printf("  bytes out:  %9lu\r\n", stats.bytes_out);
        printf("  bytes in:   %9lu\r\n", stats.bytes_in);
        printf("  timeouts:   %9lu\r\n", stats.timeouts);
        printf("  CRC errors: %9lu\r\n", stats.crc_errors);
        last_stats = now;
    }
}

void draw_and_publish(game_state_t *our_game_state, fallingbrick_t *brick) {
    shape_t shape;
    game_state_t our_game_state_cp, their_game_state_cp;

    materialize(&shape, brick);
    memcpy(&our_game_state_cp, our_game_state, sizeof(our_game_state_cp));
    DISABLE_INTERRUPTS();
    their_game_state_cp = peer_game_state;
    ENABLE_INTERRUPTS();

    // paint the brick that is in motion onto our board copy:
    for (uint8_t i = 0; i < 4; i++) {
        our_game_state_cp.board[shape.vertex[i].y] |= (0x8000 >> (shape.vertex[i].x));
    }

    for (uint8_t i = 0; i < ROWS; i++) {
        // clear the two board sections of the screen line:
        screen[i][0] &= 0x80;
        screen[i][1] &= 0x18;
        screen[i][2] &= 0x01;

        // project our side of the new board line:
        screen[i][0] |= (our_game_state_cp.board[i] >> 9);
        screen[i][1] |= (our_game_state_cp.board[i] >> 1);

        // project their side of the new board line:
        screen[i][1] |= (their_game_state_cp.board[i] >> 13);
        screen[i][2] |= (their_game_state_cp.board[i] >> 5);
    }

    if (irda_write_available()) {
        irda_write((uint8_t *)&our_game_state_cp, sizeof(our_game_state_cp));
    }
}

/*
 * Enters the Tetris main loop. This function does not return until the game
 * exits.
 */
void multi_player() {
    clear_screen();

    game_state_t game_state = {.lines = 0};
    uint16_t speed = get_speed(game_state.lines);
    memset(game_state.board, 0, sizeof(uint16_t) * ROWS);
    uint64_t now = millis();

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
            if (move(&copy, &brick, 0, &left, game_state.board)) {
                memcpy(&brick, &copy, sizeof(fallingbrick_t));
            }
            last_press = millis();
        }
        if (was_pressed(&btn_right)) {
            if (move(&copy, &brick, 0, &right, game_state.board)) {
                memcpy(&brick, &copy, sizeof(fallingbrick_t));
            }
            last_press = millis();
        }
        if (was_pressed(&btn_b)) {
            if (move(&copy, &brick, 1, &identity, game_state.board)) {
                memcpy(&brick, &copy, sizeof(fallingbrick_t));
            }
            last_press = millis();
        }
        if (was_pressed(&btn_x)) {
            if (move(&copy, &brick, -1, &identity, game_state.board)) {
                memcpy(&brick, &copy, sizeof(fallingbrick_t));
            }
            last_press = millis();
        }

        if (was_pressed(&btn_a)) {
            now -= speed;
        } else if (long_pressed(&btn_a)) {
            speed = 40;
        } else {
            speed = get_speed(game_state.lines);
        }
        if ((millis() - now) > speed) {

            if (move(&copy, &brick, 0, &down, game_state.board)) {
                now = millis();
//                printf("Brick moved down.\r\n");
                memcpy(&brick, &copy, sizeof(fallingbrick_t));
            } else if (last_press > now) {
                // we hit the ground, but as long as we keep pressing buttons, we delay merging:
                now += last_press - now;
            } else {
                now = millis();
                printf("Could not move down; merging.\r\n");
                const uint8_t removed = merge(&brick, game_state.board);
                game_state.lines += removed;

                brick.id = take_upcoming();
                brick.rotation = 0;
                brick.location.x = 4;
                brick.location.y = 0;

                if (!move(&copy, &brick, 0, &down, game_state.board)) {
                    stop_melody();
                    printf("Game over!\r\n");
//                    gameover(score, hiscore);
                    return;
                }
            }
        }
        draw_and_publish(&game_state, &brick);
        print_irda_stats();
    }
}
