#include <iostream>
#include <cstring>
using namespace std;

/*
 * 	una struttura è una collezione ORDINATA di elementi non omogenei
 *	
 *	struct Nome {
 *		tipo1 id1;
 *		  ....
 *		tipoN idN;
 *	};
 *
 *	esempio:
 *		struct Complex {
 *			double re;
 *			double im;
 *		};
 *
 *	Le strutture si possono annidare, ovvero è possibile inserire una struct come 
 *	membro di un'altra struct
 *	
 *	NB: per accedere a un elemento di una struct si usa .
 *			miaStruct.elemento; (è un'espressione dotata di indirizzo!)
 *		Se abbiamo un puntatore a una struct, dobbiamo usare ->
 *			miaStructPtr->elemento; (zuccherino sintattico)
 *		che equivale a (*miaStructPtr).elemento;
 *	
 *	è possibile fare delle assegnazioni tra struct, differentemente dagli array
 *	vengono copiati tutti i valori dei membri. Se un campo è STATICO, viene copiato per intero!
 *	
 *	Le struct possono essere ritornate dalle funzioni
 *
 *	è possibile dichiarare una struct prima di definirla
 *		struct persona;
 *			*
 *			*
 *			*
 *		struct persona {
 *			tipo1 membro1;
 *			tipo1 membro1;
 *		};
 */


// esempio 1
struct Complex {
	double re;
	double im;
 };

Complex complexAdd(const Complex& a, const Complex& b) {
	Complex res = {0};

	res.re = a.re + b.re;
	res.im = a.im + b.im;

	return res;
}

void complexPrint(const Complex& z) {
	cout << "Re(z) = " << z.re << "\tIm(z) = " << z.im << endl;
}

// esempio 2, struct annidate
struct Data {
	int giorno;
	int mese;
	int anno;
};

struct Persona {
	char nome[20];
	char cognome[20];
	Data nascita;
	/*
	 *
	 *
	 */
};

struct Studente {
	Persona identita;
	char corso[20];
	int matricola;
	/*
	 *
	 *
	 */
};

Studente* generaStudente() {
	Studente* studente = new Studente();

	studente->matricola = 1234;
	strcpy(studente->corso, "corso");
	strcpy(studente->identita.nome, "Nome");
	strcpy(studente->identita.cognome, "Cognome");
	studente->identita.nascita.giorno = 24;
	studente->identita.nascita.mese = 12;
	studente->identita.nascita.anno = 1999;

	return studente;
}

void stampaStudente(const Studente* studente) {
	cout << "Nome: " << studente->identita.nome << endl;
	cout << "Cogome: " << studente->identita.cognome << endl;
	cout << "Nascita: " << studente->identita.nascita.giorno << "/" 
						<< studente->identita.nascita.mese << "/"
						<< studente->identita.nascita.anno << endl;
	cout << "Corso: " << studente->corso << endl;
	cout << "Matricola: " << studente->matricola << endl;
}
  
int main() {
	#if 0
		Complex a = {1, 2};
		Complex b = {2, 1};

		Complex c = complexAdd(a, b);

		complexPrint(c);
	#endif 

	#if 1
		Studente* studente = generaStudente();
		Studente a = *studente;

		stampaStudente(&a);

		delete studente;
	#endif

	return 0;
}