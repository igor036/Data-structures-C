#include <stdio.h>
#include <stdlib.h>
#include "queue/queue.h"

struct node {
	int height,key;
	void* value;
	struct node* father;
	struct node* left;
	struct node* right;
};

struct tree {
	int size;
	struct node* root;
};


//aux methods
int height_node(struct node* node);
int balancing_factor(struct node* node);


struct tree* create_tree();
int tree_is_empty(struct tree* tree);
void tree_insert(struct tree* tree, void* value, int key);
struct node* get_node(struct tree* tree,int key);
void* get(struct tree* tree,int key);
void tree_remove(struct tree* tree, int key);
void tree_print(struct tree* tree );
