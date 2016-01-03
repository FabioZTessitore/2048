#include <stdio.h>
#include "board.h"

int main()
{
  Board game_board;

  printf("Init board\n");
  board_init(&game_board);
  board_dump(&game_board);
  putchar('\n');

  board_destroy(&game_board);

  return 0;
}
