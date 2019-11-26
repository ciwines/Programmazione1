#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int randomBetween(int min, int max);
void simulaRound(int &numDifensori, int &numAttaccanti);

int main() {
	srand(time(nullptr));
	int difensori = 3;
	int attaccanti = 3;

	do {
		simulaRound(difensori, attaccanti);
	} while(difensori > 0 && attaccanti > 0);

	if(difensori == 0) {
		cout << "I difensori hanno perso!" << endl;
	} 
	else {
		cout << "Gli attaccanti hanno perso!" << endl;
	}

	return 0;
}

int randomBetween(int min, int max) {
	return min + (rand() % max);
}

void simulaRound(int &numDifensori, int &numAttaccanti) {
	int round = min(numDifensori, numAttaccanti);

	for(int i = 0; i < round; i++) {
		int valDifensori = randomBetween(1, 6);
		int valAttaccanti = randomBetween(1, 6);

		if(valDifensori >= valAttaccanti) {
			numAttaccanti--;
		}
		else {
			numDifensori--;
		}
	}
}