/* test_board.c */

#include <stdio.h>
#include <stdlib.h>
#include "../random/random.h"
#include "board.h"

int main()
{
  Board game_board;
  Tile *t;
  int size = 3;
  int n_tessere = size+2;
  int i;

  printf("Init board\n");
  printf("Creazione di una board di lato %d\n", size);
  board_init(&game_board, size);
  board_dump(&game_board);
  putchar('\n');
 
  printf("Aggiunta di %d tessere\n"
      "con valori da %d a %d\n" , n_tessere, 1, n_tessere);
  for (i=0; i<n_tessere; i++) {
    t = (Tile*)malloc(sizeof(Tile));
    *t = tile_make(i+1);

    board_set(&game_board, i, t);
  }
  board_dump(&game_board);
  putchar('\n');
  
  printf("Riempimento della Board\n");
  for (; i<size*size; i++) {
    t = (Tile*)malloc(sizeof(Tile));
    *t = tile_make(i+1);

    board_set(&game_board, i, t);
  }
  board_dump(&game_board);
  putchar('\n');

  printf("Distruzione di Board\n");
  board_destroy(&game_board);

  printf("\n\n");
  printf("Nuova board\n");
  board_init(&game_board, size);

  printf("\nAggiunta di una tessera in posizione 3\n");
  t = (Tile*)malloc(sizeof(Tile));
  *t = tile_make(42);
  board_set(&game_board, 3, t);
  board_dump(&game_board);

  printf("\nSpostamento della tessera dalla posizione 3 alla posizione 6\n");
  board_move_tile(&game_board, 3, 6);
  board_dump(&game_board);

  printf("\nDistruzione della board\n");
  board_destroy(&game_board);

  random_init();

  printf("Init board\n");
  board_init(&game_board, size);
  putchar('\n');

  printf("Adding A Tile\n");
  board_add_tile(&game_board);
  board_dump(&game_board);

  board_destroy(&game_board);
  putchar('\n');

  printf("Rotate board\n");
  board_init(&game_board, size);
  for (i=0; i<size*size; i++) {
    t = (Tile*)malloc(sizeof(Tile));
    *t = tile_make(i+1);

    board_set(&game_board, i, t);
  }
  board_dump(&game_board);
  printf("Rotazione della board\n");
  board_rotate(&game_board);
  board_dump(&game_board);

  printf("Tile Up\n");
  board_tile_up(&game_board);
  board_dump(&game_board);

  board_destroy(&game_board);

  return 0;
}
