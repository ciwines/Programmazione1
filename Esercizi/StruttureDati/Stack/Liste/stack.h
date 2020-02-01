#ifndef STACK_H
#define STACK_H

// types
struct Node;

struct Node {
	double value;
	Node* next;
};

typedef Node* Stack;

// funzioni
void init(Stack& s);
void deinit(Stack& s);
bool push(Stack& s, double value);
bool top(Stack& s, double& outValue);
bool pop(Stack& s);
void print(const Stack& s);

#endif