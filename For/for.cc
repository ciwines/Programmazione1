/*
	sintassi for
	for (init; expr; agg) istr
		- init: istruzione di inizializzione
	 	- expr: espressione booleana = CONDIZIONE DI PERMANENZA
	 	- agg: istruzione di aggiornamento della variabile di controllo
	 	- istr: istruzione complessa
	esempio: for (int i = 0; i < 10; i++) cout << i << endl;
		LOOP INVARIANT = proprietà di alcune variabili dipendenti dal ciclo
		https://en.wikipedia.org/wiki/Loop_invariant

		Si prova per induzione:
			suppongo P la proprietà che voglio verificare; definisco cosi P_i che:
				(1) P_0 sia vera immediatamente prima che inizi il ciclo
				(2) P_i-1 vera alla fine dell'(i-1)esimo ciclo => P_i vera alla fine dell'i-esimo ciclo
				(3) alla fine dell'ultimo ciclo, P_n (e la negazione della condizione di permanenza) => P
		
		ESEMPIO 1: (fattoriale)
			int i = 1;
			int fact = 1;		-> P(0) = 1 = 0!; (1) è verificata

			while (i <= n) {
				fact *= i;		-> P_i-1 => P_i ; (2) è verificata
				i++;
			}
								-> P_n = P ; (3) è verificata

		ESEMPIO 2: (divisibilità per 2)

		P = dopo il ciclo, tmp % 2 != 0 e tmp * (2^ndiv) == num
		Invariante P_i = tmp * (2^ndiv) == num

		(1) P(0) = tmp * (2^0) == num vera
		(2) tmp è divisibile per 2 poichè diventa tmp/2 * (2^(ndiv + 1)) == tmp * (2^ndiv)
		(3) alla fine dell'n-esimo ciclo, P_n (e la negazione della condizione del ciclo) => P

		ndiv = 0; tmp = num;
		while (tmp % 2 == 0) {
			tmp /= 2;
			ndiv++;
		}
*/

#include <iostream>
using namespace std;

void esempio1() { 
	for (int i = 0; i < 10; i++) {
		cout << i << endl;
	}
}

long long esempio2(int n) {
	if (n < 0) {
		return -1;
	}

	long long fact = 1;

	for (int i = 2; i <= n; i++) {
		fact *= i;
	}

	return fact;
}

void esempio3(int limit) {
	// fibonacci
	for (int a = 0, b = 1, i = 1; 
		i <= limit; 
		b += a, a = b - a, i++) {
		cout << "Iterazione " << i << "\t-> " << b << endl;
	}
}

int main() {
	// esempio 1
	#if 0
		esempio1();
	#endif

	// esempio 2
	#if 0
		int n = 10;
		cout << n << "! = " << esempio2(n) << endl;
	#endif

	// esempio 3
	#if 1
		int n = 20;
		esempio3(n);
	#endif

	return 0;
}