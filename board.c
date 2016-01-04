#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "random.h"

#define BOARD_SIZE 4
#define BOARD_CELL_SIZE 8

void board_print_hborder();
void board_print_inner_blank();

int board_from_row_col_to_cell_index(int row, int col);

int *can_grow;
void grow_reset();

void grow_reset()
{
  int i;
  for (i=0; i<SIZE*SIZE; i++) {
    *(can_grow+i) = 1;
  }
}

void board_init(Board *b)
{
  int i;

  random_init();
  intlist_clear(&(b->freepos));

  can_grow = (int*)malloc(sizeof(int)*SIZE*SIZE);

  for (i=0; i<SIZE*SIZE; i++) {
    b->cells[i] = NULL;
    *(can_grow+i) = 1;
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

  free(can_grow);
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
  intlist_dump(board_get_freepos(b));
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

int board_from_row_col_to_cell_index(int row, int col)
{
  return col + row*SIZE;
}

/*
void board_tile_up(Board *b)
{
  int moved = 0;
  int i,j;
  int r;
  
  for (i=0; i<BOARD_SIZE; i++) {  
    for (j=1; j<BOARD_SIZE; j++) {
      r = j;
      if (board[r][i]!=0) {
        while (r>0 && board[r-1][i]==0) {
          board[r-1][i] = board[r][i];
          board[r][i] = 0;
          r--;
          moved = 1;
        }
        if (r>0 && board[r-1][i]==board[r][i] && grow[r-1][i]) {
          board[r-1][i] *= 2;
          board[r][i] = 0;
          grow[r-1][i] = 0;
          moved = 1;
        }
      }
    }
  }

  grow_reset();
  
  return moved;
}
*/
void board_tile_up(Board *b)
{
  int col, row;
  int r;
  int cell;
  int cell_target;
  int cell_source;
  Tile *temp;

  for (col=0; col<SIZE; col++) {  /* per tutte le colonne */
    for (row=1; row<SIZE; row++) { /* per tutte le righe tranne la piu' bassa (ultima)*/
      r = row;
      cell = board_from_row_col_to_cell_index(row, col);
      cell_source = cell;
      cell_target = board_from_row_col_to_cell_index(r-1, col);
      if (board_get(b, cell)!=NULL) {
        while (r>0 && board_get(b, cell_target)==NULL) {
          board_set(b, cell_target, board_get(b, cell_source));
          board_set(b, cell_source, NULL);
          r--;
          cell_target = board_from_row_col_to_cell_index(r-1, col);
          cell_source = board_from_row_col_to_cell_index(r, col);
        }
        /* controlla se sommare */
        cell_target = board_from_row_col_to_cell_index(r-1, col);
        cell_source = board_from_row_col_to_cell_index(r, col);
        if (r>0 &&
            board_get(b, cell_target) && board_get(b, cell_source) &&
            tile_get(board_get(b, cell_target))==tile_get(board_get(b, cell_source)) &&
            *(can_grow+cell_target)) {
          temp = (Tile*)malloc(sizeof(Tile));
          *temp = tile_make(2*tile_get(board_get(b, cell_target)));
          free(board_get(b, cell_target));
          board_set(b, cell_target, temp);
          board_set(b, cell_source, NULL);
          *(can_grow+cell_target) = 0;
        }
      }
    }
  }

  grow_reset();
}

