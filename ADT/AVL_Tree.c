#include <stdio.h>
#include <stdlib.h>

typedef struct AVLnode_s{
    int data;
    int height;
    struct AVLnode_s* left;
    struct AVLnode_s* right;
}AVLnode;

AVLnode* makeEmpty(AVLnode* node){
    if(node == NULL){
        return NULL;
    }
    makeEmpty(node->left);
    makeEmpty(node->right);
    free(node);
}

AVLnode* find(int value, AVLnode* tree){
	if(tree == NULL) return NULL;
	if(value < tree->data) return find(value, tree->left);
	else if(value > tree->data) return find(value, tree->right);
	else return tree;
}

AVLnode* findMin(AVLnode* tree){
	if(tree == NULL) return NULL;
	else if(tree->left == NULL) return tree;
	else return findMin(tree->left);
}

AVLnode* findMax(AVLnode* tree){
	if(tree != NULL)
		while(tree->right != NULL)
			tree = tree->right;

	return tree;
}

static int height(AVLnode* node){
    if(node == NULL)
        return -1;
    else return node->height;
}

int max(int a, int b){
    return (a > b) ? a : b;
}

static AVLnode* SingleRotateWithLeft(AVLnode* K2){
	AVLnode* K1;

	K1 = K2->left;
	K2->left = K1->right;
	K1->right = K2;

	K2->height = max(height( K2->left), height( K2->right)) + 1;
	K1->height = max(height( K1->left), K2->height) + 1;

	return K1;
}

static AVLnode* SingleRotateWithRight(AVLnode* K1){
	AVLnode* K2;

	K2 = K1->right;
	K1->right = K2->left;
	K2->left = K1;

	K1->height = max( height(K1->left), height( K1->right)) + 1;
	K2->height = max( height(K2->right), K1->height) + 1;

	return K2;
}

static AVLnode* DoubleRotateWithLeft(AVLnode* K3){
	K3->left = SingleRotateWithRight(K3->left);

	return SingleRotateWithLeft(K3);
}

static AVLnode* DoubleRotateWithRight(AVLnode* K1){
	K1->right = SingleRotateWithLeft(K1->right);

	return SingleRotateWithRight(K1);
}

AVLnode* Insert(int value, AVLnode* tree){
	if(tree == NULL){
		tree = malloc(sizeof(AVLnode));
		if(tree == NULL)
			printf("Out of space!!!");
		else{
			tree->data = value; tree->height = 0;
			tree->left = tree->right = NULL;
		}
	}
	else if(value < tree->data){
		tree->left = Insert(value, tree->left);
		if(height(tree->left) - height(tree->right) == 2)
			if(value < tree->left->data)
				tree = SingleRotateWithLeft(tree);
			else
				tree = DoubleRotateWithLeft(tree);
	}
	else if(value > tree->data){
		tree->right = Insert(value, tree->right);
		if(height(tree->right) - height(tree->left) == 2)
			if(value > tree->right->data)
				tree = SingleRotateWithRight(tree);
			else
				tree = DoubleRotateWithRight(tree);
	}

	tree->height = max(height(tree->left), height(tree->right)) + 1;
	return tree;
}

AVLnode* deleteNode(int key, AVLnode* root){
	printf( "Sorry; Delete is unimplemented; %d remains\n", key);
	return root;
}

int Retrieve(AVLnode* tree){
	return tree->data;
}

int main(void){

    AVLnode* tree;			//example.
	AVLnode* position;
    tree = makeEmpty(NULL);
	tree = Insert(10, tree);
	position = find(10, tree);
	int i = Retrieve(position);

    makeEmpty(tree);

    return 0;
}
