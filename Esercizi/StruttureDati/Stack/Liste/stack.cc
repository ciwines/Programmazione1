// headers
#include "stack.h"
#include <iostream>
using namespace std;

// static functions
static bool empty(const Stack& s) {
	return (s == NULL);
}

// functions
void init(Stack& s) {
	s = NULL;
}

void deinit(Stack& s) {
	while(!empty(s)) {
		pop(s);
	}
}

bool push(Stack& s, double value) {
	bool ret = true;

	Node* tmp = new (nothrow) Node;

	if(tmp == NULL) {
		ret = false;
	}
	else {
		tmp->value = value;
		tmp->next = s;
		s = tmp;
	}

	return ret;
}

bool top(Stack& s, double& outValue) {
	bool ret = true;

	if(empty(s)) {
		ret = false;
	}
	else {
		outValue = s->value;
	}

	return ret;
}

bool pop(Stack& s) {
	bool ret = true;

	if(empty(s)) {
		ret = false;
	}
	else {
		Stack tmp = s;
		s = s->next;
		delete tmp;
	}

	return ret;
}

void print(const Stack& s) {
	Stack tmp = s;

	while(tmp->next != NULL) {
		cout << tmp->value << " ";
		tmp = tmp->next;
	}
	cout << endl;
}
