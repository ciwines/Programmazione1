#include <iostream>
using namespace std;

/*
 * NB: gli array vengono passati per riferimento!
 *
 *
 *
 *
 *
 */
double* esempio(double a[], const double b[], int dimensione) {
	for(int i = 0; i < dimensione; i++) {
		a[i] += b[i];
	}

	return a;
}

int main() {
	double a[10];
	double b[10];

	cout << sizeof(a)/sizeof(a[0]) << "\t" << sizeof(b)/sizeof(b[0]) << endl;

	for(int i = 0; i < 10; i++) {
		a[i] = i;
		b[i] = 10 - 1 - i;
	}

	esempio(a, b, 10);

	for(int i = 0; i < 10; i++) {
		cout << "a[" << i << "]: " << a[i] << endl;
	}

	return 0;
}