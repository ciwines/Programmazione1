#include <iostream>
#include <cmath>
using namespace std;

#define _USE_MATH_DEFINES

void areaCerchio(double raggio, double *area);

int main() {
	double raggio = 0.0;
	double area = 0.0;

	cout << "raggio: ";
	cin >> raggio;

	areaCerchio(raggio, &area);

	cout << "area: " << area << endl;

	return 0;
}

void areaCerchio(double raggio, double *area) {
	if(area != nullptr) {
		*area = M_PI * raggio * raggio;
	}
}