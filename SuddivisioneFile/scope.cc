#include <iostream>
using namespace std;

/*
 *	Può essere globale o locale:
 *		- locale -> definizione attiva localmente ad una funzione/blocco di istruzioni
 *		- globale -> definizione attiva a livello di file
 *
 *	Durata di una definizione:
 *		- globale o statico (oggetti dichiarati con static) -> fino all'esecuzione del programma 
 *				(vengono salavati nell'area dati statici)
 *		- locale o automatico (oggetti locali a una funzione) -> durano solo per il periodo di tempo
 *				necessario ad eseguire il blocco o funzione in cui sono definiti 
 *				(vengono memorizzati nello stack)
 *		- dinamico (oggetti allocati e deallocati con new e delete) -> durano fino alla deallocazione con 
 *				delete. (vengono memorizzati nell'heap)
 *
 *	SPECIFICATORE static #1
 *		Applicato a una variabile locale forza la sua durata oltre la durata della funzione dove è definita.
 *		Queste variabili vengono infatti memorizzate nell'area dati statici.	
 *		=> il suo valore viene "ricordato" da una chiamata all'altra della funzione
 *
 *	SPECIFICATORE static #2
 *		Applicato ad un oggetto di scope globale(funzioni, variabili, globali, ...) ha l'effetto di restringere 
 *		la visibilità dell'oggetto al solo file in cui occorre la definizione
 *
 *	SPECIFICATORE extern
 *		Consente di dichiarare e poi utilizzare oggetti globali che sono definiti in un altro file
 *		Questo oggetto verrà associato alla sua definizione tramite il linker
 *
 *	
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */

void inc() {
	static int counter = 0;

	cout << "counter: " << counter << endl;
	counter++;
}

int main() {
	for(int i = 0; i < 5; i++) {
		inc();
	}

	return 0;
}