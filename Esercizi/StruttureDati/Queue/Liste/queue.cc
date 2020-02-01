// headers
#include "queue.h"
#include <iostream>
using namespace std;

// static functions
static bool qEmpty(const Queue& q) {
	return (q.head == nullptr);
}
 
// functions
void qInit(Queue& q) {
	q.head = nullptr;
	q.tail = nullptr;
}

void qDeinit(Queue& q) {
	while(!qEmpty(q)) {
		qDequeue(q);
	}
}

bool qEnqueue(Queue& q, double value) {
	bool ret = true;

	Node* tmp = new (nothrow) Node;

	if(tmp == nullptr) {
		ret = false;
	}
	else {
		tmp->value = value;
		tmp->next = nullptr;

		if(qEmpty(q)) {
			q.head = tmp;
		}
		else {
			q.tail->next = tmp;
			
		}

		q.tail = tmp;
	}
	
	return ret;
}

bool qDequeue(Queue& q) {
	bool ret = true;

	if(qEmpty(q)) {
		ret = false;
	}
	else {
		Node* tmp = q.head;

		q.head = q.head->next;

		delete tmp;
	}
	
	return ret;
}

bool qFirst(const Queue& q, int& outValue) {
	bool ret = true;

	if(qEmpty(q)) {
		ret = false;
	}
	else {
		outValue = q.head->value;
	}
	
	return ret;
}

void qPrint(const Queue& q) {
	Node* first = q.head;

	while(first != nullptr) {
		cout << first->value << " ";
		first = first->next;
	}
	cout << endl;
}
