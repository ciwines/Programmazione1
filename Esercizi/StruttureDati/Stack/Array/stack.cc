// headers
#include <iostream>
#include "stack.h"
using namespace std;

// funzioni statiche
static bool empty(const Stack& s) {
	return (s.index == 0);
}

static bool full(const Stack& s) {
	return (s.index == s.size);
}

// funzioni 
void init(Stack& s, int size) {
	s.size = size;
	s.index = 0;
	s.elements = new double[size];
}

void deinit(Stack& s) {
	if(s.elements != nullptr) {
		delete[] s.elements;
	}
}

bool push(Stack& s, double value) {
	bool ret = true;

	if(full(s)) {
		ret = false;
	}
	else {
		s.elements[s.index] = value;
		s.index++;
	}

	return ret;
}

bool top(Stack& s, double& outValue) {
	bool ret = true;

	if(empty(s)) {
		ret = false;
	}
	else {
		outValue = s.elements[s.index - 1];
	}

	return ret;
}

bool pop(Stack& s) {
	bool ret = true;

	if(empty(s)) {
		ret = false;
	}
	else {
		s.index--;
	}

	return ret;
}

void print(const Stack& s) {
	for(int i = 0; i < s.index; i++) {
		cout << s.elements[i] << " ";
	}
	cout << endl;
}