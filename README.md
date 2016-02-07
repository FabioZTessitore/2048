# 2048

Il gioco 2048 in tre versioni: console, ncurses, gtk.

## Installazione

### Download
```bash
$ git clone https://github.com/FabioZTessitore/2048.git
```

### Compilazione

#### Compilazione della versione console
```bash
$ make 2048_console
```

#### Compilazione della versione ncurses
Assicurarsi di avere le librerie ncurses
```bash
$ sudo apt-get update
$ sudo apt-get install libncurses5-dev
```
```bash
$ make 2048_ncurses
```

#### Compilazione della versione gtk
Assicurarsi di avere le librerie gtk
```bash
$ sudo apt-get update
$ sudo apt-get install libgtk-3-dev
```
```bash
$ make 2048_gtk
```

## Esecuzione
```bash
$ ./2048
```

# L'angolo dello svilupparore

L'elemento principale del modello di gioco è la `Board`. Una `Board` viene modellata come
vettore di puntatori a `Tile`.

## Modulo `Tile`

Una `Tile` è costituita soltanto dal suo valore e da una flag
che specifica se la tessera può crescere di valore (se non lo ha già fatto
durante il turno corrente).
```c
/* tile.h */

typedef struct tile {
  int value;
  int can_grow;
} Tile;
```

Le funzionalità messe a disposizione sono:
- `tile_make` (crea una Tile)
- `tile_set` (imposta il valore della Tile)
- `tile_get` (restituisce il valore della Tile)
- `tile_double` (raddoppia il valore della Tile)
- `tile_reset_can_grow` (resetta la flag can_grow)
- `tile_can_grow` (restituisce la flag can_grow)
- `tile_dump` (stampa di debug)

## Modulo `Board`

Una `Board` è costituita da un vettore di puntatori a `Tile` (visualizzata
come matrice quadrata di lato `size`) e da una lista di posizioni libere.
```c
/* board.h */

typedef struct board {
  Tile **cells;
  int size;
  IntList freepos;
} Board;
```
Appena viene creata una nuova `Board` le `cells` vengono impostate a `NULL`
e tutte le posizioni vengono inserite nella lista delle posizioni libere.

## Moduli ausiliari

### Modulo `random`

Per l'implementazione del gioco è necessario più volte
estrarre numeri pseudocasuali. In particolare quando si
genera una nuova `Tile` bisogna estrarre la posizione
tra quelle disponibili e il valore da assegnarle.

Il modulo `random` si occupa di inizializzare il generatore di numeri
pseudocasuali:
```c
/* random.h */

void random_init();
```

e di generare numeri compresi nell'intervallo [min, max[
```c
/* random.h */

int random_between(int min, int max);
```

### Modulo `IntList`

Il modulo `IntList` mette a disposizione una lista di interi
da utilizzare per la gestione delle caselle libere della `Board`.

Una `IntList` è l'insieme di un vettore di interi (allocato dinamicamente
quando la lista viene creata), la dimensione allocata (`capacity`)
e la dimensione attuale (`size`).
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
