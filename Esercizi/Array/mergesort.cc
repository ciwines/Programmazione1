#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

/*
 *	implementare il seguente algoritmo di sorting ricorsivo (mergesort)
 * 		1 dividere l'array V in due parti uguali (+-1) V1 e V2
 *		2 invocare ricorsivamente mergesort sui due array
 *		3 fare il merge dei due array
 */

void mergeArray(int array[], int res[], int left, int middle, int right);
void mergeSort(int array[], int res[], int left, int right);

const int FIRST_DIM = 4;
const int SECOND_DIM = 4;

int main() {
	//int a[FIRST_DIM] = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
	//int a[FIRST_DIM] = {0, 2, 3, 7};
	//int b[SECOND_DIM] = {1, 4, 6, 8, 9, 13};
	int c[SECOND_DIM] = {4, 1, 3, 2};
	int r[SECOND_DIM] = {0};

	/*srand(time(nullptr));

	for(int i = 0; i < SECOND_DIM; i++) {
		c[i] = rand() % 50;
		cout << c[i] << "\t";
	}
	cout << endl;*/

	//mergeArray(a, b, r, FIRST_DIM, SECOND_DIM);
	mergeSort(c, r, 0, SECOND_DIM - 1);

	for(int i = 0; i < (SECOND_DIM); i++) {
		cout << c[i] << "\t";
	}
	cout << endl;
	return 0;
}

/*void mergeArray(int first[], int second[], int res[], int firstDim, int secondDim) {
	int i;
	int j;
	int iter;

	for(i = 0, j = 0, iter = 0;
		iter < (firstDim + secondDim) && i < firstDim && j < secondDim;
		iter++) {
		if(first[i] < second[j]) {
			res[iter] = first[i];
			i++;
		}
		else {
			res[iter] = second[j];
			j++;
		}
	}

	while(i < firstDim) {
		res[iter] = first[i];
		i++;
		iter++;
	}

	while(j < secondDim) {
		res[iter] = second[j];
		j++;
		iter++;
	}

	// debug
	//cout << "i: " << i << "\tj: " << j << "\titer: " << iter << "\tmatch: " << (iter == (firstDim + secondDim)) << endl;
}
*/

void mergeArray(int array[], int res[], int left, int middle, int right) {
	int i;
	int j;
	int iter;

	cout << "ARRAY INIZIO: ";
		for(int i = 0; i < 4; i++) {
			cout << array[i] << "\t";
		}
		cout << endl;

	for(i = left, j = middle + 1, iter = 0; 
		i <= middle && j <= right && iter <= right - left;
		iter++) {

		cout << "i: " << i << "\tj: " << j << "\tarray[i]: " << array[i] << "\tarray[j]: " << array[j] << endl;

		if(array[i] <= array[j]) {
			cout << array[i] << " <= " << array[j] << endl;
			res[iter] = array[i];
			i++;
		}
		else {
			cout << array[i] << " > " << array[j] << endl;
			res[iter] = array[j];
			j++;
		}
	}

	while(i <= middle) {
		cout << "aaaa" << endl;
		res[iter] = array[i];
		i++;
		iter++;
	}

	while(j <= right) {
		cout << "bbbb" << endl;
		res[iter] = array[j];
		j++;
		iter++;
	}

	for(int i = left; i <= right; i++) {
		array[i] = res[i];
	}

	cout << "ARRAY FINE: ";
		for(int i = 0; i < 4; i++) {
			cout << array[i] << "\t";
		}
		cout << endl;
} 

void mergeSort(int array[], int res[], int left, int right) {
	int index = (left + right) / 2;

	if(left < right) {

		cout << "--> left: " << left << "\tindex: " << index << "\tright: " << right << endl;
		cout << "LEFT mergeSort(array, res, " << left << ", " << index << ");" << endl;
		mergeSort(array, res, left, index);

		cout << "--> left: " << left << "\tindex: " << index << "\tright: " << right << endl;
		cout << "RIGHT mergeSort(array, res, " << index + 1 << ", " << right << ");" << endl;
		mergeSort(array, res, index + 1, right);

		cout << "\tmergeArray(array, res, " << left << ", " << index << ", " << right<< ");" << endl;
		mergeArray(array, res, left, index, right);
	}
}
