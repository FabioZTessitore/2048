# Il modulo `IntList`

Il modulo `IntList` mette a disposizione una lista di interi con la possibilità
di aggiungere elementi in coda, ma di leggere (non prelevare) da una posizione qualsiasi.


# L'angolo dello svilupparore

Una `IntList` è implementata come struct contenente un vettore di interi
allocato dinamcamente `values`, la dimensione allocata `capacity` e la
dimensione effettivamente utilizzata `size`.

```c
/* int_list.h */

typedef struct intlist {
  int *values;
  int capacity;
  int size;
} IntList;
```

Una `IntList` mette a disposizione le seguenti funzionalità:
- `intlist_init` (alloca la memoria)
- `intlist_destroy` (libera la memoria)
- `intlist_clear` (azzera la lista)
- `intlist_push` (aggiunge un elemento in coda)
- `intlist_get` (ritorna l'elemento scelto)
- `intlist_length` (ritorna la lunghezza attuale della lista)
- `intlist_capacity` (ritorna la dimensione allocata della IntList)
- `intlist_dump` (stampa di debug)
