/* tile.h */

#ifndef TILE_H
#define TILE_H

/* Tile
 *
 * tessere di gioco.
 */

typedef struct tile {
  int value;
  int can_grow;             /* flag che avvisa se la tessera puo'
                               crescere oppure no */
} Tile;

/* tile_make:
 *
 * restituisce una tessera contenente il valore 'value'
 * e proprieta' can_grow pari a 1 (puo' crescere)
 */
Tile tile_make(int value);


/* tile_get:
 *
 * restituisce il valore di una tessera
 */
int tile_get(Tile*);


/* tile_set:
 *
 * imposta il valore di una tessera
 */
void tile_set(Tile*, int value);


/* tile_double:
 *
 * raddoppia il valore della tessera
 * e imposta can_grow a 0
 */
void tile_double(Tile*);


/* tile_reset_can_grow:
 *
 * resetta a 1 la proprieta' can_grow
 */
void tile_reset_can_grow(Tile*);


/* tile_can_grow:
 *
 * restituisce la flag can_grow
 */
int tile_can_grow(Tile*);


/* tile_dump:
 *
 * stampa per debug
 */
void tile_dump(Tile*);

#endif
