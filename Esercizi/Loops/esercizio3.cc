// scrivere un programma che prenda in ingresso un valore reale x 
// e un intero N e calcoli x^N come prodotto di N volte X.
#include <iostream>
using namespace std;

int main() {

	// variabili
	double x = 0.0;
	int n = 0;
	double valore = 0.0;
	bool inverti = false;
	bool calcolato = false;

	// richiedo i parametri
	cout << "Base: ";
	cin >> x;

	cout << "Esponente: ";
	cin >> n;

	// calcolo la potenza
	if (n == 0) {
		calcolato = true;
		valore = 1;
	}
	else if (n < 0) {
		inverti = true;
		n = -n;
	} 

	if (!calcolato) {
		valore = x;
		for (int i = 1; i < n; i++) {
			valore *= x;
		}

		if (inverti) {
			valore = 1 / valore;
		} 
	}	

	// mostro a schermo il risultato 
	cout << x << "^" << n << " = " << valore << endl;
	return 0;
}