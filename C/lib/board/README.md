# Il modulo `Board`

Il modulo `Board` definisce la scacchiera del gioco 2048.


# L'angolo dello svilupparore

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
