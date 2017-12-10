#include <stdio.h>
#include <stdlib.h>

/*Author Igor Joaquim*/

/*type's
 *------
 */
struct Node{
	void* value;
	struct Node* next;
	struct Node* previous;
};


struct List{
	struct Node* first;
	struct Node* last;
	int size;
};


/*function's
 *----------
 */

struct List* newList();
void* add(struct List*, void* value);
void* getByIndex(struct List* list,int index);
struct Node* getNodeByIndex(struct List* list,int index);
void* getByValue(struct List* list,void* value);
struct Node* getNodeByValue(struct List* list,void* value);
int deleteByIndex(struct List* list, int index);
int deleteByValue(struct List* list, void* value);
int isEmpty(struct List* list);
void printl(struct List* list);
void clear(struct List* list);
