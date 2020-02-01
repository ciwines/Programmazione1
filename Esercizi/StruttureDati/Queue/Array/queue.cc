// headers
#include "queue.h"
#include <iostream>
using namespace std;

// static functions
static int qNext(int index, const Queue& q) {
	return ((index + 1) % q.size);
}

static bool qEmpty(const Queue& q) {
	return (q.head == q.tail);
}

static bool qFull(const Queue& q) {
	return (qNext(q.tail, q) == q.head);
}

// functions
void qInit(Queue& q, int queueSize) {
	q.head = 0;
	q.tail = 0;
	q.elements = new (nothrow) double[queueSize + 1];
	q.size = queueSize + 1;
}

void qDeinit(Queue& q) {
	if(q.elements) 
		delete[] q.elements;
}

bool qEnqueue(Queue& q, double value) {
	bool ret = true;

	if(qFull(q)) {
		ret = false;
	}
	else {
		q.elements[q.tail] = value;
		q.tail = qNext(q.tail, q);
	}

	return ret;
}

bool qDequeue(Queue& q) {
	bool ret = true;

	if(qEmpty(q)) {
		ret = false;
	}
	else {
		q.head = qNext(q.head, q);
	}

	return ret;
}

bool qFirst(const Queue& q, int& outValue) {
	bool ret = true;

	if(qEmpty(q)) {
		ret = false;
	}
	else {
		outValue = q.elements[q.head];
	}

	return ret;
}

void qPrint(const Queue& q) {

  	for (int i=q.head; i!=q.tail; i=qNext(i,q)) {
    	cout << q.elements[i] << " ";
    }

  	cout << endl;
}		
