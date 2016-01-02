#include <stdio.h>
#include "tile.h"

Tile tile_make(int value)
{
  Tile a_tile;

  a_tile.value = value;

  return a_tile;
}

int tile_get(Tile *t)
{
  return t->value;
}

void tile_dump(Tile *t)
{
  printf("~%4d~\n", t->value);
}
