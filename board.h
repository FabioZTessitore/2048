#ifndef BOARD_H
#define BOARD_H

#include "tile.h"

#define SIZE 4

struct board {
  Tile *cells[SIZE*SIZE];
};

typedef struct board Board;

void board_init(Board*);
void board_dump(Board*);

#endif
