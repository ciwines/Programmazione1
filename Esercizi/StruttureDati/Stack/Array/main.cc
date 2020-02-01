// main di rseba
#include <iostream>
#include "stack.h"
using namespace std;

int main () 
{
    char res;
    double val;
    Stack s;

    init(s, 100);

    do {
		cout << "\nOperazioni possibili:\n"
			 << " Push (u)\n" 
			 << " Pop (o)\n" 
			 << " Top (t)\n" 
			 << " Print (p)\n" 
		 << " Fine (f)\n";
		cin >> res;

		switch (res) {
		case 'u':
		    cout << "Val? : ";
		    cin >> val;
		    if (push(s, val) == false)
				cout << "Stack pieno!\n";
		    break;
		case 'o':
		    if (pop(s) == false)
				cout << "Stack vuoto!\n";
		    break;
		case 't':
		    if (top(s, val) == false)
				cout << "Stack vuoto!\n";
		    else 
		    	cout << "Top = " << val << endl;
		    break;
		case 'p':
		    print(s);
		    break;
		case 'f':
		    break;
		default:
		    cout << "Opzione errata\n";
		}
    } while (res != 'f');

    deinit(s);

    return 0;
}
