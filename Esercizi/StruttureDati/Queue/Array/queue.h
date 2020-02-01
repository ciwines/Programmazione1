#ifndef QUEUE_H
#define QUEUE_H

// structs
struct Queue {
	int 	head;
	int		tail;
	double*	elements;
	int 	size;
};

// functions
void qInit(Queue& q, int queueSize);
void qDeinit(Queue& q);
bool qEnqueue(Queue& q, double value);
bool qDequeue(Queue& q);
bool qFirst(const Queue& q, int& outValue);
void qPrint(const Queue& q);

#endif