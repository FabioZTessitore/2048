#include <stdio.h>
#include "board.h"

#define BOARD_SIZE 4
#define BOARD_CELL_SIZE 8

void board_print_hborder();
void board_print_inner_blank();

void board_init(Board *b)
{
  int i;

  for (i=0; i<SIZE*SIZE; i++) {
    b->cells[i] = NULL;
  }
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
}


/*
void board_print()
{
  int i,j;
  for (i=0; i<BOARD_SIZE; i++) {
    board_print_hborder();
    board_print_inner_blank();
    for (j=0; j<BOARD_SIZE; j++) {
      printf("|%7d ", board[i][j]);
    }
    putchar('|');
    putchar('\n');
    board_print_inner_blank();
  }
  board_print_hborder();
}
*/

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
