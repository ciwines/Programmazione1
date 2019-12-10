#include "queue.h"

/* 
 * 	Una coda è una collezione di dati omogenei in cui gli elementi sono gestiti in modo
 * 	FIFO (First In First Out)
 *
 * 	Sono definite le seguenti funzioni:
 * 		-> init() e deinit(: inizializza/deinizializza la coda
 *		-> enqueue(T): inserisce elemento sulla coda; fallisce se piena
 * 		-> dequeue(): estrae il primo elemento inserito (senza visualizzarlo); fallisce se vuota
 * 		-> first(T&): ritorna il primo elemento inserito (senza estrarlo); fallisce se vuota
 *
 *	NB: enqueue(T), dequeue() e first(T&) devono essere O(1) !
 */

// IMPLEMENTAZIONE MEDIANTE ARRAY
/* 	
 *	idea di buffer circolare:
 * 		succ(i) = (i + 1) % dim
 *	
 * 	due interi h, t e un array v di dim elementi di tipo t
 *	h -> indice del più vecchio elemento inserito (head)
 *	t -> indice del prossimo elemento da inserire (tail)
 * 	coda vuota => t == h
 *	coda piena => succ(t) == h
 */ 