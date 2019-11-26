// Stringhe (C)
#include <iostream>
using namespace std;

/*
 *	char nome[dim] = "Testo";
 *	 -> char ciao[] = "Ciao\0";
 *
 *	cin.eof() -> ritorna un valore diverso da 0 se è stata raggiunta la fine dello stream
 *	cin.fail() -> ritona un valore diverso da 0 se è stato riscontrato un errore di lettura 
 *					o viene raggiunta la fine dello stream
 *	cin.clear() -> resetta lo stato di errore
 *
 *
 *
 */

void esempio1() {
	char buffer[64] = {0};

	do {
		cout << "> ";
		cin >> buffer;

		cout << "-> " << buffer << endl;
	} while(buffer[0] != '.');
}

void esempio2() {
	char buffer[64] = {0};

	do {
		cin >> buffer;
		cout << buffer << endl;
	} while(!cin.eof());
}

void esempio3() {
	char buffer[64] = {0};

	do {
		if(!cin.fail()) {
			cin >> buffer;
			cout << buffer << endl;
		}
		else {
			cerr << "Errore nella lettura." << endl;
			cin.clear();
		}
	} while(!cin.eof());
}

void esempio4() {
	char buffer[64] = {0};

	while(cin.getline(buffer, 64)) {
		cout << "\t" << buffer << endl;
	}
}

int main() {
	#if 0
		esempio1();
	#endif 

	#if 0
		esempio2();
	#endif

	#if 0
		esempio3();
	#endif 

	#if 1
		esempio4();
	#endif

	return 0;
}