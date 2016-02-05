#ifndef BOARD_H
#define BOARD_H

/* Board
 *
 * la scacchiera del gioco 2048
 */

#include "int_list.h"
#include "tile.h"

/* Board e' di dimensioni SIZE x SIZE
 *
 * SIZE puo' arrivare al massimo a 10
 * a causa della massima dimensione
 * di una IntList (vedi file int_list.h)
 */
#define SIZE 4

typedef struct board {
  Tile *cells[SIZE*SIZE];   /* la scacchiera vera e propria
                               e' modellata come array monodimensionale
                               di puntatori a Tile.
                               
                               La posizione (riga, colonna)
                               viene messa internamente in relazione
                               con un indice dell'array.
                               
                               Ogni 'cella' punta ad una Tile se presente
                               in quella posizione oppure vale NULL.
                            */

  IntList freepos;          /* la lista delle posizioni libere sulla scacchiera */

  int can_grow[SIZE*SIZE];  /* flag:
                               1 se la Tile eventualmente presente
                               alla posizione corrispondente puo' essere promossa,
                               0 se e' stata gia' promossa in questo turno
                            */
} Board;


/* board_init:
 *
 * inizializza la scacchiera
 */
void board_init(Board*);


/* board_destroy:
 *
 * libera la memoria
 */
void board_destroy(Board*);


/* board_dump:
 *
 * stampa per debug
 */
void board_dump(Board*);


/* board_set:
 *
 * inserisce una Tile alla posizione indicata
 */
void board_set(Board*, int cell_index, Tile*);


/* board_get:
 *
 * restituisce la Tile dalla posizione indicata
 */
Tile *board_get(Board*, int cell_index);

/* board_add_tile:
 *
 * aggiunge una nuova Tile alla scacchiera
 * in posizione casuale tra quelle libere
 */
void board_add_tile(Board *);

/* board_tile_up:
 * board_tile_down:
 * board_tile_left:
 * board_tile_right:
 *
 * spostamento delle tile.
 * ritornano 1 se e' stato effettuato
 * almeno un movimento o una promozione
 */
int board_tile_up(Board *);
int board_tile_down(Board *);
int board_tile_left(Board *);
int board_tile_right(Board *);

#endif
