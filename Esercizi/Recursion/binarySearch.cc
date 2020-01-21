#include <iostream>
using namespace std;

int search(const int* array, int dim, int value);
int binarySearch(const int* array, int dim, int left, int right, int value);

int main() {
	const int array[8] = {0, 2, 4, 6, 7, 9, 12, 34};

	cout << search(array, 8, 0) << endl;

	return 0;
}

int search(const int* array, int dim, int value) {
	return binarySearch(array, dim, 0, dim - 1, value);
}

int binarySearch(const int* array, int dim, int left, int right, int value) {
	int index = (left + right) / 2;

	// cout << "bs(array, " << dim << ", " << left << ", " << right << ", " << value << ");" << endl;

	if(array[index] != value) {
		if(left <= right) {
			if(array[index] > value) {
				index = binarySearch(array, dim, left, index - 1, value);
			} 
			else if (array[index] < value) {
				index = binarySearch(array, dim, index + 1, right, value);
			}

			// se array[index] è uguale a value non fa nulla poichè index contiene già la posizione nell'array
		}
		else {
			index = -1;
		}
	}

	return index;
}