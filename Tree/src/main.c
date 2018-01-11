#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(void) {

	struct tree* tree = create_tree();

	tree_insert(tree,15,15);
	tree_insert(tree,27,27);
	tree_insert(tree,49,49);
	tree_insert(tree,10,10);
	tree_insert(tree,8,8);
	tree_insert(tree,67,67);
	tree_insert(tree,59,59);

	tree_insert(tree,9,9);
	tree_insert(tree,13,13);
	tree_insert(tree,20,20);
	tree_insert(tree,14,14);

	tree_remove(tree,20);

	tree_print(tree);

	return 2;
}
