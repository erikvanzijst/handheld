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
#include "../include/font.h"

#define CONNECTION_TIMEOUT_MS   500
#define PLAYER_DEAD_bm          0x01
#define PLAYER_DEAD_ACK_bm      0x02

typedef struct {
    /*
     * The player's tetris board.
     */
    uint16_t board[ROWS];

    /*
     * The total number of lines cleared by the player since the start of the
     * game.
     */
    uint8_t lines_cleared;

    /*
     * Total number of lines received from the peer and applied to our board.
     */
    uint8_t lines_added;

    /*
     * PLAYER_DEAD_bm
     * PLAYER_DEAD_ACK_bm
     */
    uint8_t flags;
} game_state_t;

volatile game_state_t peer_game_state;
volatile uint64_t last_packet_ms;       // timestamp of the most recent packet

bool is_connected(uint64_t now) {
    uint64_t last_packet_ms_cp;
    DISABLE_INTERRUPTS();
    last_packet_ms_cp = last_packet_ms;
    ENABLE_INTERRUPTS();
    return now - last_packet_ms_cp < CONNECTION_TIMEOUT_MS;
}

void connect(game_state_t * our_game_state) {
    printf("Waiting for peer...\r\n");
    while (!is_connected(millis()) || (peer_game_state.flags & (PLAYER_DEAD_bm | PLAYER_DEAD_ACK_bm))) {
        irda_write((uint8_t *)&our_game_state, sizeof(game_state_t));
    }
    printf("Connected to peer! connected = %d, peer.flags = %d\r\n", is_connected(millis()), peer_game_state.flags);
    // TODO: draw something on the screen
}

void irda_receive(uint8_t *buf, uint16_t len) {
    memcpy((uint8_t *)&peer_game_state, buf, min(sizeof(peer_game_state), len));
    last_packet_ms = millis();
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

bool apply_peer_lines(game_state_t * our_game_state, game_state_t * their_game_state, fallingbrick_t * brick) {
    fallingbrick_t brick_cp;
    uint8_t peer_lines;
    DISABLE_INTERRUPTS();
    peer_lines = their_game_state->lines_cleared;
    ENABLE_INTERRUPTS();

    for (; peer_lines > our_game_state->lines_added; our_game_state->lines_added++) {
        if (!move(&brick_cp, brick, 0, &down, our_game_state->board)) {
            brick->location.y--;
        }
        for (int i = 0; i < ROWS - 1; i++) {
            our_game_state->board[i] = our_game_state->board[i + 1];
        }
        our_game_state->board[ROWS - 1] = ~(0x0040 << rand_under(10));
    }
    return brick->location.y >= 0;          // whether we were able to insert all penalty lines
}

void game_over_mp(volatile game_state_t * our_game_state, bool win) {
    uint64_t now = millis();
    our_game_state->flags |= PLAYER_DEAD_bm;
    if (win) {
        printf("YOU WIN\r\n");
        printf("Ack'ing peer's death...\r\n");
        our_game_state->flags |= PLAYER_DEAD_ACK_bm;

        printf("Waiting for peer to ack our ack...\r\n");
        while (!((peer_game_state.flags == 0x03) || peer_game_state.flags == 0)) {  // TODO: use the other one
            if (millis() - now > 5000) {
                printf("peer_game_state.flags = %x connected = %d\r\n", peer_game_state.flags, is_connected(millis()));
                now = millis();
            }
            irda_write((uint8_t *)our_game_state, sizeof(game_state_t));
        }
        printf("Peer either ack'd our ack, or restarted.\r\n");

    } else {
        printf("YOU LOSE\r\n");

        printf("Waiting for peer to die also...\r\n");
        while (!((peer_game_state.flags == 0x03 && our_game_state->flags & PLAYER_DEAD_ACK_bm) || (peer_game_state.flags == 0 && our_game_state->flags & PLAYER_DEAD_ACK_bm))) {
            if (peer_game_state.flags & PLAYER_DEAD_bm && !(our_game_state->flags & PLAYER_DEAD_ACK_bm)) {
                printf("Peer now also stopped; waiting for peer to ack our ack...\r\n");
                our_game_state->flags |= PLAYER_DEAD_ACK_bm;
            }
            irda_write((uint8_t *)our_game_state, sizeof(game_state_t));
        }
        printf("Peer either ack'd our ack, or restarted; peer_game_state.flags = %x\r\n", peer_game_state.flags);
    }

    printf("Press any key to start new game.\r\n");
    say(win ? "WIN " : "LOSE");
    while (!any_key()) {
        irda_write((uint8_t *)our_game_state, sizeof(game_state_t));
    }
}

/*
 * Enters the Tetris main loop. This function does not return until the game
 * exits.
 */
void multi_player() {
    clear_screen();

    game_state_t game_state = {
            .lines_cleared = 0,
            .flags = 0
    };
    fallingbrick_t brick, brick_cp;
    uint16_t speed = get_speed(game_state.lines_cleared);
    memset(game_state.board, 0, sizeof(uint16_t) * ROWS);
    uint64_t now = millis();

    // initialize the upcoming queue:
    initialize_upcoming();

    brick.id = take_upcoming();
    brick.rotation = 0;
    brick.location.x = 4;
    brick.location.y = 0;

    // paint background:
    printf("Drawing background...\r\n");
    for (uint8_t row = 0; row < ROWS; row++) {
        screen[row][0] = 0x80;
        screen[row][1] = 0x18;
        screen[row][2] = 0x01;
    }

    printf("Game started...\r\n");

    uint64_t last_press = 0;

    irda_enable(irda_receive);
    connect(&game_state);

    while (true) {
        if (peer_game_state.flags & PLAYER_DEAD_bm) {
            game_over_mp(&game_state, true);
            return;
        }

        if (was_pressed(&btn_left)) {
            if (move(&brick_cp, &brick, 0, &left, game_state.board)) {
                memcpy(&brick, &brick_cp, sizeof(fallingbrick_t));
            }
            last_press = millis();
        }
        if (was_pressed(&btn_right)) {
            if (move(&brick_cp, &brick, 0, &right, game_state.board)) {
                memcpy(&brick, &brick_cp, sizeof(fallingbrick_t));
            }
            last_press = millis();
        }
        if (was_pressed(&btn_b)) {
            if (move(&brick_cp, &brick, 1, &identity, game_state.board)) {
                memcpy(&brick, &brick_cp, sizeof(fallingbrick_t));
            }
            last_press = millis();
        }
        if (was_pressed(&btn_x)) {
            if (move(&brick_cp, &brick, -1, &identity, game_state.board)) {
                memcpy(&brick, &brick_cp, sizeof(fallingbrick_t));
            }
            last_press = millis();
        }

        if (was_pressed(&btn_a)) {
            now -= speed;
        } else if (long_pressed(&btn_a)) {
            speed = 40;
        } else {
            speed = get_speed(game_state.lines_cleared);
        }

        if (!apply_peer_lines(&game_state, &peer_game_state, &brick)) {
            game_over_mp(&game_state, false);
            return;
        }

        if ((millis() - now) > speed) {

            if (move(&brick_cp, &brick, 0, &down, game_state.board)) {
                now = millis();
//                printf("Brick moved down.\r\n");
                memcpy(&brick, &brick_cp, sizeof(fallingbrick_t));
            } else if (last_press > now) {
                // we hit the ground, but as long as we keep pressing buttons, we delay merging:
                now += last_press - now;
            } else {
                now = millis();
                printf("Could not move down; merging.\r\n");
                game_state.lines_cleared += merge(&brick, game_state.board);

                brick.id = take_upcoming();
                brick.rotation = 0;
                brick.location.x = 4;
                brick.location.y = 0;

                if (!move(&brick_cp, &brick, 0, &down, game_state.board)) {
                    game_over_mp(&game_state, false);
//                    stop_melody();
//                    gameover(score, hiscore);
                    return;
                }
            }
        }
        draw_and_publish(&game_state, &brick);
        print_irda_stats();
    }
}
