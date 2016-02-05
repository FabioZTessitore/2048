#include <stdio.h>
#include "random.h"
#include "board.h"

int main()
{
  Board game_board;

  random_init();

  printf("Init board\n");
  board_init(&game_board);

  int freepos = board_get_freepos(&game_board)->size;
  printf("Numero di celle libere (mediante get_freepos()): %d\n", freepos);
  printf("Ci sono celle libere? %s\n", board_some_cell_empty(&game_board) ? "si" : "no");
  board_dump(&game_board);

  putchar('\n');

  printf("Adding A Tile\n");
  board_add_tile(&game_board);
  printf("Update Free Pos\n");
  board_update_freepos(&game_board);
  putchar('\n');
  freepos = board_get_freepos(&game_board)->size;
  printf("Numero di celle libere (mediante get_freepos()): %d\n", freepos);
  printf("Ci sono celle libere? %s\n", board_some_cell_empty(&game_board) ? "si" : "no");
  board_dump(&game_board);

  putchar('\n');

  board_destroy(&game_board);

  return 0;
}
