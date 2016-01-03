#include <stdio.h>
#include "board.h"

int main()
{
  Board game_board;

  printf("Init board\n");
  board_init(&game_board);
  board_dump(&game_board);
  putchar('\n');

  int freepos = board_get_freepos(&game_board)->size;
  printf("Numero di celle libere (mediante get_freepos()): %d\n", freepos);

  board_destroy(&game_board);

  return 0;
}
