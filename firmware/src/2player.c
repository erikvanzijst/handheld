#include <stdint.h>
#include <stdio.h>
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
#include "../include/alarm.h"

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
volatile game_state_t our_game_state;
volatile fallingbrick_t brick;
volatile uint64_t last_packet_ms;       // timestamp of the most recent packet

void publish_board() {
    shape_t shape;
    game_state_t our_game_state_cp;

    if (irda_write_available()) {
        materialize(&shape, &brick);
        memcpy(&our_game_state_cp, &our_game_state, sizeof(game_state_t));

        // paint the brick that is in motion onto our board copy:
        for (uint8_t i = 0; i < 4; i++) {
            our_game_state_cp.board[shape.vertex[i].y] |= (0x8000 >> (shape.vertex[i].x));
        }
        irda_write((uint8_t *)&our_game_state_cp, sizeof(game_state_t));
    }
    // reschedule ourselves
    set_alarm(ALARM2, 200, publish_board);
}

bool is_connected() {
    volatile uint64_t last_packet_ms_cp;
    DISABLE_INTERRUPTS();
    last_packet_ms_cp = last_packet_ms;
    ENABLE_INTERRUPTS();
    return (millis() - last_packet_ms_cp) < CONNECTION_TIMEOUT_MS;
}

void connect() {
    printf("Waiting for peer...\r\n");

    uint8_t screen_cp[ROWS][3];
    memcpy(&screen_cp, &screen, sizeof(screen_cp));             // save the screen

    uint8_t pos[4] = {0, 1, 3, 2};
    uint8_t idx = 0;
    uint64_t last = 0;

    screen[6][2] &= 0x0f;
    screen[7][2] &= 0x0f;
    screen[8][2] &= 0x0f;
    screen[9][2] &= 0x0f;

    // display a spinner in the right-hand section:
    while (!is_connected() || (peer_game_state.flags & (PLAYER_DEAD_bm | PLAYER_DEAD_ACK_bm))) {
        if (millis() - last > 200) {
            set_pixel(17 + ((pos[idx] & 0x1) ? 1 : 0), 7 + ((pos[idx] & 0x2) ? 1 : 0), 0);
            idx = (idx + 1) % 4;
            set_pixel(17 + ((pos[idx] & 0x1) ? 1 : 0), 7 + ((pos[idx] & 0x2) ? 1 : 0), 1);
            last = millis();
        }
    }

    memcpy(&screen, &screen_cp, sizeof(screen_cp));             // restore screen
    printf("Connected to peer!\r\n");
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

void draw_screen() {
    shape_t shape;
    game_state_t our_game_state_cp, their_game_state_cp;

    materialize(&shape, &brick);
    memcpy(&our_game_state_cp, &our_game_state, sizeof(our_game_state_cp));
    DISABLE_INTERRUPTS();
    their_game_state_cp = peer_game_state;
    ENABLE_INTERRUPTS();

    // paint the brick that is in motion onto our board copy:
    for (uint8_t i = 0; i < 4; i++) {
        our_game_state_cp.board[shape.vertex[i].y] |= (0x8000 >> (shape.vertex[i].x));
    }

    for (uint8_t i = 0; i < ROWS; i++) {
        // project our side of the new board line:
        screen[i][0] = 0x80 | (our_game_state_cp.board[i] >> 9);
        screen[i][1] = (our_game_state_cp.board[i] >> 1) | 0x18 | (their_game_state_cp.board[i] >> 13);
        screen[i][2] = (their_game_state_cp.board[i] >> 5) | 0x01;
    }
}

bool apply_peer_lines() {
    fallingbrick_t brick_cp;
    game_state_t our_game_state_cp;
    uint8_t peer_lines;

    DISABLE_INTERRUPTS();                   // Avoid race conditions with publishing ISR
    peer_lines = peer_game_state.lines_cleared;
    ENABLE_INTERRUPTS();
    memcpy(&our_game_state_cp, &our_game_state, sizeof(game_state_t));

    for (; peer_lines > our_game_state_cp.lines_added; our_game_state_cp.lines_added++) {
        if (!move(&brick_cp, &brick, 0, &down, our_game_state_cp.board)) {
            brick.location.y--;
        }
        for (int i = 0; i < ROWS - 1; i++) {
            our_game_state_cp.board[i] = our_game_state_cp.board[i + 1];
        }
        our_game_state_cp.board[ROWS - 1] = ~(0x0040 << rand_under(10));
    }
    DISABLE_INTERRUPTS();                   // Avoid race conditions with publishing ISR
    memcpy(&our_game_state, &our_game_state_cp, sizeof(game_state_t));
    ENABLE_INTERRUPTS();

    return brick.location.y >= 0;          // whether we were able to insert all penalty lines
}

void game_over_mp(bool win) {
    stop_melody();
    if (win) {
        our_game_state.flags |= (PLAYER_DEAD_bm | PLAYER_DEAD_ACK_bm);
        play_melody(&victory_melody, 1);
    } else {
        our_game_state.flags |= PLAYER_DEAD_bm;
        play_melody(&gameover_melody, 1);
    }

    while (!((peer_game_state.flags == 0x03 && our_game_state.flags & PLAYER_DEAD_ACK_bm) ||
             (peer_game_state.flags == 0 && our_game_state.flags & PLAYER_DEAD_ACK_bm))) {
        if (peer_game_state.flags & PLAYER_DEAD_bm) {
            our_game_state.flags |= PLAYER_DEAD_ACK_bm;
        }
    }

    uint64_t now = millis();
    while (millis() - now < 2000) {         // suppress key presses for 2s to show the post-game result screen
        for (uint8_t i = 4; i <= 10; i++) {
            screen[i][0] = screen[i][1] = screen[i][2] = 0;
        }
        scroll(win ? "WIN " : "LOSE ", "", -1);
    }
    stop_melody();
}

/*
 * Enters the Tetris main loop. This function does not return until the game
 * exits.
 */
void multi_player() {
    fallingbrick_t brick_cp;
    bool muted = false;
    clear_screen();

    memset(&our_game_state, 0, sizeof(game_state_t));
    uint16_t speed = get_speed(our_game_state.lines_cleared);
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
    publish_board();                            // starts automatic background publishing
    connect();                                  // wait for connection to be established
    play_melody(&tetris_melody, -1);

    while (true) {
        if (peer_game_state.flags & PLAYER_DEAD_bm) {
            game_over_mp(true);
            return;
        }
        if (!apply_peer_lines()) {
            game_over_mp(false);
            return;
        }

        draw_screen();
        print_irda_stats();

        bool pre = is_muted();
        if (!is_connected()) {
            mute(true);                 // pause the sound while disconnected
            connect();
        }
        mute(pre);

        if (was_pressed(&btn_select)) {
            mute(!is_muted());
        }
        if (was_pressed(&btn_left)) {
            if (move(&brick_cp, &brick, 0, &left, our_game_state.board)) {
                memcpy(&brick, &brick_cp, sizeof(fallingbrick_t));
            }
            last_press = millis();
        }
        if (was_pressed(&btn_right)) {
            if (move(&brick_cp, &brick, 0, &right, our_game_state.board)) {
                memcpy(&brick, &brick_cp, sizeof(fallingbrick_t));
            }
            last_press = millis();
        }
        if (was_pressed(&btn_b)) {
            if (move(&brick_cp, &brick, 1, &identity, our_game_state.board)) {
                memcpy(&brick, &brick_cp, sizeof(fallingbrick_t));
            }
            last_press = millis();
        }
        if (was_pressed(&btn_x)) {
            if (move(&brick_cp, &brick, -1, &identity, our_game_state.board)) {
                memcpy(&brick, &brick_cp, sizeof(fallingbrick_t));
            }
            last_press = millis();
        }

        if (was_pressed(&btn_a)) {
            now -= speed;
        } else if (long_pressed(&btn_a)) {
            speed = 40;
        } else {
            speed = get_speed(our_game_state.lines_cleared);
        }

        if ((millis() - now) > speed) {

            if (move(&brick_cp, &brick, 0, &down, our_game_state.board)) {
                now = millis();
                memcpy(&brick, &brick_cp, sizeof(fallingbrick_t));

            } else if (last_press > now) {
                // we hit the ground, but as long as we keep pressing buttons, we delay merging:
                now += last_press - now;

            } else {
                now = millis();
                printf("Could not move down; merging.\r\n");
                uint16_t board_cp[ROWS];
                memcpy(&board_cp, our_game_state.board, sizeof(board_cp));
                our_game_state.lines_cleared += merge(&brick, board_cp);
                DISABLE_INTERRUPTS();
                // atomically modify the board to avoid possible race conditions with interrupt-driven irda_write()
                memcpy(our_game_state.board, &board_cp, sizeof(board_cp));
                ENABLE_INTERRUPTS();

                brick.id = take_upcoming();
                brick.rotation = 0;
                brick.location.x = 4;
                brick.location.y = 0;

                if (!move(&brick_cp, &brick, 0, &down, our_game_state.board)) {
                    game_over_mp(false);
                    return;
                }
            }
        }
    }
}
