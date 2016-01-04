#ifndef RANDOM_H
#define RANDOM_H

/* random
 *
 * wrapper attorno alle funzioni
 * per la generazione di numeri pseudo-casuali
 */


/* random_init:
 *
 * inizializza il sistema di generazione
 * dei numeri pseudo-casuali
 */
void random_init();


/* random_between:
 *
 * genera e restituisce un numero
 * compreso tra min incluso e max escluso
 */
int random_between(int min, int max);

#endif
