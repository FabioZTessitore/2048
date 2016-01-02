#include <stdio.h>
#include "tile.h"

int main()
{
  Tile a_tile = tile_make(2048);

  printf("Ho creato una tile con valore 2048\n");
  tile_dump(&a_tile);
  putchar('\n');

  printf("Il valore contenuto nella tile:\n");
  printf("%d\n", tile_get(&a_tile));

  return 0;
}
