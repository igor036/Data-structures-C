#include "queue.h"

struct Queue* new_queue(){
	return (struct Queue*)malloc(sizeof(struct Queue));
}

void add(struct Queue* queue,void* value){

	struct Node* node = (struct Node*)malloc(sizeof(struct Node*));
	node->value = value;

	if(queue->size == 0){

		queue->first = queue->last = node;
		queue->first->next = queue->last;
		queue->last->previous = queue->first;

	} else {

		queue->last->next = node;
		queue->last = node;

	}

	queue->size++;

}

void* getFirst(struct Queue* queue){

	if (queue->size == 0)
		return NULL;

	struct Node* node = queue->first;
	void* value =  node->value;

	queue->first = queue->first->next;
	queue->size--;

	free(node);
	return value;
}

int isEmpity(struct Queue* queue){
	return queue->size == 0;
}

void clear(struct Queue* queue){

	struct Node* node = queue->first;

	while(node != NULL){
		struct Node* aux = node;
		node = node->next;
		free(aux);
	}

	queue->size = 0;
}
