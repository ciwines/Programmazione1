#include <iostream>
#include <cmath>
using namespace std;

double f(double x);

int main() {
	for(int i = -10; i <= 10; i++)
		cout << i << ": " << f(i) << endl;

	return 0;
}

double f(double x) {
	double risultato = 0;

	if(x <= 0)
		risultato = -pow(x, 3);
	else 
		risultato = exp(x-1);

	return risultato;
}