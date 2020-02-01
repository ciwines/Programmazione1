#ifndef STACK_H
#define STACK_H

struct Stack {
	double* elements;
	int index;
	int size;
};

void init(Stack& s, int size);
void deinit(Stack& s);
bool push(Stack& s, double value);
bool top(Stack& s, double& outValue);
bool pop(Stack& s);
void print(const Stack& s);

#endif