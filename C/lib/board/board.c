#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "random.h"

/******************************************************
 * Funzioni di utilita' per il modulo Board
 * ****************************************************/

/* board_destroy_tile:
 *
 * libera la memoria occupata da una Tile
 */
void board_destroy_tile(Board *b, int cell_index);

/* board_update_freepos:
 *
 * aggiorna la lista delle posizioni libere
 */
void board_update_freepos(Board*);

/* board_reset_grow:
 *
 * resetta le flag can_grow delle tessere
 */
void board_reset_grow(Board*);

/******************************************************
 * Fine funzioni di utilita' per il modulo Board
 * ****************************************************/


void board_init(Board *b, int size)
{
  int i;

  if (size<=0) {
    fprintf(stderr, "board_init: size deve essere positiva\n");
    exit(-1);
  }

  b->size = size;
  intlist_init(&(b->freepos), size*size);
  b->cells = (Tile**)malloc(sizeof(Tile*)*size*size);

  for (i=0; i<size*size; i++) {
    board_set(b, i, NULL);
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

  for (i=0; i<b->size*b->size; i++) {
    board_destroy_tile(b, i);
  }

  free(b->cells);
  intlist_destroy(&(b->freepos));
}

void board_dump(Board *b)
{
  int row, col;
  int cell_index;
  int freepos;    /* numero di celle libere */

  board_update_freepos(b);

  freepos = board_get_freepos(b)->size;
  printf("Numero di celle libere (mediante get_freepos()): %d\n", freepos);
  printf("Ci sono celle libere? %s\n", board_some_cell_empty(b) ? "si" : "no");

  cell_index = 0;
  for (row=0; row<b->size; row++) {
    for (col=0; col<b->size; col++) {
      tile_dump(board_get(b, cell_index));
      cell_index++;
    }
    putchar('\n');
  }

  intlist_dump(board_get_freepos(b));
}

void board_set(Board *b, int cell_index, Tile *t)
{
  if (b->cells[cell_index]!=NULL && t!=NULL) {
    fprintf(stderr, "board_set: tentativo di impostare una Tile su posizione non libera\n");
    exit(-1);
  }

  b->cells[cell_index] = t;
  board_update_freepos(b);
}

Tile* board_get(Board *b, int cell_index)
{
  return b->cells[cell_index];
}

void board_update_freepos(Board *b)
{
  int i;

  intlist_clear(&(b->freepos));

  for (i=0; i<b->size*b->size; i++) {
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

void board_move_tile(Board *b, int cell_src, int cell_dst)
{
  if (board_get(b, cell_dst)!=NULL) {
    fprintf(stderr, "board.c\n"
        "board_move_tile\n"
        "cella target non vuota\n");
    exit(-1);
  }

  board_set(b, cell_dst, board_get(b, cell_src));
  board_set(b, cell_src, NULL);

  board_update_freepos(b);
}

void board_add_tile(Board *b)
{
  int index_min = 0;
  int index_max = (b->freepos).size;
  int index = random_between(index_min, index_max);
  int cell_index;
  Tile *t;
  
  if (!intlist_get(&(b->freepos), index, &cell_index)) {
    fprintf(stderr, "board.c\nboard_add_tile\nindice posizione libera non valido");
    exit(-1);
  }

  t = (Tile*)malloc(sizeof(Tile));
  *t = tile_make((random_between(0, 100) < 10) ? 4 : 2);

  board_set(b, cell_index, t);
}

void board_rotate(Board *b)
{
  int row, col, cell_index;
  int qrow, qcol;
  const int size = b->size;
  Tile *q[size][size];

  cell_index = size*size-1;
  qrow = 0;
  qcol = size-1;
  for (row=size-1; row>=0; row--) {
    for (col=size-1; col>=0; col--) {
      q[qrow][qcol] = board_get(b, cell_index);
      board_set(b, cell_index, NULL);
      qrow++;
      cell_index--;
    }
    qrow = 0;
    qcol--;
  }

  cell_index = 0;
  for (row=0; row<size; row++) {
    for (col=0; col<size; col++) {
      board_set(b, cell_index, q[row][col]);
      cell_index++;
    }
  }
}

void board_reset_grow(Board *b)
{
  Tile *t;
  int cell_index;

  for (cell_index=0; cell_index<b->size*b->size; cell_index++) {
    t = board_get(b, cell_index);
    if (t) {
      tile_reset_can_grow(t);
    }
  }
}

int board_tile_up(Board *b)
{
  int col, row;
  int r;
  int cell_target;
  int cell_source;
  int moved = 0;

  for (col=0; col<b->size; col++) {
    for (row=1; row<b->size; row++) {

      r = row;

      cell_source = b->size*row + col;

      if (board_get(b, cell_source)!=NULL) {

        cell_target = b->size*(r-1) + col;

        while (r>0 && board_get(b, cell_target)==NULL) {
          board_move_tile(b, cell_source, cell_target);
          r--;
          cell_source = cell_target;
          cell_target = b->size*(r-1) + col;
          moved = 1;
        }

        if (r>0 && tile_get(board_get(b, cell_target)) &&
            tile_get(board_get(b, cell_target))==tile_get(board_get(b, cell_source)) &&
            tile_can_grow(board_get(b, cell_target)))
        {
          tile_double(board_get(b, cell_target));
          board_destroy_tile(b, cell_source);
          moved = 1;
        }
      }
    }
  }

  board_reset_grow(b);
  board_update_freepos(b);

  return moved;
}

int board_tile_left(Board *b)
{
  int moved;

  board_rotate(b);
  board_rotate(b);
  board_rotate(b);
  moved = board_tile_up(b);
  board_rotate(b);

  board_reset_grow(b);
  board_update_freepos(b);

  return moved;
}

int board_tile_right(Board *b)
{
  int moved;

  board_rotate(b);
  moved = board_tile_up(b);
  board_rotate(b);
  board_rotate(b);
  board_rotate(b);

  board_reset_grow(b);
  board_update_freepos(b);

  return moved;
}

int board_tile_down(Board *b)
{
  int moved;

  board_rotate(b);
  board_rotate(b);
  moved = board_tile_up(b);
  board_rotate(b);
  board_rotate(b);

  board_reset_grow(b);
  board_update_freepos(b);

  return moved;
}
