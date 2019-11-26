#include <iostream>
using namespace std;

/*
 * Sequenza finita di elementi dello stesso tipo
 * La dimensione deve essere definita a priori (allocazione statica)
 * e quindi determinale a compile-time
 * Esempio:
 *	- T nome[dim] alloca sizeof(T) * dim celle consecutive di memoria
 *
 * double valori[25] -> 25 double consecutivi
 * char hello[5] = {'h', 'e', 'l', 'l', 'o'};
 * int zeri[10] = {0};
 * int esempio[] = {0, 1, 2, 3}; -> si può omettere la dimensione se si 
 * 									inizializza tramite una lista (implicita)
 *
 * Dati A e B due array, on sono possibili le seguenti operazioni:
 *	- A = B;
 *	- A++ e  A--
 *	........
 *
 * L'unica operazione definita è quella di subscripting(selezione con indice), ovvero
 * un'espressione dotata di indirizzo che ritorna il valore dell'iseimo elemento
 * 	- A[i] = exp;
 *
 *
 *
 *
 *
 *
 */

const int DIM = 130;

void esempio1() {
	double A[DIM];

	for(int i = 0; i < DIM; i++) {
		A[i] = DIM - 1 - i;
	}

	for(int i = 0; i < DIM; i++) {
		cout << "A[" << i << "]:\t" << A[i] << " ->\t" << &A[i] << endl;
	}

	/*
		FUNZIONA MA VA FUORI DAL RANGE DI LETTURA/SCRITTURA
		for(int i = 1; i <= DIM; i++) {
			cout << "A[" << i << "]:\t" << A[i] << " ->\t" << &A[i] << endl;
		}
	*/

	for(int i = 0; i < 1000; i++) {
		cout << A[DIM + i] << "\t" << i * sizeof(double) * 8 << endl;
	}

	
}

void esempio2() {
	char hello[6] = {'h', 'e', 'l', 'l', 'o', '\0'};
	cout << hello << endl; 
}

int main() {
	esempio1();
	esempio2();

	return 0;
}