#include "List.h"


struct List* newList(){
	struct List* list = (struct List*)malloc(sizeof(struct List));
	return list;
}

void* add(struct List* list,void* value){

	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->value = value;

	if (list->size == 0){

		list->first = list->last = node;
		list->first->next = list->last;
		list->last->previous = list->first;

	} else {

		list->last->next = node;
		node->previous = list->last;
		list->last = node;
	}

	list->size++;
	return value;
}

void* getByIndex(struct List* list,int index){

	if (index > list->size || index < 0)
		return NULL;
	if(index == list->size-1)
		return list->last->value;
	if (index == 0)
		return list->first->value;

	struct Node* node;

	if (index > list->size)  {
		node = list->last;
		for (int i = list->size; i > index; i--){
			node = node->previous;
		}
	} else {
		node = list->first;
		for (int i = 0; i < index; i++)
			node = node->next;
	}

	return node->value;
}

struct Node* getNodeByIndex(struct List* list,int index){

	struct Node* node;

	if (index > list->size)  {
		node = list->last;
		for (int i = list->size; i > index; i--)
			node = node->previous;

	} else {
		node = list->first;
		for (int i = 0; i < index; i++)
			node = node->next;
	}

	return node;

}

void* getByValue(struct List* list,void* value){

	if (list->first->value == value)
		return list->first->value;

	if (list->last->value == value)
		return list->last->value;

	struct Node* node = list->first;

	for (int i = 0; i < list->size; i++){
		if (node->value == value)
			return node->value;
		node = node->next;
	}
}

struct Node* getNodeByValue(struct List* list,void* value){

	struct Node* node = list->first;

	for (int i = 0; i < list->size; i++){
		if (node->value == value)
			return node;
		node = node->next;
	}
}

int deleteByIndex(struct List* list, int index){

	if (index >= list->size || index < 0)
		return 0;

	struct Node* node;

	if (index == 0) {

		node = list->first;
		list->first = list->first->next;

	} else if (index == list->size-1) {

		node = list->last;
		list->last =  list->last->previous;

	} else {

		node = getNodeByIndex(list,index);
		node->previous->next = node->next;
	}
	list->size--;
	free(node);
	return 1;
}


int deleteByValue(struct List* list, void* value){

	struct Node* node;

	if (list->first->value == value) {

		node = list->first;
		list->first = list->first->next;

	} else if (list->last->value == value) {

		node = list->last;
		list->last =  list->last->previous;

	} else {

		node = getNodeByValue(list,value);
		if (node == NULL)
			return 0;

		node->previous->next = node->next;
	}
	list->size--;
	free(node);
	return 1;
}


int isEmpty(struct List* list){
	return list->first == NULL ? 1 : 0;
}

void printl(struct List* list){

	struct Node* node = list->first;

	for (int i = 0; i < list->size-1; i++){
		printf("%s\n",node->value);
		node = node->next;
	}

}

void clear(struct List* list){

	struct Node* node = list->first;

	while(node != NULL){
		struct Node* temp = node->next;
		free(node);
		node = temp;
		list->size--;
	}
}
