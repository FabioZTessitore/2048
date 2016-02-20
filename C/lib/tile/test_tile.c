/* test_tile.c */

#include <stdio.h>
#include "tile.h"

int main()
{
  int value = 42;
  Tile a_tile;

  printf("Crea una Tile con valore %d\n", value);
  a_tile = tile_make(value);
  tile_dump(&a_tile);
  printf("\n\n");

  printf("Raddoppio il valore\n");
  tile_double(&a_tile);
  tile_dump(&a_tile);
  printf("\n\n");

  printf("Reset di can_grow\n");
  tile_reset_can_grow(&a_tile);
  tile_dump(&a_tile);
  putchar('\n');

  return 0;
}
