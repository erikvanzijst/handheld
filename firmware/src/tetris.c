#include <compiler.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <util/delay.h>
#include "button.h"
#include "font.h"
#include "hiscore.h"
#include "next.h"
#include "screen.h"
#include "tetris.h"
#include "tetrominos.h"
#include "wallclock.h"

#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

#define min(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })

#define WIDTH 10    // width of tetris board

vertex_t down = {0, 1};
vertex_t left = {-1, 0};
vertex_t right = {1, 0};
vertex_t identity = {0, 0};
const uint16_t linevalue[] = {0, 40, 100, 300, 1200};

typedef struct {
  uint8_t id;
  uint8_t rotation;
  vertex_t location;
} fallingbrick_t;

void materialize(shape_t *dest, fallingbrick_t *brick) {
  for (uint8_t i = 0; i < 4; i++) {
    dest->vertex[i].x = brickdefs[brick->id].shape[brick->rotation].vertex[i].x + brick->location.x;
    dest->vertex[i].y = brickdefs[brick->id].shape[brick->rotation].vertex[i].y + brick->location.y;
  }
}

bool fits(fallingbrick_t *brick, uint16_t *board) {
  shape_t shape;
  materialize(&shape, brick);

  for (uint8_t i = 0; i < 4; i++) {
    if (shape.vertex[i].y < 0 || shape.vertex[i].y >= ROWS || shape.vertex[i].x < 0 || shape.vertex[i].x >= WIDTH ||
        (board[shape.vertex[i].y] & (0x8000 >> shape.vertex[i].x))) {
      return false;
    }
  }
  return true;
}

bool move(fallingbrick_t *dest, fallingbrick_t *src, int rot, vertex_t *vector, uint16_t *board) {
  memcpy(dest, src, sizeof(fallingbrick_t));

  dest->rotation = (dest->rotation + rot + 4) % 4;
  dest->location.x += vector->x;
  dest->location.y += vector->y;

  return fits(dest, board);
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

uint8_t merge(fallingbrick_t *brick, unsigned int *board) {
  uint8_t removed = 0;
  shape_t shape;
  materialize(&shape, brick);
  for (uint8_t i = 0; i < 4; i++) {
    board[shape.vertex[i].y] |= (0x8000 >> shape.vertex[i].x);
  }

  // remove completed lines:
  int row = ROWS - 1;
  for (int i = ROWS - 1; i >= 0; i--) {
    if (board[i] < 0xffc0) {
      board[row--] = board[i];
    } else {
      removed++;
    }
  }
  for (; row >= 0; row--) {
    board[row] = 0;
  }
  return removed;
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

/*
 * Returns the speed associated with the specified number of removed lines.
 * Speed in measured in delay ms.
 */
uint16_t get_speed(uint16_t lines) {
  return (uint16_t) max((-5.6 * lines + 550) + 50, 50);
}

void pause() {
  if (was_pressed(&btn_start) || was_pressed(&btn_up) || was_pressed(&btn_y)) {
    uint8_t saved[ROWS][3];

    printf("Paused...\r\n");
    memcpy(saved, screen, sizeof(screen));
    clear_screen();

    scroll(
        "Paused              ",
        "          Paused    ",
        -1);

    memcpy(screen, saved, sizeof(screen));
    printf("Resuming...\r\n");
  }
}

void gameover(uint16_t score, uint32_t hiscore) {
  char top[]    = "YOU :             ";
  char bottom[] = "BEST:             ";
  

  _delay_ms(1000);
  clear_screen();

  itoa(hiscore, (char *)(bottom + 5), 10);
  strcpy((char *)(bottom + strlen(bottom)), "  ");

  itoa(score, (char *)(top + 5), 10);
  memset((char *)(top + strlen(top)), 0x20, sizeof(top) - strlen(top));
  top[strlen(bottom)] = 0;

  any_key();  // clear button state
  scroll(top, bottom, -1);
}

void tetris()
{
  printf("Clear screen\r\n");
  clear_screen();
  printf("Scrolling banner...\r\n");
  scroll("TETRIS      ", "", -1);
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

  draw_upcoming();
  printf("Game started...\r\n");

  uint64_t last_press = 0;
  while (true) {
    pause();

    if (was_pressed(&btn_left)) {
      if(move(&copy, &brick, 0, &left, board)) {
        memcpy(&brick, &copy, sizeof(fallingbrick_t));
        drawboard(board, &brick);
      }
      last_press = millis();
    }
    if (was_pressed(&btn_right)) {
      if(move(&copy, &brick, 0, &right, board)) {
        memcpy(&brick, &copy, sizeof(fallingbrick_t));
        drawboard(board, &brick);
      }
      last_press = millis();
    }
    if (was_pressed(&btn_b)) {
      if(move(&copy, &brick, 1, &identity, board)) {
        memcpy(&brick, &copy, sizeof(fallingbrick_t));
        drawboard(board, &brick);
      }
      last_press = millis();
    }
    if (was_pressed(&btn_x)) {
      if(move(&copy, &brick, -1, &identity, board)) {
        memcpy(&brick, &copy, sizeof(fallingbrick_t));
        drawboard(board, &brick);
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

        if (!move(&copy, &brick, 0, &down, board)) {
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
