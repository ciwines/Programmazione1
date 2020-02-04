#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;

const int ELEMENTI_MAX_PER_RIGA = 255;

void usage();
void processa(const char* inputFile, const char* outputFile, int linesNum);
char** leggiFile(fstream& stream, int& linesNum);
void convertiRiga(char* riga);
void invertiRighe(char** righe, int numeroRighe);

int main(int argc, char* argv[]) {
	// controllo dei parametri
	if(argc != 4) {
		usage();
	}

	// argv[1] -> nome file di input
	int lines = atoi(argv[2]);
	// argv[3] -> nome file di output

	processa(argv[1], argv[3], lines);

	return 0;
}

void usage() {
	cerr << "Utilizzo: ./a.out <file di input> <numero di righe> <file di output>" << endl;
	exit(1);
}

void processa(const char* inputFile, const char* outputFile, int linesNum) {
	// apro gli stream
	fstream input;
	fstream output;

	input.open(inputFile, ios::in);
	output.open(outputFile, ios::out);

	if(!input) {
		cerr << inputFile << " non esiste!" << endl;
	}
	else {
		// alloco e leggo n righe dal file di input
		char** righe = leggiFile(input, linesNum);
		invertiRighe(righe, linesNum);

		// scrivo le righe invertite e modificate sul file di output
		for(int i = 0; i < linesNum; i++) {
			output.write(righe[i], strlen(righe[i]));
			output.put('\n');
			//cout << righe[i] << endl;
		}

		// dealloco le righe
		for(int i = 0; i < linesNum; i++) {
			delete[] righe[i];
		}
		delete[] righe;
	}

	// chiudo gli stream
	input.close();
	output.close();
}

char** leggiFile(fstream& stream, int& linesNum) {
	char buffer[ELEMENTI_MAX_PER_RIGA + 1];
	char** righe = new char*[linesNum];
	int dimensione;
	int i = 0;

	while(stream.getline(buffer, ELEMENTI_MAX_PER_RIGA) && i < linesNum) {

		// alloco la linea di dimensione strlen(buffer) + 1
		dimensione = strlen(buffer);
		righe[i] = new char[dimensione + 1];

		// copio buffer in righe[i]
		strncpy(righe[i], buffer, dimensione);
		righe[i][dimensione] = '\0';			

		// la converto secondo le specifiche
		convertiRiga(righe[i]);
		i++;
		//cout << "i -> " << i << endl;
	}

	if(i < linesNum) {
		linesNum = i;
	}

	return righe;
}

void convertiRiga(char* riga) {
	bool stringaTerminata = false;
	char c;
	for(int i = 0; i < (ELEMENTI_MAX_PER_RIGA + 1) && !stringaTerminata; i++) {
		c = riga[i];

		if(c == '\0') {
			stringaTerminata = true;
		}
		else if(c != ' ' && c != '\t') {
			// se è pari
			if(((i + 1) % 2) == 0) {
				riga[i] = '+';
			}
			// se è dispari
			else {
				riga[i] = '*';
			}
		}
	}
}

void invertiRighe(char** righe, int numeroRighe) {
	for(int i = 0; i < (numeroRighe / 2); i++) {
		char* tmp = righe[numeroRighe - 1 - i];
		righe[numeroRighe - 1 - i] = righe[i];
		righe[i] = tmp;
	}
}


