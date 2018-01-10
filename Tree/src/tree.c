#include "tree.h"


//static functions

/*
 * used for find the first
 * node in the tree
 */
static struct node* tree_frist_node(struct tree* tree) {

	struct node* node = tree->root;

	while(node->left != 0x0)
		node = node->left;

	return node;
}



/*
 * used for find the last
 * node in the tree
 */
static struct node* tree_last_node(struct tree* tree) {

	if (tree->root == 0x0)
		return 0x0;

	struct node* node = tree->root;

	while(node->right != 0x0)
		node = node->right;

	return node;
}



/*
 * used for find
 * a node by key
 */
static struct node* tree_get_node(struct tree* tree,int key){

	if (tree->root == 0x0)
		return 0x0;

	struct node* node = tree->root;

	while(node != 0x0 && node->key != key)
		node = key > node->key ? node->right : node->left;

	return node;
}


/*
 * used for remove one node
 * of tree
 */
static void* tree_remove_node(struct node* node){

	if (node == 0x0)
		return 0x0;

	struct node* father;
	struct node* aux;
	void* value = node-> value;

	father = node->father;

	//the tree have only one element!
	if (node->left == 0x0 && node->right == 0x0) {

		if (father->left == node)
			father->left = 0x0;
		else
			father->right = 0x0;

		free(node);

	}

	//the node have only one child
	else if (node->left == 0x0 || node->right == 0x0){

		//left
		if (node->left != 0x0 && node->right == 0x0)
				aux = node->left;

		//right
		else if (node->left == 0x0 && node->right != 0x0)
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

		while (aux->left != 0x0)
			aux = aux->left;

		node->key = aux->key;
		node->value = aux->value;
		free(aux);

		if (aux->father->left == aux)
			aux->father->left = 0x0;
		else
			aux->father->right = 0x0;
	}

	return value;
}


static int tree_balancing_node(struct node* node){

	if (!node)
		return 0;

	int left = node->left ? node->left->height+1 : 0;
	int right = node->right ? node->right->height+1 : 0;

	return left - right;
}

static void tree_left_rotation(struct node* node,struct tree* tree){

	struct node* rigth = node->right;

	node->right = rigth->left;

	if (rigth->left)
		rigth->left->father = node;

	rigth->left = node;
	rigth->father = node->father;
	node->father = rigth;


	if (tree->root->key == node->key) {
		tree->root = rigth;
	}

	rigth->height++;

	int left = node->left ? node->left->height : 0;
	int right = node->right ? node->right->height : 0;

	node->height = left > right ? left : right;

	node = rigth;
}


static void tree_update_height(struct node* node,struct tree* tree ,int level) {

	struct node* previous = node;


	while(node) {

		node->height = level++;

		//left rotations
		if (tree_balancing_node(node) <= -2) {

			//single
			if (tree_balancing_node(node->right) < 0)
				tree_left_rotation(node,tree);

		}

		previous = node;
		node = node->father;

	}
}
//end static functions

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

	if (tree->root == 0x0)
		tree->root = node;
	else {

		struct node* aux = tree->root;

		while (aux != 0x0) {

			if (aux->key == key) {
				aux->value = value;
				break;
			}

			if (aux->key > key && aux->left == 0x0) {
				aux->left = node;
				node->father =  aux;
				break;
			} else if (aux->key < key && aux->right == 0x0) {
				aux->right = node;
				node->father =  aux;
				break;
			}

			aux = key > aux->key ? aux->right : aux->left;
		}

		tree->size++;
		tree_update_height(node,tree,0);
	}
}

void* tree_get(struct tree* tree,int key){

	struct node* node = tree_get_node(tree,key);
	return node == 0x0 ? 0x0 : node->value;
}

void* tree_remove(struct tree* tree, int key){
	return tree_remove_node(tree_get_node(tree,key));
}

void tree_print(struct tree* tree ){

	struct Queue* queue = new_queue();
	struct node* node;

	add(queue,tree->root);

	while(!isEmpity(queue)){

		node = getFirst(queue);

		if (node->left != 0x0)
			add(queue,node->left);
		if (node->right != 0x0)
			add(queue,node->right);

		printf("%s ","{");

		printf("key: %d  - ",node->key);

		if (node->father) {

			if (node->father->left)
				printf("child left: %d ",node->father->key);
			else
				printf("child rigth: %d ",node->father->key);
		} else
			printf("root node - ");

		printf("height: %d ",node->height);
		printf(" bf: %d ",tree_balancing_node(node));

		printf("%s\n","}");


	}
}

void* tree_first(struct tree* tree) {

	if (tree->root == 0x0)
		return 0x0;

	return tree_frist_node(tree)->value;
}


void* tree_remove_first(struct tree* tree){

	if (tree->root == 0x0)
		return 0x0;

	return tree_remove_node(tree_frist_node(tree));

}

void* tree_last(struct tree* tree) {

	if (tree->root == 0x0)
		return 0x0;

	return tree_last_node(tree)->value;
}

void* tree_remove_last(struct tree* tree) {

	if (tree->root == 0x0)
		return 0x0;

	return tree_remove_node(tree_last_node(tree));
}
