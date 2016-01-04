#include <stdio.h>
#include "board.h"

int main()
{
  Board game_board;

  printf("2048 ... il gioco!\n\n\n");

  board_init(&game_board);
  
  board_add_tile(&game_board);
  board_add_tile(&game_board);

  board_dump(&game_board);
  
  board_destroy(&game_board);

  return 0;
}
