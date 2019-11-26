// Scrivere un programma che risolva un'equazione di 2 grado nei reali
#include <iostream>
#include <cmath>

using namespace std;

int main() {
	// variabili
	// l'equazione ha forma ax^2 + bx + c = 0
	double a;
	double b;
        double c;
        
	// richiedo i parametri
	cout << "a: ";
	cin >> a;

	cout << "b: ";
	cin >> b;

	cout << "c: ";
	cin >> c;

	// calcolo il discriminante
	double delta = pow(b, 2) - (4 * a * c);

	// tre casi
	// delta < 0, dobbiamo
	if (delta < 0) {
		// l'equazione non ha soluzioni reali
	        double modulo = sqrt(abs(delta));
                double x1 = -b / (2 * a);
                double y1 = -modulo;
                double y2 = modulo;

                char segno1 = y1 >= 0 ? '+' : '-';    
                char segno2 = y2 >= 0 ? '+' : '-';
                
                if (x1 == -0) {
                        x1 = 0;
                }

                cout << "Le soluzioni complesse sono z1=" << x1 <<  segno1 << abs(y1) << "i e z2=" << x1 << segno2  << abs(y2) << "i" << endl;
	}

	// delta == 0
	else if (delta == 0) {
		// calcolo la soluzione e la mostro a schermo
		double x = -b / (2 * a);
		if (x == -0) {
		    x = 0;
		}

		cout << "La soluzione è x=" << x << endl;
	}

	// caso generico, delta > 0
	else {
		// calcolo le soluzioni e le mostro a schermo
		double x1 = (-b - sqrt(delta)) / (2 * a);
		double x2 = ((-b + sqrt(delta)) / (2 * a));

		cout << "Le soluzioni sono x1=" << x1 << " e x2=" << x2 << endl;
	}

	return 0;
}
