#include <iostream>
#include "queue.h"
using namespace std;

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
 * 		succ(i) := (i + 1) % dim
 *	
 * 	due interi h, t e un array v di dim elementi di tipo t
 *	h -> indice del più vecchio elemento inserito (head)
 *	t -> indice del prossimo elemento da inserire (tail)
 * 	coda vuota => t == h
 *	coda piena => succ(t) == h
 *
 *	Tendenzialmente si allocano N + 1 elementi per evitare il problema dell'identificazione 
 *	del riempimento della cosa
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */ 

// funzioni ausiliarie
static int succ(int index, const Queue& queue) {
	return ((index + 1) % queue.size);
}

static bool empty(const Queue& queue) {
	return (queue.tail == queue.head);
}

static bool full(const Queue& queue) {
	return (succ(queue.tail, queue) == queue.head);
}

// implementazione
void init(Queue& queue) {
	queue.tail = 0;
	queue.head = 0;
	queue.size = QUEUE_DIM + 1;
	queue.members = new int[queue.size];
}

void deinit(Queue& queue) {
	delete[] queue.members;
}

retval enqueue(int value, Queue& queue) {
	retval res = OKAY;

	if(full(queue)) {
		res = FAIL;
	}
	else {
		queue.members[queue.tail] = value;
		queue.tail = succ(queue.tail, queue);
	}

	return res;
}

retval dequeue(Queue& queue) {
	retval res = OKAY;

	if(empty(queue)) {
		res = FAIL;
	}
	else {
		queue.head = succ(queue.head, queue);
	}

	return res;
}

retval first(int& value, const Queue& queue) {
	retval res = OKAY;

	if(empty(queue)) {
		res = FAIL;
	}
	else {
		value = queue.members[queue.head];
	}

	return res;
}

void print(const Queue& queue) {
	for(int i = queue.head; i != queue.tail; i = succ(i, queue)) {
		cout << queue.members[i] << "\t";
	}
	cout << endl;
}






