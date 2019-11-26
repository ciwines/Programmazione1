#include <iostream>
using namespace std;

/*
 * Una funzione che chiama se stessa
 * Due componenti:
 *	- una o più condizioni di terminazione
 *	- una o più chiamate ricorsive
 *
 *  => rischio di produrre sequnze infinite
 * <=> stretta relazione con i cicli
 * 
 * Non tutti i problemi possono essere risolti ricorsivamente
 * è quindi a volte necessario definire una funzione wrapper
 * con dei parametri aggiuntivi
 *
 *
 *
 *
 */	

long long fattoriale(int n) {
	long long valore = 1;

	if(n > 0) {
		valore = n * fattoriale(n - 1);
	}
	
	return valore;
}

void ricorsioneInfinita(int i) {
	cout << i << endl;
	ricorsioneInfinita(i+1);
}

long long fib(int n) {
	long long val = 1;

	if(n > 0) {
		val = fib(n - 1) + fib(n - 2);
	}

	return val;
}

/////////////////////////////////////////////////
// 		      	ESEMPIO WRAPPER 			   //
/////////////////////////////////////////////////

// funzione ricorsiva
void _stampa(int corrente, int n) {

	if(corrente <= n) {
		cout << corrente;
		_stampa(corrente + 1, n);
	}
}

// wrapper
void stampa(int n) {
	int corrente = 0;

	_stampa(0, n);

	cout << endl;
}

/////////////////////////////////////////////////
/////////////////////////////////////////////////

int main() {
	#if 0
		cout << fattoriale(4) << endl;
	#endif

	#if 0
		ricorsioneInfinita(0);
	#endif

	#if 0
		cout << fib(4) << endl;
	#endif

	#if 1
		stampa(125);
	#endif

	return 0;
}