/* Author: Igor Joauqim dos Santos Lima
 * GitHub: https://github.com/igor036
 *
 * ----------------------------------------
 *
 * The key is using for find and insert a node struct
 * in the tree
 */

#include <stdio.h>
#include <stdlib.h>
#include "queue/queue.h"

struct node {

	int key,height;

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




//use malloc for create new tree.
struct tree* create_tree();




//verify if tree is empty
int tree_is_empty(struct tree* tree);




//insert in tree
void tree_insert(struct tree* tree, void* value, int key);




//get value of node
void* tree_get(struct tree* tree,int key);




//remove node for tree
void* tree_remove(struct tree* tree, int key);




//print all values.
void tree_print(struct tree* tree );




/* get the value of the node
 * with the smallest key
 */
void* tree_first(struct tree* tree);



/* get the value of the node
 * with the smallest key
 * and remove that node from the tree
 */
void* tree_remove_first(struct tree* tree);



/* get the value of the node
 * with the biggest key
 */
void* tree_last(struct tree* tree);



/* get the value of the node
 * with the biggest key
 * and remove that node from the tree
 */
void* tree_remove_last(struct tree* tree);
