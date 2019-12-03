#include <iostream>
using namespace std;

/*
 * 	new tipo; -> alloca un oggetto di tipo "tipo"
 *	new tipo(valore) -> alloca un oggetto di tipo "tipo" e lo inizializza
 *	new tipo[dim] -> allcoa un array di dim elememnti
 *	
 *	delete obj -> dealloca un oggetto allocato con new
 *	delete[] arr -> dealloca un array allocato con new[]
 *
 *	l'indirizzo ritornato da new va (ovviamente) salvato in un puntatore
 *
 *	Per ogni new/new[], dovrebbe esistere una delete/delete[]
 *
 */


void esempio1() {
	int dim = 0;

	cout << "Dimensione: ";
	cin >> dim;

	int* array = new int[dim];

	for(int i = 0; i < dim; i++) {
		array[i] = i;
		cout << "array[" << i << "]: " << array[i] << endl;
	}

	/*
	 *
	 */

	delete[] array;

	// ERRORE -> LETTURA IN UNA LOCAZIONE NON ALLOCATA!
	// => Not Stonks!tr
	cout << "-> delete[]" << endl;
	for(int i = 0; i < dim; i++) {
		array[i] = i;
		cout << "array[" << i << "]: " << array[i] << endl;
	}
}

int main() {
	#if 1
		esempio1();
	#endif

	return 0;
}