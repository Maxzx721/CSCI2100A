#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* leftChild;
    struct Node* rightChild;
}Node;

Node* makeEmpty(Node* tree){
	if(tree != NULL){
		makeEmpty(tree->leftChild);
		makeEmpty(tree->rightChild);
		free(tree);
	}
	return NULL;
}

Node* find(int value, Node* tree){
	if(tree == NULL)
		return NULL;
	if(value < tree->data)
		return find(value, tree->leftChild);
	else if(value > tree->data)
		return find(value, tree->rightChild);
	else
		return tree;
}

Node* findMin(Node* tree){
	if(tree == NULL)
		return NULL;
	else if(tree->leftChild == NULL)
		return tree;
	else
		return findMin(tree->leftChild);
}

Node* findMax(Node* tree){
	if(tree != NULL)
	while(tree->rightChild != NULL)
		tree = tree->rightChild;

	return tree;
}

Node* insert(int value, Node* tree){
	if(tree == NULL){
		tree = malloc(sizeof(Node));
		if(tree == NULL)
			printf("Out of space!!!");
		else{
			tree->data = value;
			tree->leftChild = tree->rightChild = NULL;
		}
	}
	else if(value < tree->data)
		tree->leftChild = insert(value, tree->leftChild);
	else if(value > tree->data)
		tree->rightChild = insert(value, tree->rightChild);

	return tree;
}

Node* Delete(int value, Node* tree){
	Node* TmpCell;

	if(tree == NULL)
		printf("Element not found");
	else if(value < tree->data)
		tree->leftChild = Delete(value, tree->leftChild);
	else if(value > tree->data)
		tree->rightChild = Delete(value, tree->rightChild);
	else if(tree->leftChild && tree->rightChild){
		TmpCell = findMin(tree->rightChild);
		tree->data = TmpCell->data;
		tree->rightChild = Delete(tree->data, tree->rightChild);
	}
	else {
		TmpCell = tree;
		if(tree->leftChild == NULL)
			tree = tree->rightChild;
		else if(tree->rightChild == NULL)
			tree = tree->leftChild;
		free(TmpCell);
	}

	return tree;
}

int Retrieve(Node* tree){
	return tree->data;
}

int main(void){

    Node* tree;
	Node* position;
	int i;

    tree = makeEmpty(NULL);
	tree= insert(10, tree);
	position =find(10, tree); 	// locate the desire location like(find function)
	i = Retrieve(position);		// take the value of location "position" to i
	tree = Delete(10, tree);	//delete value 10
	makeEmpty(tree);

    return 0;
}
