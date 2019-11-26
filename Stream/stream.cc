#include <iostream>
#include <fstream>
using namespace std;

/*
 * 	-> fstream
 *	3 possibili modalità di apertura(open):
 *		- lettura
 *		- scrittura
 *		- scrittura a fine file (append)
 *
 *	fstream nome;
 *	es: fstream in, out, app;
 *		in.open("in.txt", ios::in);	
 *		out.open("out.txt", ios::out);
 *		app.open("app.txt", ios::out | ios::app);
 *	
 *	Durante l'apertura in scrittura, se il file non esiste, viene creato
 *	
 *	Gli stream aperti vanno chiusi!
 *
 *
 *
 *
 */	

bool apriLettura(const char* nome, fstream& stream) {
	bool aperto = true;

	stream.open(nome, ios::in);
	if(stream.fail()) {
		cout << "Errore durante l'apertura" << endl;
		aperto = false;
	}

	return aperto;
}

int main() {
	fstream in;

	if(apriLettura("in.txt", in)) {
		while(!in.eof()) {
			char line[80] = {0};
			in.getline(line, 80);
			cout << line << endl;
		}
	}

	in.close();

	return 0;
}