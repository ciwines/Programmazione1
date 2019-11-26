#include <iostream>
using namespace std;

/*
 * Gli array vengono spesso usati con le funzioni ricorsive
 * è sempre conveniente biforcare l'array!
 * 
 *
 *
 *
 */

// esempio di biforcazione con ricorsione
int somma(int array[], int min, int max) {
	int risultato = 0;

	if(min > max) {
		risultato = 0;
	}
	else if (min == max) {
		risultato = array[min];
	}
	else {
		int index = (min + max) / 2;

		// faccio due chiamate ricorsive passando "metà array" come parametro
		risultato = somma(array, min, index) + somma(array, index + 1, max);
	}

	return risultato;
}


int main() {
	int array[10] = {0};

	for(int i = 0; i < 10; i++) {
		array[i] = i + 1;
	}

	cout << "Somma: " << somma(array, 0, 9) << endl;

	return 0;
}