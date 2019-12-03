#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

/*
 *	MAT[i] equivale a +(MAT + i)
 *	=> MAT[i][j] equivale a *((*(MAT + i)) + j)
 *
 *
 *	typedef -> permette di definire nuovi tipi 
 *		typedef int** matrix;
 *	
 *	ATTENZIONE: se dealloco mat e non mat[i], NON dealloco anche mat[i],
 *				si viene così a creare un memory leak
 *
 *
 *
 *
 * 
 */

typedef int** matrix;

void nomemory() {
	cout << "No memory." << endl;
}

// alloca una matrice di r righe e c colonne
matrix allocaDin(int r, int c) {
	// alloca r righe
	matrix mat = new (nothrow) int*[r];
	if(mat == nullptr) {
		nomemory();
	}

	for(int i = 0; i < r; i++) {
		// per ogni riga, alloca c colonne
		mat[i] = new (nothrow) int[c];
		if(mat[i] == nullptr) {
			nomemory();
		}
	}

	return mat;
}

// dealloca una matrice di r righe e c colonne
void deallocaDin(matrix mat, int r, int c) {
	for(int i = 0; i < r; i++) {
		// per ogni riga, dealloca le colonne
		delete[] mat[i];
	}

	delete[] mat;
}

int main(){
	int r = 0;
	int c = 0;
	matrix mat;

	srand(time(nullptr));

	cout << "Righe: ";
	cin >> r;

	cout << "Colonne: ";
	cin >> c;

	mat = allocaDin(r, c);

	// popolo la matrice
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			// mat[i][j] = rand() % 100;
			*((*(mat + i)) + j) = rand() % 100;
		}
	}

	// stampo la matrice
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			// cout << mat[i][j] << "\t";
			cout << *((*(mat + i)) + j) << "\t";
		}
		cout << endl;
	}

	deallocaDin(mat, r, c);

	return 0;
} 