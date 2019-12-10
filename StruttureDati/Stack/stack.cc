#include <iostream>
#include "stack.h"
using namespace std;

/*
 *	La pila(stack) è una collezione di dati omogenei i cui elementi sono gestiti in modo LIFO(last in first out)	
 *	Viene visualizzato/estratto l'ultimo elemento inserito
 *
 *	Vengono tipicamente definite le seguenti funzioni:	
 *		- init() e deinit() -> inizializza e deinizializza la pila
 *		- push(T) -> inserisce un elemento nello stack; fallisce se pieno
 *		- pop() -> estrae l'ultimo elemento inserito(senza visualizzarlo); fallisce se vuota
 *		- top(T&) -> ritorna l'ultimo inserito(senza estrarlo); fallisce se vuota
 *
 *	NB: 
 * 		- a volte pop() e top(T&) vengono fuse insieme in pop(T&)
 *		- a volte è disponibile una funzione print()
 *		- deinit() non è sempre presente
 *
 *	NNB: le operazioni push(T), pop() e top(T&) devono essere O(1) !
 */

// IMPLEMENTAZIONE MEDIANTE ARRAY
/* 
 *	Dati: un intero h e un array v di dim elementi di tipi T
 *		-> v allocato staticamente o dinamicamente
 * 		-> dim numero massimo di elementi
 *		-> h indice del prossimo elemento da inserire
 *			-> pila vuota => h == 0
 *			-> pila piena => h == dim
 *
 *	init():	
 *		-> pone h = 0 e alloca v se dinamica
 *	push(T):
 *		-> inserisce T in v[h] e incrementa h
 *	pop():
 *		-> decrementa h(non lo cancella, sarebbe inutile in quanto decrementando h l'elemento in h+1 
 			non sarà mai più disponibile)
 *	top(T&):
 *		-> restituisce v[h-1]
 *	deinit():
 *		-> dealloca v se allocata dinamicamente
 *
 *
 */

// funzioni ausiliarie
static bool _empty(const Stack& s) {
	return (s.index == 0);
}

static bool _full(const Stack& s) {
	return (s.index == STACK_DIM);
}

// funzioni dello stack
void init(Stack& stack) {
	stack.index = 0;
	stack.members = new int[STACK_DIM];
}

void deinit(Stack& stack) {
	delete[] stack.members;
}

retval push(int value, Stack& stack) {
	retval res = OKAY;

	if(_full(stack)) {
		res = FAIL;
	}
	else {
		stack.members[stack.index] = value;
		stack.index++;
	}

	return res;
}

retval top(int& value, const Stack& stack) {
	retval res = OKAY;

	if(_empty(stack)) {
		res = FAIL;
	}
	else {
		value = stack.members[stack.index - 1];
	}

	return res;
}

retval pop(Stack& stack) {
	retval res = OKAY;

	if(_empty(stack)) {
		res = FAIL;
	}
	else {
		stack.index--;
	}

	return res;
}

void print(const Stack& stack) {
	for(int i = 0; i < stack.index; i++) {
		cout << "Stack[" << i << "] = " << stack.members[i] << endl;
	}
}






