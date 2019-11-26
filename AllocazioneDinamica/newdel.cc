#include <iostream>
using namespace std;

/*
 * 	new tipo; -> alloca un oggetto di tipo "tipo"
 *	new tipo(valore) -> alloca un oggetto di tipo "tipo" e lo inizializza
 *	new tipo[dim] -> allcoa un array di dim elememnti
 *	
 *	delete obj -> dealloca un oggetto allocato con new
 *	delete[] arr -> dealloca un array allocato con new
 *
 *	l'indirizzo ritornato da new va (ovviamente) salvato in un puntatore
 *
 *
 *
 */

int main() {
	int dim = 0;

	cout << "Dimensione: ";
	cin >> dim;

	int* array = new int[dim];

	/*
	 *
	 */

	delete[] array;

	//delete[] new int[dim];

	return 0;
}