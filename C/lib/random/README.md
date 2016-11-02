# Il modulo `random`

Il modulo `random` si occupa della generazione di numeri pseudocasuali.


## L'angolo dello sviluppatore

### random_init()

Prima di utilizzare l'unica funzione messa a disposizione dal modulo
`random` bisogna inizializzare il generatore di numeri
pseudocasuali mediante `random_init()`.
```c
/* random.h */

/* random_init:
 *
 * inizializza il sistema di generazione
 * dei numeri pseudo-casuali
 */
void random_init();
```

### random_between()

Per generare numeri compresi nell'intervallo [min, max[ il
modulo mette a disposizione `random_between()`:
```c
/* random.h */

/* random_between:
 *
 * genera e restituisce un numero
 * compreso tra min incluso e max escluso
 */
int random_between(int min, int max);
```
