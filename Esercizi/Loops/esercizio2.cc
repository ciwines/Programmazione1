// scrivere un programma che prenda in ingresso un valore reale x 
// e calcoli (un'approssimazione del)la serie
// 
// Somma_i (-1)^i 1/(x^i)
#include <iostream>
#include <cmath>
using namespace std;

int main() {

	// variabili
	const int iterazioni = 20;
	double x = 0.0;
	double valoreSerie = 0.0;

	// chiedo il parametro x all'utente
	cout << "Inserisci un parametro reale: ";
	cin >> x;

	// calcolo un'approssimazione della serie
	for (int i = 0; i < iterazioni; i++) {
		double potenza = pow(-1, i);
		double valoreIesimo = potenza * (1 / pow(x, i));

		valoreSerie += valoreIesimo;
	}

	cout << "Serie [" << iterazioni << "]: " << valoreSerie << endl;

	return 0;
}