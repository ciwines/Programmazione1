// scrivere un programma che calcoli i primi 20 numeri della 
// successione di fibonacci

#include <iostream>
using namespace std;

int main() {

	// variabili 
	int fib1 = 0;
	int fib2 = 1;

	// loop
	for(int i = 0; i < 20; i++) {
		int fibN = fib2 + fib1;
		fib1 = fib2;
		fib2 = fibN;

		cout << "FIB [" << i + 1 << "]: " << fibN << endl;
	}

	return 0;
}