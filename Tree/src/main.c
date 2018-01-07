#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(void) {

	struct tree* tree = create_tree();

	printf("size of tree is %d\n",tree->size);
	printf("is empty = %d\n",tree_is_empty(tree));

	tree_insert(tree,2,2);
	tree_insert(tree,1,1);
	tree_insert(tree,3,3);

	/*
	printf("\n%s\n","Arvore");
	tree_print(tree);*/

	printf("\n%s\n","Arvore");

	tree_remove(tree,2);
	tree_print(tree);


	return 2;
}
