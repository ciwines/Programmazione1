#include <iostream>
#include "stack.h"
using namespace std;

int main() {
	
	cout << "ciao" << endl;
	Stack stack;
	bool richiediInput = true;

	init(stack);

	cout << "ciao" << endl;

	do {
		int value = 0;
		char decisione;

		cout << "Operazioni: " << endl
			 << "\t1. push" << endl
			 << "\t2. pop" << endl
			 << "\t3. top" << endl
			 << "\t4. print" << endl
			 << "\t5. esci" << endl
			 << "> ";
		cin >> decisione;

		switch(decisione) {
			case '1': 
				cout << "Valore: ";
				cin >> value;
				if(!push(value, stack)) {
					cerr << "Coda piena!" << endl;
				}
				break;

			case '2': 
				if(!pop(stack)) {
					cerr << "Coda vuota!" << endl;
				}
				break;

			case '3': 
				if(!top(value, stack)) {
					cerr << "Cosa vuota!" << endl;
				}
				else {
					cout << "Valore: " << value << endl;
				}
				break;

			case '4': 
				print(stack);
				break;

			case '5': 
			default:
				richiediInput = false;
				break;
		}
	}
	while(richiediInput);

	deinit(stack);

	return 0;
}