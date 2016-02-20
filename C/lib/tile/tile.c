/* tile.c */

#include <stdio.h>
#include "tile.h"

Tile tile_make(int value)
{
  Tile a_tile;

  a_tile.value = value;
  a_tile.can_grow = 1;

  return a_tile;
}

int tile_get(Tile *t)
{
  return (t!=NULL) ? t->value : 0;
}

void tile_set(Tile *t, int value)
{
  t->value = value;
}

void tile_double(Tile *t)
{
  tile_set(t, tile_get(t)*2);
  t->can_grow = 0;
}

void tile_reset_can_grow(Tile *t)
{
  t->can_grow = 1;
}

int tile_can_grow(Tile *t)
{
  return t->can_grow;
}

void tile_dump(Tile *t)
{
  if (t!=NULL) {
    printf("  %4d  ", t->value);
    printf("(can grow: %d)  ", t->can_grow);
  } else {
    printf("  NULL  ");
  }
}
