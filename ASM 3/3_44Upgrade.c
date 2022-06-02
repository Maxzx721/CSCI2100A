#include <stdio.h>
#include <stdlib.h>

int output[10000], count = 0;

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

Node* insert(int pre[], int post[], int* preIndex, int li, int hi, int size){
    
    if (*preIndex >= size || li > hi)
        return NULL;
 
    Node* root = newNode( pre[*preIndex] );
    ++*preIndex;

    if (li == hi){
        return root;
    }
    
    int i;
    for (i = li; i <= hi; ++i){
        if (pre[*preIndex] == post[i]){
            break;
        }

    }

    if (i <= hi){
        root->leftChild = insert(pre, post, preIndex, li, i, size);
        root->rightChild = insert(pre, post, preIndex, i + 1, hi - 1, size);
    }
 
    return root;
}

void inorder(Node* node){
    if(node != NULL){
        inorder(node->leftChild);
        output[count] = node->data;
        count++;
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
    int N, M, i, j, pointer = 0, pre[10000], post[10000];
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
        count = 0;
        tree = insert(pre, post, &pointer, 0, M - 1, M);
        inorder(tree);
        for(j=0; j<pointer-1; j++){
            printf("%d ", output[j]);
        }
        printf("%d\n", output[j]);
        deleteTree(tree);
        tree = NULL;
    }
 
    return 0;
}