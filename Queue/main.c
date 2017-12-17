#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

int main(){

	struct Queue* queue = new_queue();

	add(queue,1);
	add(queue,2);
	add(queue,3);

	while(!isEmpity(queue))
		printf("%d\n",getFirst(queue));

	return 0;
}
