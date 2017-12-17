#include <stdlib.h>
#include <stdio.h>

struct Node {
	void* value;
	struct Node* next;
};

struct Stack {
	int size;
	struct Node* top;
};

struct Stack* new_stack();
void push(struct Stack* stack, void* value);
void* pop(struct Stack* stack);
int isEmpity(struct Stack* stack);
void clear(struct Stack* stack);
