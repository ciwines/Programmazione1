#include "esempio.h"

void esempio() {
	static int counter = 0;

	cout << "Counter: " << counter++ << endl;
}