// Scriver un programmino che chieda una carattere descrivente una lingua 
// (es: 'i'= italiano, 'e'=inglese, ecc.) e scriva "buon giorno" 
// nella lingua prescelta. Usare l'istruzione switch.
#include <iostream>

using namespace std;

int main() {
    // variabili 
    char lingua;

    // chiedo la lingua all'utente
    cout << "Lingua: ";
    cin >> lingua;

    // in base alla lingua stampo buongiorno
    switch(lingua) {
        // italiano
        case 'i':
            cout << "Buongiorno";
            break;            

        // inglese
        case 'e':
            cout << "Good morning";
            break;

        // spagnolo
        case 's':
            cout << "Buenos dias";
            break;

        // francese
        case 'f':
            cout << "Bonjour";
            break;
    
        // lingua non riconosciuta
        default:
            cout << "Lingua non riconosciuta";
            break;
    }

    cout << endl;

    return 0;
}
