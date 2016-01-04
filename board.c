#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "random.h"

#define BOARD_SIZE 4
#define BOARD_CELL_SIZE 8

void board_print_hborder();
void board_print_inner_blank();

void board_init(Board *b)
{
  int i;

  intlist_clear(&(b->freepos));

  for (i=0; i<SIZE*SIZE; i++) {
    b->cells[i] = NULL;
    intlist_push(&(b->freepos), i);
  }
}

void board_destroy(Board *b)
{
  int i;

  for (i=0; i<SIZE*SIZE; i++) {
    if (b->cells[i] != NULL) {
      free(b->cells[i]);
      b->cells[i] = NULL;
    }
  }
}

IntList* board_get_freepos(Board *b)
{
  int i;

  intlist_clear(&(b->freepos));

  for (i=0; i<SIZE*SIZE; i++) {
    if (b->cells[i] == NULL) {
      intlist_push(&(b->freepos), i);
    }
  }

  return &(b->freepos);
}

int board_some_cell_empty(Board *b)
{
  return ( (b->freepos).size>0 );
}

Tile *board_get(Board *b, int cell_index)
{
  return b->cells[cell_index];
}

void board_set(Board *b, int cell_index, Tile *t)
{
  b->cells[cell_index] = t;
}

void board_add_tile(Board *b)
{
  int min = 0;
  int max = (b->freepos).size;
  int cell = intlist_get(&(b->freepos), random_between(min, max));
  Tile *t = (Tile*)malloc(sizeof(Tile));
  t->value = 2;

  board_set(b, cell, t);
}

void board_dump(Board *b)
{
  int i, j;

  for (i=0; i<BOARD_SIZE; i++) {
    board_print_hborder();
    board_print_inner_blank();
    
    for (j=0; j<BOARD_SIZE; j++) {
      putchar('|');
      tile_dump(b->cells[j+i*SIZE]);
    }

    printf("|\n");
    board_print_inner_blank();
  }
  board_print_hborder();
  putchar('\n');
  intlist_dump(&(b->freepos));
}

void board_print_hborder()
{
  int i, j;
  for (j=0; j<BOARD_SIZE; j++) {
    putchar('+');
    for (i=0; i<BOARD_CELL_SIZE; i++) putchar('-');
  }
  putchar('+');
  putchar('\n');
}

void board_print_inner_blank()
{
  int i, j;
  for (j=0; j<BOARD_SIZE; j++) {
    putchar('|');
    for (i=0; i<BOARD_CELL_SIZE; i++) putchar(' ');
  }
  putchar('|');
  putchar('\n');
}
