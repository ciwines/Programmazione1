// headers 
#include <iostream>
#include "queue.h"

// namespaces
using namespace std;

// main
int main () 
{
    char res;
    int num;    
    Queue q;
    
    qInit(q);
    do {
		cout << "\nOperazioni possibili:\n"
			 << "Enqueue (e)\n" 
			 << "First (f)\n" 
			 << "Dequeue (d)\n" 
			 << "Print (p)\n" 
			 << "Exit (x)\n";
		cin >> res;
		switch (res) {
		case 'e':
		    cout << "Valore: ";
		    cin >> num;
		    if (qEnqueue(q, num)==false)
			cout << "Coda piena\n";
		    break;
		case 'f':
		    if (qFirst(q, num)==false)
			cout << "Coda vuota\n";
		    else 
			cout << "Val: " << num << endl;
		    break;
		case 'd':
		    if (qDequeue(q)==false)
			cout << "Coda vuota\n";
		    break;
		case 'p':
		    qPrint(q);
		    break;
		case 'x':
		    break;
		default:
		    cout << "Valore errato!\n";
		}
    } while (res != 'x');  

    qDeinit(q);
}
