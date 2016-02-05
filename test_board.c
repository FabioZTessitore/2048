#include <stdio.h>
#include <stdlib.h>
#include "random.h"
#include "board.h"

int main()
{
  Board game_board;
  Tile *t;
  int i;

  printf("Init board\n");
  board_init(&game_board, 6);
  board_dump(&game_board);
  putchar('\n');
 
  printf("Adding Tiles\n");
  for (i=0; i<10; i++) {
    t = (Tile*)malloc(sizeof(Tile));
    *t = tile_make(i+1);

    board_set(&game_board, i, t);
  }
  board_dump(&game_board);
  
  printf("Fill\n");
  for (; i<36; i++) {
    t = (Tile*)malloc(sizeof(Tile));
    *t = tile_make(i+1);

    board_set(&game_board, i, t);
  }
  board_dump(&game_board);

  board_destroy(&game_board);

  printf("\n\n\n\n");
  printf("Nuova board\n");
  board_init(&game_board, 4);
  t = (Tile*)malloc(sizeof(Tile));
  *t = tile_make(42);
  board_set(&game_board, 3, t);
  board_dump(&game_board);
  board_move_tile(&game_board, 3, 6);
  board_dump(&game_board);

  board_destroy(&game_board);

  random_init();

  printf("Init board\n");
  board_init(&game_board, 6);

  board_dump(&game_board);
  putchar('\n');

  printf("Adding A Tile\n");
  board_add_tile(&game_board);
  board_dump(&game_board);

  board_destroy(&game_board);

  putchar('\n');

  printf("Rotate board\n");
  board_init(&game_board, 4);
  for (i=0; i<10; i++) {
    t = (Tile*)malloc(sizeof(Tile));
    *t = tile_make(i+1);

    board_set(&game_board, i, t);
  }
  board_dump(&game_board);
  board_rotate(&game_board);
  board_dump(&game_board);

  board_tile_up(&game_board);
  board_dump(&game_board);

  board_destroy(&game_board);

  return 0;
}
