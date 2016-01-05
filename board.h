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
#define SIZE 10

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


/* board_tile_dump:
 *
 * stampa per debug di una singola tile
 */
void board_tile_dump(Board *, int row, int col);


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


/* board_get_tile_value:
 *
 * restituisce il valore della Tile presente
 * alla posizione indicata.
 * Restituisce 0 se non e' presente una Tile.
 */
int board_get_tile_value(Board*, int cell_index);


/* board_add_tile:
 *
 * aggiunge una nuova Tile alla scacchiera
 * in posizione casuale tra quelle libere
 */
void board_add_tile(Board *);


/* board_update_freepos:
 *
 * aggiorna la lista delle posizioni libere
 */
void board_update_freepos(Board*);


/* board_get_freepos:
 *
 * restituisce la lista delle posizioni libere
 */
IntList* board_get_freepos(Board*);


/* board_some_cell_empty:
 *
 * ritorna 1 se c'e' almeno un posto
 * libero sulla scacchiera
 */
int board_some_cell_empty(Board*);


/* board_move_tile:
 *
 * sposta una Tile dalla posizione di indice cell_source
 * alla posizione di indice cell_target.
 * La cella di posizione cell_target DEVE essere vuota
 */
void board_move_tile(Board*, int cell_source, int cell_target);


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
