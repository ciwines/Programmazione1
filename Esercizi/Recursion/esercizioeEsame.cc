#include <iostream>
using namespace std;


// 2 + 3 + 4
int calcola_somma(int a, int b, int res) {
	if(a <= b) {
		res += (a + b) + calcola_somma(a + 1, b -1, res);
	}
	return res;
}

int main() {
	int a = 0;
	int b = 0;

	do {
		cout << "a: ";
		cin >> a;

		cout << "b: ";
		cin >> b;
	} while(a < 0 || b < 0 || a > b);

	int somma = calcola_somma(a, b, 0);

	cout << "Somma: " << somma << endl;

	return 0;
}