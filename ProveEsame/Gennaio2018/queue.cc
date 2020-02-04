#include "queue.h"
#include <iostream>
using namespace std;

static bool queueEmpty(const queue& q) {
	return (q.head == NULL);
}

void init(queue &q) {
	q.head = NULL;
	q.tail = NULL;
}

void deinit(queue &q) {
	while(q.head->next != NULL) {
		elem* tmp = q.head;
		q.head = q.head->next;

		delete q.head;
	}
}	

bool enqueue(queue &q, float n) {
	bool okay = true;

	elem* tmp = new (nothrow) elem;
	if(tmp == NULL) {
		okay = false;
	}
	else {
		tmp->value = n;

		if(queueEmpty(q)) {
			q.head = tmp;
		}
		else {
			tmp->next = q.tail;
			q.tail = tmp;
		}

		q.tail = tmp;
	}

	return okay;
}

bool dequeue(queue &q) {
	bool okay = true;

	if(queueEmpty(q)) {
		okay = false;
	}
	else {
		elem* tmp = q.head;
		q.head = q.head->next;

		delete tmp;
	}

	return okay;
}

bool first(const queue &q, float &out) {
	bool okay = true;

	if(queueEmpty(q)) {
		okay = false;
	}
	else {
		out = q.tail->value;
	}

	return okay;
}

void print(const queue &q) {
	queue tmp = q;

	while(!queueEmpty(tmp)) {
		cout << "valore -> " << tmp.tail->value << endl;
		tmp.tail = tmp.tail->next;
	}
}
