#include "tree.h"


/*aux methods*/
int height_node(struct node* node){
	if (node == NULL)
		return 0;
	return node->height;
}
int balancing_factor(struct node* node){
	return height_node(node->left) - height_node(node->right);
}


struct tree* create_tree(){
	return (struct tree*)malloc(sizeof(struct tree));
}

int tree_is_empty(struct tree* tree) {
	return tree->size == 0;
}

void tree_insert(struct tree* tree, void* value, int key) {

	struct node* node = (struct node*)malloc(sizeof(struct node));

	node->key = key;
	node->value = value;

	if (tree->root == NULL)
		tree->root = node;
	else {

		struct node* aux = tree->root;

		while (aux != NULL) {

			if (aux->key == key) {
				aux->value = value;
				break;
			}

			if (aux->key > key && aux->left == NULL) {
				aux->left = node;
				node->father =  aux;
				break;
			} else if (aux->key < key && aux->right == NULL) {
				aux->right = node;
				node->father =  aux;
				break;
			}

			aux = key > aux->key ? aux->right : aux->left;
		}

		tree->size++;
	}
}

struct node* get_node(struct tree* tree,int key){

	struct node* node = tree->root;

	while(node != NULL && node->key != key)
		node = key > node->key ? node->right : node->left;

	return node;
}


void* get(struct tree* tree,int key){

	struct node* node = get_node(tree,key);
	return node == NULL ? NULL : node->value;
}

void tree_remove(struct tree* tree, int key){

	struct node* node = get_node(tree,key);
	struct node* father;
	struct node* aux;

	if (node != NULL) {

		father = node->father;

		//the tree have only one element!
		if (node->left == NULL && node->right == NULL) {

			if (father->left == node)
				father->left = NULL;
			else
				father->right = NULL;

			free(node);

		}

		//the node have only one child
		else if (node->left == NULL || node->right == NULL){

			//left
			if (node->left != NULL && node->right == NULL)
				aux = node->left;

			//right
			else if (node->left == NULL && node->right != NULL)
				aux = node->right;


			if (father->left == node)
				father->left = aux;
			else
				father->right = aux;

			aux->father = father;
			free(node);

		}

		//the node have two child
		else {

			aux = node->right;

			while (aux->left != NULL)
				aux = aux->left;

			node->key = aux->key;
			node->value = aux->value;
			free(aux);

			if (aux->father->left == aux)
				aux->father->left = NULL;
			else
				aux->father->right = NULL;
		}
	}
}

void tree_print(struct tree* tree ){

	struct Queue* queue = new_queue();
	struct node* node;

	add(queue,tree->root);

	while(!isEmpity(queue)){

		node = getFirst(queue);

		if (node->left != NULL)
			add(queue,node->left);
		if (node->right != NULL)
			add(queue,node->right);

		printf("%d\n",node->key);


	}
}
