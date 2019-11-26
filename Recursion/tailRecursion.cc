#include <iostream>
using namespace std;

/*
	type F(int x,...) {
		if (CasoBase(x,...))
			res = IstrBase(...);

		else {
			Istr(...);
			x = agg(x,...);
			res = F(x,...);
		}

		return res;
	}
	
	Si può scrivere come 

	type F(int x,...) {
		while (!CasoBase(x,...)){
			Istr(...);
			x = agg(x,...);
		}

		res = IstrBase(...);
		return res;
	}

	NB: con -O2 viene automaticamente effettuata questa conversione
*/

// ricorsiva
long long fattoriale(int n) {
	// caso base
	long long valore = 1;

	// caso generico
	if(n > 0) {
		valore = n * fattoriale(n - 1);
	}
	
	return valore;
}

long long fattorialeIterativo(int n) {
	long long valore = 1;

	while(n > 0) {
		valore *= n;
		n--;
	}

	return valore;
}

int main() {
	cout << "Fattoriale ricorsivo: 4! = " << fattoriale(4) << endl;
	cout << "Fattoriale iterativo: 4! = " << fattorialeIterativo(4) << endl;

	return 0;
}