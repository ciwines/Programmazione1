#include <iostream>
using namespace std;

const int ARRAY_DIM = 10;

long int somma_prodotto_incrociato(int a1[], int a2[], int dim);
long int somma_prodotto_incrociato_ric(int a1[], int a2[],  int dim, int index);

int main() {
	int a1[ARRAY_DIM] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int a2[ARRAY_DIM] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55};

	cout << somma_prodotto_incrociato(a1, a2, ARRAY_DIM) << endl;

	return 0;
}

long int somma_prodotto_incrociato(int a1[], int a2[], int dim) {
	return somma_prodotto_incrociato_ric(a1, a2, dim, 0);
}

long int somma_prodotto_incrociato_ric(int a1[], int a2[], int dim, int index) {
	long int value = 0;

	if(index < dim) {
		value = a1[index] * a2[dim - 1 - index] + somma_prodotto_incrociato_ric(a1, a2, dim, index + 1);
	}	

	return value;
}	