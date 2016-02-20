# Il modulo `Board`

Una `Board` è costituita da un vettore di puntatori a `Tile` e da una
lista di posizioni libere. Viene visualizzata come matrice quadrata di lato `size`.

## Installazione

### Download
Assicurati di aver effettuato il download della repository:
```bash
$ git clone https://github.com/FabioZTessitore/2048.git
```
### Compilazione
```bash
$ make test_board
```
## Esecuzione
```bash
$ ./test_board
```

# L'angolo dello svilupparore

L'elemento principale del modello di gioco è la `Board`.
Una `Board` viene modellata come vettore di puntatori a `Tile`.
Contiene inoltre una lista di posizioni libere di tipo `IntList`.
La `Board` viene visualizzata come come matrice quadrata di dimensione `size`.

```c
/* board.h */

typedef struct board {
  Tile **cells;
  int size;
  IntList freepos;
} Board;
```
