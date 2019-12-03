#include <iostream>
using namespace std;

/*
 * 	una struttura è una collezione ordinata di elementi non omogenei
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
 *			miaStruct.elemento;
 *		Se abbiamo un puntatore a una struct, dobbiamo usare ->
 *			miaStructPtr->elemento;
 *		che equivale a (*miaStructPtr).elemento;
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
  
int main() {
	Complex a = {1, 2};
	Complex b = {2, 1};

	Complex c = complexAdd(a, b);

	complexPrint(c);

	return 0;
}