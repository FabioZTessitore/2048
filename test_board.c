#include <stdio.h>
#include "random.h"
#include "board.h"

int main()
{
  Board game_board;

  random_init();

  printf("Init board\n");
  board_init(&game_board);

  board_dump(&game_board);
  putchar('\n');

  printf("Adding A Tile\n");
  board_add_tile(&game_board);
  board_dump(&game_board);

  putchar('\n');

  board_destroy(&game_board);

  return 0;
}
