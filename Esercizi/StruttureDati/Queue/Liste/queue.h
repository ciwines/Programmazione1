#ifndef QUEUE_H
#define QUEUE_H

// types
struct Node;
struct Node {
	double 	value;
	Node* 	next;
};

struct Queue {
	Node* 	head;
	Node* 	tail;
};

// functions
void qInit(Queue& q);
void qDeinit(Queue& q);
bool qEnqueue(Queue& q, double value);
bool qDequeue(Queue& q);
bool qFirst(const Queue& q, int& outValue);
void qPrint(const Queue& q);

#endif