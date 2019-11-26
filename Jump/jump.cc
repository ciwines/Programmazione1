/*
	NON USARE MAI QUESTE ISTRUZIONI
		- break: termina l'esecuzione di un ciclo

		while(...) {
			...
			break
			...
		}

		- return: termina l'esecuzione di una funzione e 
				  ritorna un valore

		int foo(...) {
			while (...) {
				...
				return qualcosa;
				....
			}
		}

		- continue: termina una singola istanza del ciclo
		for(...) {
			...
			continue;
			....
		}

		- goto: salto incondizionato (in asm, jmp)
*/

#include <iostream>
using namespace std;


void esempio1Brutto() {
	// NON FARE MAI COSI
	while(1) {
		int a, b;
		char c;
		cout << "Inserisci due numeri: ";
		cin >> a >> b;
		cout << "somma: " << a+b << endl << "Vuoi continuare? [s/n] ";
		cin >> c;

		if (c == 'n') {
			break;
		}
	}
}

void esempio1Bello() {
	int a, b;
	char c;

	do {
		cout << "Inserisci due numeri: ";
		cin >> a >> b;

		cout << "somma: " << a+b << endl << "Vuoi continuare? [s/n] ";
		cin >> c;
	}
	while (c == 's');
}

int main() {

	// esempio 1
	#if 1
		esempio1Bello();
	#endif

	return 0;
}