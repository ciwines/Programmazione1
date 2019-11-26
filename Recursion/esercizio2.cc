#include <iostream>
using namespace std;

void spazi(int n) {
	for(int i = 0; i < n; i++) {
		cout << " ";
	}
}

bool _prime(long long n, long long corrente) {
	bool primo = true;

	if(n < 2) {
		primo = false;
	}
	else if(corrente < n) {
		primo = ((n % corrente) != 0);
		if(primo) {
			++corrente;
			cout << "Prime(" << n << ", " << corrente << ") -> " << primo << endl;
			primo = _prime(n, corrente);
		}
	}

	return primo;
}

bool prime(long long n) {
	return _prime(n, 2);
}

int main() {
	int n = 0;
	bool primo = false;

	cout << "Numero: ";
	cin >> n;

	primo = prime(n);

	/*for(int i = 0; i <= n; i++)
		cout << i << ((prime(i)) ? " è primo." : " non è primo.") << endl;*/

	return 0;
}