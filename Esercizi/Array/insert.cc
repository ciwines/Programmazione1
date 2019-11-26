#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int DIM = 10;

void insert(int startArray[], int endArray[], int startDim, int endDim, int value);

int main() {
	int array[DIM] = {1, 2, 3, 4, 5, 6, 8, 9, 10, 11};
	int end[DIM + 1] = {0};
	int value = 0;

	cout << "> ";
	cin >> value;

	insert(array, end, DIM, DIM + 1, value);

	for(int i = 0; i < DIM + 1; i++) {
		cout << end[i] << endl;
	}

	return 0;
}

void insert(int startArray[], int endArray[], int startDim, int endDim, int value) {
	bool inserted = false;
	for(int i = 0; i < startDim; i++) {
		if(startArray[i] > value && !inserted) {
			endArray[i] = value;
			endArray[i + 1] = startArray[i];
			i++;
			inserted = true;
		} 
		else {
			endArray[i] = startArray[i];
		}
	}

	if(!inserted) {
		endArray[endDim - 1] = value;
	}
}