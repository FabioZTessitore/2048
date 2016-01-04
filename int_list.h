#ifndef INTLIST_H
#define INTLIST_H

#define MAX_SIZE 100

/* IntList
 *
 * Una lista di interi
 *
 * I valori possono essere inseriti in coda
 * e letti in qualsiasi ordine.
 *
 * Utilizzata per l'estrazione casuale di un elemento
 * tra quelli in lista.
 */

typedef struct intlist {
  int values[MAX_SIZE];
  int size;
} IntList;


/* intlist_clear:
 *
 * inizializza la IntList 'il' azzerando size,
 * (non cancella gli elementi della lista)
 */
void intlist_clear(IntList *il);


/* intlist_push:
 *
 * aggiunge value in coda alla IntList 'il'
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
 * restituisce la lunghezza della IntList,
 * (ritorna size, non ricalcola)
 */
int intlist_length(IntList *il);


/* intlist_dump:
 *
 * stampa per debug
 */
void intlist_dump(IntList *il);

#endif
