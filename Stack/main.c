#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

int main(){

	struct Stack* stack = new_stack();

	push(stack,3);
	push(stack,2);
	push(stack,1);

	while(stack->size > 0)
		printf("%d\n", pop(stack));

	return 0;
}
