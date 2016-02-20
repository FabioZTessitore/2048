# Il modulo `Tile`

Il modulo `Tile` definisce una tessera del gioco 2048.

Una `Tile` è costituita soltanto dal suo valore e da una flag
che specifica se la tessera può crescere di valore
(se non lo ha già fatto durante il turno corrente).

## Installazione

### Download
Assicurati di aver effettuato il download della repository:
```bash
$ git clone https://github.com/FabioZTessitore/2048.git
```
### Compilazione
```bash
$ make test_tile
```
## Esecuzione
```bash
$ ./test_tile
```

# L'angolo dello svilupparore

## Modulo `Tile`

Una `Tile` è implementata come struct composta da un valore intero e da una flag
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
