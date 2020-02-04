#include <iostream>
#include "queue.h"
using namespace std;

int main() {
	
	cout << "ciao" << endl;
	Queue queue;
	bool richiediInput = true;

	init(queue);

	cout << "ciao" << endl;

	do {
		int value = 0;
		char decisione;

		cout << "Operazioni: " << endl
			 << "\t1. enqueue" << endl
			 << "\t2. dequeue" << endl
			 << "\t3. first" << endl
			 << "\t4. print" << endl
			 << "\t5. esci" << endl
			 << "> ";
		cin >> decisione;

		switch(decisione) {
			case '1': 
				cout << "Valore: ";
				cin >> value;
				if(!enqueue(value, queue)) {
					cerr << "Coda piena!" << endl;
				}
				break;

			case '2': 
				if(!dequeue(queue)) {
					cerr << "Coda vuota!" << endl;
				}
				break;

			case '3': 
				if(!first(value, queue)) {
					cerr << "Cosa vuota!" << endl;
				}
				else {
					cout << "Valore: " << value << endl;
				}
				break;

			case '4': 
				print(queue);
				break;

			case '5': 
			default:
				richiediInput = false;
				break;
		}
	}
	while(richiediInput);

	deinit(queue);

	return 0;
}