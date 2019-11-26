#include <iostream>
#include <cmath>
using namespace std;

#define _USE_MATH_DEFINES

bool datiCerchio(int raggio, double *area, double *circonferenza);

int main() {
	int raggio = 0;
	double area = 0.0;
	double circonferenza = 0.0;

	cout << "raggio: ";
	cin >> raggio;

	datiCerchio(raggio, &area, &circonferenza);

	cout << "area: " << area << endl;
	cout << "circonferenza: " << circonferenza << endl;

	return 0;
}

bool datiCerchio(int raggio, double *area, double *circonferenza) {
	bool raggioOk = true;

	if(raggio >= 0) {
		*area = M_PI * raggio * raggio;
		*circonferenza = 2 * M_PI * raggio;
	}
	else {
		raggioOk = false;
	}

	return raggioOk;
}