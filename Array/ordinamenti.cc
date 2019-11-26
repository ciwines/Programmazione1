#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

/*
 * Due categorie: quadratici e n logn
 * 	Bubblesort -> O(n^2) -> funziona bene quando gli elementi sono quasi completamente ordinati
 *
 *	Quicksort -> O(nlogn)
 *
 *
 */

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

/*
	BUBBLESORT 
	
	procedure BubbleSort(A:lista di elementi da ordinare)
  		scambio ← true
	  	n ← length(A) - 2
	  	while (scambio) do
	    	scambio ← false
	    	for i ← 0 to n + 1 do
	      		if (A[i] > A[i + 1]) then       //sostituire '>' con '<' per ottenere un ordinamento decrescente
	        		swap ( A[i], A[i+1] )
	        		scambio ← true
	    	n ← n-1                           //ad ogni passaggio si accorcia di uno il ciclo di for
*/

// funzione ausiliaria
void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void bubblesort(int array[], int dim) {
	for(int i = dim - 1; i > 0; i--) {
		for(int j = 0; j < i; j++) {
			if(array[j] > array[j + 1]) {
				swap(array[j], array[j + 1]);
			}
		}
	}
}

// una volta che l'array risulta ordinato, termina le iterazioni, evitando cicli inutili
void bubblesortOttimizzato(int array[], int dim) {
	bool sorted = false;

	for(int i = dim - 1; i > 0 && !sorted; i--) {
		sorted = true;
		for(int j = 0; j < i; j++) {
			if(array[j] > array[j + 1]) {
				sorted = false;
				swap(array[j], array[j + 1]);
			}
		}
	}
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

/*
	Function Partition(A, p, q)
	begin
	  	i ← p
	  	j ← q
	  	while i ≤ j do
	    	begin
	      		while A[j] > A[p] do j ← j - 1
	      		while i ≤ j and A[i] ≤ A[p] do i ← i + 1
	      		if i < j then
	         	begin
	           		Scambia(A[i], A[j])
	           		i ← i + 1
	           		j ← j - 1
	         	end
	    	end
	  	Scambia(A[p], A[j])
	  	return j
	end
*/

/*
	Procedure Quicksort(A, p, q)
	 	Input A vettore di elementi
	   	begin
	     	l ← Partition (A, p, q)
	     	if (l - p) < (q - l) then
	       	begin
	         	if p < (l - 1) then Quicksort(A,p, l - 1)
	         	if (l + 1) < q then Quicksort(A, l + 1, q)
	       	end
	     	else
	       	begin
	         	if (l + 1) < q then Quicksort(A, l + 1,q)
	         	if p < (l - 1) then Quicksort(A,p, l - 1)
	       	end
	   	end
*/

int partition(int array[], int first, int last) {
	int i = first;
	int j = last;

	while(i <= j) {
		while(array[j] > array[first])
			j--;

		while(i <= j && array[i] <= array[first])
			i++;

		if(i < j) {
			swap(array[i], array[j]);
			i++;
			j--;
		}
	}

	swap(array[first], array[j]);
	return j;
}

void quicksort(int array[], int first, int last) {
	int l = partition(array, first, last);
	if((l - first) < (last - l)) {
		if(first < (l - 1))
			quicksort(array, first, l - 1);
	    if((l + 1) < last)
	     	quicksort(array, l + 1, last);
	}
	else {
		if((l + 1) < last)
			quicksort(array, l + 1, last);
	    if(first < (l - 1))
	     	quicksort(array, first, l - 1);
	}
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

int main() {
	srand(time(nullptr));

	const int dimensione = 20;
	int array[dimensione] = {0};

	for(int i = 0; i < dimensione; i++) {
		array[i] = rand() % 50 + 1;
		cout << array[i] << endl;
	}

	// bubblesort(array, dimensione);
	//bubblesortOttimizzato(array, dimensione);
	quicksort(array, 0, dimensione - 1);

	cout << "Ordinato! " << endl;
	for(int i = 0; i < dimensione; i++) {
		cout << array[i] << endl;
	}



	return 0;
}