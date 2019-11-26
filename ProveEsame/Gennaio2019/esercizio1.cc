#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;

void toUpper(char& c);
bool isEndPhrase(char c) ;

int main(int argc, char *argv[]) {
	// variabili
	fstream inFile;
	fstream outFile;
	char c;

	// controllo sugli argomenti
	if(argc != 3) {
		cout << "./a.out <test> <testocorretto>" << endl;
		exit(0);
	}

	// apro il file da correggere
	inFile.open(argv[1], ios::in);
	if(inFile.fail()) {
		cout << argv[1] << " non esiste." << endl;
		exit(0);
	}

	// apro il file corretto
	outFile.open(argv[2], ios::out);

	// lettura del primo carattere
	inFile.get(c);
	toUpper(c);
	outFile << c;

	// resto del file
	while(!inFile.eof()) {
		inFile.get(c);

		if(isEndPhrase(c)) {
			cout << "end" << endl;
			do {
				outFile << c;
				inFile.get(c);;
			} while(c == ' ');

			toUpper(c);
			cout << c << endl;
			outFile << c;
		} 
		else {
			outFile << c;
		}
	}

	inFile.close();
	outFile.close();

	return 0;
}

void toUpper(char& c) {
	if(c >= 'a' && c <= 'z') {
		c = 'A' + c - 'a';
	}
}

bool isEndPhrase(char c) {
	bool endPhrase = false;

	switch(c) {
		case '.':
		case '?':
		case '!':
			endPhrase = true;
	}

	return endPhrase;
}