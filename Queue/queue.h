#include <stdio.h>
#include <stdlib.h>

struct Node {

	void* value;
	struct Node* next;
	struct Node* previous;
};

struct Queue {

	int size;
	struct Node* first;
	struct Node* last;
};

/* uses mallock to create new pointer of queue */
struct Queue* new_queue();

/* add in the final of queue */
void add(struct Queue* queue,void* value);

/*get and remove the first element in the queue*/
void* getFirst(struct Queue* queue);

/*check if queue is empty*/
int isEmpity(struct Queue* queue);

/*clear the memory of all elements in the queue*/
void clear(struct Queue* queue);
