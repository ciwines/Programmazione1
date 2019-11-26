#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int DIM = 50000;

int _linearSearch(int array[], int dim, int value, int iteration);
int linearSearch(int array[], int dim, int value);

int main() {
	int array[DIM] = {0};
	int value = 0;

	srand(time(nullptr));

	for(int i = 0; i < DIM; i++) {
		array[i] = rand() % 1000;
	}

	cout << "> ";
	cin >> value;

	int found = linearSearch(array, DIM, value);

	cout << "Valore " << ((found != -1) ? "trovato!" : "non trovato!") << endl;

	return 0;
}

int _linearSearch(int array[], int dim, int value, int iteration) {
	int index = -1;

	if(array[0] == value) {
		index = iteration;
	}
	else if(dim > 0) {
		index = _linearSearch(&array[1], dim - 1, value, iteration + 1);
	}

	return index;
}

int linearSearch(int array[], int dim, int value) {
	return _linearSearch(array, dim, value, 0);
}