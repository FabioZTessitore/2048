#ifndef BOARD_H
#define BOARD_H

/* Board
 *
 * una scacchiera di tessere
 */

#include "int_list.h"
#include "tile.h"

typedef struct board {
  Tile **cells;             /* la scacchiera vera e propria
                               e' modellata come array monodimensionale
                               di puntatori a Tile.
                               
                               La posizione (riga, colonna)
                               viene messa internamente in relazione
                               con un indice lineare.
                               
                               Ogni 'cella' punta ad una Tile se presente
                               in quella posizione oppure vale NULL.
                            */
  int size;                 /* Dimensione lineare della board */

  IntList freepos;          /* la lista delle posizioni libere sulla scacchiera */
} Board;


/* board_init:
 *
 * inizializza la scacchiera
 */
void board_init(Board*, int size);


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


/* board_some_cell_empty:
 *
 * ritorna 1 se c'e' almeno un posto
 * libero sulla scacchiera
 */
int board_some_cell_empty(Board*);


/* board_get_freepos:
 *
 * restituisce la lista delle posizioni libere
 */
IntList *board_get_freepos(Board*);


/* board_move_tile:
 *
 * sposta una Tile dalla posizione di indice cell_source
 * alla posizione di indice cell_target.
 * La cella di posizione cell_target DEVE essere vuota
 */
void board_move_tile(Board*, int cell_source, int cell_target);


/* board_add_tile:
 *
 * aggiunge una nuova Tile alla scacchiera
 * in posizione casuale tra quelle libere
 */
void board_add_tile(Board *);


/* board_rotate:
 *
 * ruota la board in senso antiorario
 */
void board_rotate(Board *);


/* board_tile_up:
 *
 * spostamento delle tile.
 * ritornano 1 se e' stato effettuato
 * almeno un movimento o una promozione
 */
int board_tile_up(Board *);

int board_tile_left(Board *);
int board_tile_right(Board *);
int board_tile_down(Board *);

#endif
