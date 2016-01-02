#ifndef TILE_H
#define TILE_H

struct tile {
  int value;
};

typedef struct tile Tile;

Tile tile_make(int value);
int tile_get(Tile*);
void tile_dump(Tile*);

#endif
