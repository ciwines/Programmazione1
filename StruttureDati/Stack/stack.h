#ifndef __STACK_H__
#define __STACK_H__



// dimensione dello stack
static const int STACK_DIM = 100;

// retval
enum retval {
	FAIL,
	OKAY
};

// IMPLEMENTAZIONE STATICA
// struct stack
/*struct Stack {
	int index;
	int members[STACK_DIM];
};*/

// IMPLEMENTAZIONE DINAMICA
struct Stack {
	int index;
	int* members;
};

// funzioni
void init(Stack&);
void deinit(Stack&);
retval push(int, Stack&);
retval top(int&, const Stack&);
retval pop(Stack&);
void print(const Stack&);

#endif