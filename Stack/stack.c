#include "stack.h"

struct Stack* new_stack(){
	return (struct Stack*)malloc(sizeof(struct Stack));
}

void push(struct Stack* stack, void* value){

	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->value = value;

	if (stack->size > 0)
		node->next = stack->top;

	stack->top = node;
	stack->size++;
}

void* pop(struct Stack* stack){

	if (stack->size == 0)
		exit(1);

	struct Node* top = stack->top;
	void* value = top->value;

	if(stack->size > 0)
		stack->top = top->next;

	free(top);
	stack->size--;

	return value;
}

int isEmpity(struct Stack* stack){
	return stack->size > 0 ? 1 : 0;
}

void clear(struct Stack* stack){

	struct Node* node = stack->top;

	while(node != NULL){
		struct Node* aux = node;
		node = node->next;
		free(aux);
	}

	stack->size = 0;
}
