#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "random.h"

/* board_coords_to_index:
 *
 * converte una coppia di coordinate (row, col)
 * in un indice lineare.
 */
int board_coords_to_index(int row, int col);

/* board_grow_reset:
 *
 * ripristina flag di promozione Tile
 */
void board_grow_reset(Board *b);

/* board_destroy_tile:
 *
 * libera la memoria occupata da una Tile
 */
void board_destroy_tile(Board *b, int cell_index);

/* board_tile_dump:
 *
 * stampa per debug di una singola tile
 */
void board_tile_dump(Board *, int row, int col);

/* board_get_tile_value:
 *
 * restituisce il valore della Tile presente
 * alla posizione indicata.
 * Restituisce 0 se non e' presente una Tile.
 */
int board_get_tile_value(Board*, int cell_index);

/* board_update_freepos:
 *
 * aggiorna la lista delle posizioni libere
 */
void board_update_freepos(Board*);

/* board_get_freepos:
 *
 * restituisce la lista delle posizioni libere
 */
IntList* board_get_freepos(Board*);


/* board_some_cell_empty:
 *
 * ritorna 1 se c'e' almeno un posto
 * libero sulla scacchiera
 */
int board_some_cell_empty(Board*);

/* board_move_tile:
 *
 * sposta una Tile dalla posizione di indice cell_source
 * alla posizione di indice cell_target.
 * La cella di posizione cell_target DEVE essere vuota
 */
void board_move_tile(Board*, int cell_source, int cell_target);




void board_init(Board *b)
{
  int i;

  random_init();
  intlist_clear(&(b->freepos));

  for (i=0; i<SIZE*SIZE; i++) {
    board_set(b, i, NULL);
    b->can_grow[i] = 1;
    intlist_push(&(b->freepos), i);
  }
}

void board_destroy_tile(Board *b, int cell_index)
{
  Tile *t = board_get(b, cell_index);
  
  if (t != NULL) {
      free(t);
      t = NULL;
      board_set(b, cell_index, NULL);
    }
}

void board_destroy(Board *b)
{
  int i;

  for (i=0; i<SIZE*SIZE; i++) {
    board_destroy_tile(b, i);
  }
}

void board_tile_dump(Board *b, int row, int col)
{
  int cell_index;
  
  cell_index = board_coords_to_index(row, col);
  tile_dump(board_get(b, cell_index));
}

void board_dump(Board *b)
{
  int row, col;

  board_update_freepos(b);

  int freepos = board_get_freepos(b)->size;
  printf("Numero di celle libere (mediante get_freepos()): %d\n", freepos);
  printf("Ci sono celle libere? %s\n", board_some_cell_empty(b) ? "si" : "no");

  for (row=0; row<SIZE; row++) {
    for (col=0; col<SIZE; col++) {
      board_tile_dump(b, row, col);
    }
    putchar('\n');
  }
  putchar('\n');

  intlist_dump(board_get_freepos(b));
}

void board_set(Board *b, int cell_index, Tile *t)
{
  b->cells[cell_index] = t;
}

Tile* board_get(Board *b, int cell_index)
{
  return b->cells[cell_index];
}

int board_get_tile_value(Board *b, int cell_index)
{
  Tile *t = board_get(b, cell_index);
  
  if (t==NULL) {
    return 0;
  }

  return tile_get(t);
}

void board_add_tile(Board *b)
{
  int cell_min = 0;
  int cell_max = (b->freepos).size;
  int i = random_between(cell_min, cell_max);
  int cell;
  
  if (!intlist_get(&(b->freepos), i, &cell)) {
    fprintf(stderr, "board.c\nboard_add_tile\nindice di cella non valido");
    exit(-1);
  }

  Tile *t = (Tile*)malloc(sizeof(Tile));
  *t = tile_make((random_between(0, 100) < 10) ? 4 : 2);

  board_set(b, cell, t);
}

void board_update_freepos(Board *b)
{
  int i;

  intlist_clear(&(b->freepos));

  for (i=0; i<SIZE*SIZE; i++) {
    if (board_get(b, i)==NULL) {
      intlist_push(&(b->freepos), i);
    }
  }
}

IntList* board_get_freepos(Board *b)
{
  return &(b->freepos);
}

int board_some_cell_empty(Board *b)
{
  return ( intlist_length(board_get_freepos(b)) > 0 );
}

void board_move_tile(Board *b, int cell_source, int cell_target)
{
  board_set(b, cell_target, board_get(b, cell_source));
  board_set(b, cell_source, NULL);
}

int board_tile_up(Board *b)
{
  int col, row;
  int r;
  int cell_target;
  int cell_source;
  Tile *temp;
  int moved = 0;

  for (col=0; col<SIZE; col++) {
    for (row=1; row<SIZE; row++) {

      r = row;

      cell_source = board_coords_to_index(row, col);

      if (board_get(b, cell_source)!=NULL) {

        cell_target = board_coords_to_index(r-1, col);

        while (r>0 && board_get(b, cell_target)==NULL) {
          board_move_tile(b, cell_source, cell_target);
          r--;
          cell_source = cell_target;
          cell_target = board_coords_to_index(r-1, col);
          moved = 1;
        }

        if (r>0 && board_get_tile_value(b, cell_target) &&
            board_get_tile_value(b, cell_target)==board_get_tile_value(b, cell_source) &&
            b->can_grow[cell_target])
        {
          temp = (Tile*)malloc(sizeof(Tile));
          *temp = tile_make(2*board_get_tile_value(b, cell_target));
          free(board_get(b, cell_target));
          board_set(b, cell_target, temp);
          board_set(b, cell_source, NULL);
          b->can_grow[cell_target] = 0;
          moved = 1;
        }
      }
    }
  }

  board_grow_reset(b);
  board_update_freepos(b);

  return moved;
}

int board_tile_down(Board *b)
{
  int col, row;
  int r;
  int cell_source;
  int cell_target;
  Tile *temp;
  int moved = 0;
  
  for (col=0; col<SIZE; col++) {
    for (row=SIZE-2; row>=0; row--) {

      r = row;

      cell_source = board_coords_to_index(row, col);

      if (board_get(b, cell_source)!=NULL) {

      cell_target = board_coords_to_index(row+1, col);

        while (r<SIZE-1 && board_get(b, cell_target)==NULL) {
          board_move_tile(b, cell_source, cell_target);
          r++;
          cell_source = cell_target;
          cell_target = board_coords_to_index(r+1, col);
          moved = 1;
        }

        if (r<SIZE-1 && board_get_tile_value(b, cell_target) &&
            board_get_tile_value(b, cell_target)==board_get_tile_value(b, cell_source) &&
            b->can_grow[cell_target])
        {
          temp = (Tile*)malloc(sizeof(Tile));
          *temp = tile_make(2*tile_get(board_get(b, cell_target)));
          free(board_get(b, cell_target));
          board_set(b, cell_target, temp);
          board_set(b, cell_source, NULL);
          b->can_grow[cell_target] = 0;
          moved = 1;
        }
      }
    }
  }

  board_grow_reset(b);
  board_update_freepos(b);

  return moved;
}

int board_tile_left(Board *b)
{
  int cell_source;
  int cell_target;
  int row, col;
  int c;
  Tile *temp;
  int moved = 0;
  
  for (row=0; row<SIZE; row++) {
    for (col=1; col<SIZE; col++) {

      c = col;

      cell_source = board_coords_to_index(row, col);

      if (board_get(b, cell_source)!=NULL) {

        cell_target = board_coords_to_index(row, col-1);

        while (c>0 && board_get(b, cell_target)==NULL) {
          board_move_tile(b, cell_source, cell_target);
          c--;
          cell_source = cell_target;
          cell_target = board_coords_to_index(row, c-1);
          moved = 1;
        }

        if (c>0 && board_get_tile_value(b, cell_target) &&
            board_get_tile_value(b, cell_target)==board_get_tile_value(b, cell_source) &&
            b->can_grow[cell_target])
        {
          temp = (Tile*)malloc(sizeof(Tile));
          *temp = tile_make(2*tile_get(board_get(b, cell_target)));
          free(board_get(b, cell_target));
          board_set(b, cell_target, temp);
          board_set(b, cell_source, NULL);
          b->can_grow[cell_target] = 0;
          moved = 1;
        }
      }
    }
  }

  board_grow_reset(b);
  board_update_freepos(b);

  return moved;
}

int board_tile_right(Board *b)
{
  int cell_target;
  int cell_source;
  int row, col;
  int c;
  Tile *temp;
  int moved = 0;
  
  for (row=0; row<SIZE; row++) {
    for (col=SIZE-2; col>=0; col--) {

      c = col;

      cell_source = board_coords_to_index(row, col);

      if (board_get(b, cell_source)!=NULL) {

        cell_target = board_coords_to_index(row, col+1);

        while (c<SIZE-1 && board_get(b, cell_target)==NULL) {
          board_move_tile(b, cell_source, cell_target);
          c++;
          cell_source = cell_target;
          cell_target = board_coords_to_index(row, c+1);
          moved = 1;
        }

        if (c<SIZE-1 && board_get_tile_value(b, cell_target) &&
            board_get_tile_value(b, cell_target)==board_get_tile_value(b, cell_source) &&
            b->can_grow[cell_target])
        {
          temp = (Tile*)malloc(sizeof(Tile));
          *temp = tile_make(2*tile_get(board_get(b, cell_target)));
          free(board_get(b, cell_target));
          board_set(b, cell_target, temp);
          board_set(b, cell_source, NULL);
          b->can_grow[cell_target] = 0;
          moved = 1;
        }
      }
    }
  }

  board_grow_reset(b);
  board_update_freepos(b);

  return moved;
}

int board_coords_to_index(int row, int col)
{
  return col + row*SIZE;
}

void board_grow_reset(Board *b)
{
  int i;
  for (i=0; i<SIZE*SIZE; i++) {
    b->can_grow[i] = 1;
  }
}
