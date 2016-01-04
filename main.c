#include <stdio.h>
#include "board.h"

#define UP 1

void clear_screen() {
  int i = 25;
  for (; i>0; i--) {
    putchar('\n');
  }
}

int main()
{
  Board game_board;
  int direction;

  printf("2048 ... il gioco!\n\n\n");

  board_init(&game_board);
  
  board_add_tile(&game_board);

  do {
    board_add_tile(&game_board);
    board_dump(&game_board);
    direction = getchar();
    direction = UP;

    switch(direction) {
      case UP:
        board_tile_up(&game_board);
        break;
    };
    clear_screen();
  } while(board_get_freepos(&game_board) && board_some_cell_empty(&game_board));
  
  board_destroy(&game_board);

  return 0;
}
