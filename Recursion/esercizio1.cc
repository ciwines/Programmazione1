#include <iostream>
using namespace std;

long long fattoriale(int n) {
	// caso base
	long long valore = 1;

	// caso generico
	if(n > 0) {
		valore = n * fattoriale(n - 1);
	}

	return valore;
}

int main() {
	int n = 0;

	cout << "Numero: ";
	cin >> n;

	cout << n << "! = " << fattoriale(n) << endl;

	return 0;
}