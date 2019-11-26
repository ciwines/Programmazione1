#include <iostream>
#include <cmath>
using namespace std;

void ruota(int &a, int &b, int &c);
void stampa(int a, int b, int c);

int main() {
	int a = 1;
	int b = 2;
	int c = 3;

	stampa(a, b, c);
	ruota(a, b, c);
	stampa(a, b, c);

	return 0;
}

void stampa(int a, int b, int c) {
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "c: " << c << endl;
}

void ruota(int &a, int &b, int &c) {
	int tmp = c;
	c = b;
	b = a;
	a = tmp;
}