#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

/*
 *	tipo nome[dim1][dim2]...[dimN];
 *
 *	int mat[2][2] = { {1, 2}, {3, 4} };
 *		mat[0] è quindi {1, 2}
 *		mat[0][1] è 4
 *
 *	gli array multidimensionali vengono salvati come un'unica catena 
 *	di elementi continua! 
 *	-> http://www.cs.unibo.it/~renzo/lucidi11/lso-01-linguaggioc/img72.png
 *
 *	è quindi equivalente a un array unico di dim1 * dim2 * ... * dimN elementi
 *
 */

const int RIGHE = 3;
const int COLONNE = 3;

void stampaMat(int mat[][COLONNE]);

int main() {
	int mat[RIGHE][COLONNE] = {0};

	stampaMat(mat);

	srand(time(nullptr));

	for(int i = 0; i < RIGHE; i++) {
		for(int j = 0; j < COLONNE; j++) {
			mat[i][j] = rand() % 100;	
		}
	}

	stampaMat(mat);

	return 0;
}

void stampaMat(int mat[][COLONNE]) {
	for(int i = 0; i < RIGHE; i++) {
		for(int j = 0; j < COLONNE; j++) {
			cout << mat[i][j] << "\t";
		}
		cout << endl;
	}
}