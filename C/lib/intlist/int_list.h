/* int_list.h */

#ifndef INTLIST_H
#define INTLIST_H

/* IntList
 *
 * Una lista di interi
 *
 * I valori possono essere inseriti in coda
 * e letti in qualsiasi ordine.
 */

typedef struct intlist {
  int *values;
  int capacity;
  int size;
} IntList;


/* intlist_init:
 *
 * inizializza la IntList creando un vettore di
 * interi di lunghezza pari a capacity e
 * azzera size
 */
void intlist_init(IntList *il, int capacity);


/* intlist_destroy:
 *
 * rilascia la memoria allocata
 * per il vettore di interi values
 */
void intlist_destroy(IntList *il);


/* intlist_clear:
 *
 * inizializza la IntList azzerando size,
 * (non cancella realmente gli elementi della lista)
 */
void intlist_clear(IntList *il);


/* intlist_push:
 *
 * aggiunge value in coda alla IntList
 * e ritorna la nuova dimensione size.
 * Se non e' possibile inserire l'elemento
 * perche' la lista e' piena ritorna -1
 */
int intlist_push(IntList *il, int value);


/* intlist_get:
 *
 * restituisce il valore dell'elemento di indice index
 * attraverso value. Ritorna 1 se l'operazione va a buon fine.
 * Ritorna 0 e azzera value se l'indice non e' valido
 */
int intlist_get(IntList *il, int index, int *value);


/* intlist_length:
 *
 * restituisce la lunghezza attuale della IntList,
 * (ritorna size, non ricalcola)
 */
int intlist_length(IntList *il);


/* intlist_capacity:
 *
 * restituisce la dimensione allocata della IntList
 */
int intlist_capacity(IntList *il);


/* intlist_dump:
 *
 * stampa per debug
 */
void intlist_dump(IntList *il);

#endif
