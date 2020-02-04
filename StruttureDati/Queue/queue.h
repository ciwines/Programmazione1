#ifndef __QUEUE_H__
#define __QUEUE_H__

// dimensione dello Queue
static const int QUEUE_DIM = 100;

// retval
enum retval {
	FAIL,
	OKAY
};

// IMPLEMENTAZIONE STATICA

// IMPLEMENTAZIONE DINAMICA
struct Queue {
	int head;
	int tail;
	int* members;
	int size;
};

// funzioni
void init(Queue&);
void deinit(Queue&);
retval enqueue(int, Queue&);
retval dequeue(Queue&);
retval first(int&, const Queue&);
void print(const Queue&);

#endif