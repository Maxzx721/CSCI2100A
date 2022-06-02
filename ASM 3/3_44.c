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

Node* insert(Node* root, int pre[], int post[], int* i, int size, int j, int k){
    if(*i >= size){
        return NULL;
    }
    Node* temp = newNode(pre[*i]);
    root = temp;
    j = 0;
    k = 0;
    while(post[j] != pre[*i]){
        j++;
    }
    while(post[k] != pre[*i+1]){
        k++;
    }
    ++*i;
    if(k < j){
        root->leftChild = insert(root->leftChild, pre, post, i, size, j, k);
        root->rightChild = insert(root->rightChild, pre, post, i, size, j, k);
    }
    return root;
}

void inorder(Node* node){
    if(node != NULL){
        inorder(node->leftChild);
        printf("%d ", node->data);
        inorder(node->rightChild);
    }
}

void deleteTree(Node* node){
    if (node == NULL) {
        return;
    }
    deleteTree(node->leftChild);
    deleteTree(node->rightChild);
    free(node);
}

int main(void){

    int N, M, i, j, pointer, pre[10000], post[10000];
    scanf("%d", &N);
    Node* tree = NULL;

    for(i=0; i<N; i++){
        scanf("%d", &M);
        for(j=0; j<M; j++){
            scanf("%d", &pre[j]);
        }
        for(j=0; j<M; j++){
            scanf("%d", &post[j]);
        }
        pointer = 0;
        tree = insert(tree, pre, post, &pointer, M, M-1, 0);
        inorder(tree);
        printf("\n");
        deleteTree(tree);
        tree = NULL;
    }

    return 0;
}