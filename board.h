#ifndef BOARD_H
#define BOARD_H

#include "tile.h"
#include "int_list.h"

#define SIZE 4

struct board {
  Tile *cells[SIZE*SIZE];
  IntList freepos;
};

typedef struct board Board;

void board_init(Board*);
void board_dump(Board*);
void board_destroy(Board*);
IntList* board_get_freepos(Board*);
int board_some_cell_empty(Board*);
Tile *board_get(Board*, int cell_index);
void board_set(Board*, int cell_index, Tile*);
void board_add_tile(Board *);
void board_tile_up(Board *);
void board_tile_down(Board *);
void board_tile_left(Board *);
void board_tile_right(Board *);

#endif
