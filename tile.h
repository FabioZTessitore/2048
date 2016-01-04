#ifndef TILE_H
#define TILE_H

/* Tile
 *
 * le tessere del gioco 2048.
 */

typedef struct tile {
  int value;
} Tile;

/* tile_make:
 *
 * restituisce una tessera contenente il valore 'value'
 */
Tile tile_make(int value);


/* tile_get:
 *
 * restituisce il valore di una tessera
 */
int tile_get(Tile*);


/* tile_dump:
 *
 * stampa per debug
 */
void tile_dump(Tile*);

#endif
