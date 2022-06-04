#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* leftChild;
    struct Node* rightChild;
}Node;

Node* newNode(int value){
    Node* node = malloc(sizeof(Node));
    node->data = value;
    node->leftChild = NULL;
    node->rightChild = NULL;
    return node;
}

Node* insert(Node* root, int value[], int i, int size){
    if(i < size){
        Node* temp = newNode(value[i]);
        root = temp;
        root->leftChild = insert(root->leftChild, value, i * 2 + 1, size);
        root->rightChild = insert(root->rightChild, value, i* 2 + 2, size);
    }
    return root;
}

void deleteTree(Node* node){
    if (node == NULL) {
        return;
    }
    deleteTree(node->leftChild);
    deleteTree(node->rightChild);
    free(node);
}

void preorder(Node* node) {
    if(node != NULL){
    printf("%d ", node->element); /* V */
    preorder(node->leftChild); /* L */
    preorder(node->rightChild); /* R */
    }
}

void inorder(Node* node){
    if(node != NULL){
        inorder(node->leftChild);
        if(node->data != 0){
            printf("%d ", node->data);
        }
        inorder(node->rightChild);
    }
}

void postorder(Node* node) {
    if(node != NULL){
    postorder(node->leftChild); /* L */
    postorder(node->rightChild); /* R */
    printf("%d ", node->element); /* V */
    }
}

int main(void){
    Node* tree = NULL;

    scanf("%d", &M);
        for(j=0; j<M; j++){
            scanf("%d", &value[j]);
        }
        tree = insert(tree, value, 0, M);

    return 0;
}
