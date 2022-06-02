#include <stdio.h>
#include <stdlib.h>

int ans;

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

int painter(Node* node){
    if(node == NULL || node->data == 0){
        return 1;
    }
    int L = painter(node->leftChild);
    int R = painter(node->rightChild);

    if(L == 1 && R == 1){
        return 2;
    }else if(L == 2 || R == 2) {
        ans++;
        return 3;
    }

    return 1;
}

void minPainter(Node* node){
    int value = painter(node), yn;

    if(value == 2){
        yn = 1;
    }else{
        yn = 0;
    }
    printf("%d\n", ans + yn);
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

    int N, M, i, j, value[10000];
    scanf("%d", &N);
    Node* tree;

    for(i=0; i<N; i++){
        scanf("%d", &M);
        for(j=0; j<M; j++){
            scanf("%d", &value[j]);
        }
        ans = 0;
        tree = insert(tree, value, 0, M);
        minPainter(tree);
        deleteTree(tree);
        tree = NULL;
    }

    return 0;
}
