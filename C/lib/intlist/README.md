# Il modulo `IntList`

Una `IntList` è l'insieme composto da un vettore di interi (allocato dinamicamente
quando la lista viene creata), la dimensione allocata (`capacity`)
e la dimensione attuale (`size`).

Permette l'inserimento in coda di valori interi e il recupero da posizione qualsiasi.

## Installazione

### Download
Assicurati di aver effettuato il download della repository:
```bash
$ git clone https://github.com/FabioZTessitore/2048.git
```
### Compilazione
```bash
$ make test_int_list
```
## Esecuzione
```bash
$ ./test_int_list
```

# L'angolo dello svilupparore

Una `IntList` è implementata come struct contenente un vettore di interi
(allocato dinamcamente) `values`, la dimensione allocata `capacity` e la
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
