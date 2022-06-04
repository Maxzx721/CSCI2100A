#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
}Node;

Node* createList(){
    Node* emptyList;
    emptyList = (Node*) malloc(sizeof(Node));
    emptyList->next = NULL;
    return emptyList;
}

void insertEnd(int value, Node* L){
    Node* newnode = (Node*) malloc(sizeof(Node));
    Node* temp = L;
    newnode->data = value;
    newnode->next = NULL;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = newnode;
}

void deleteList(Node* L){
    if(Node == NULL)
        return;
    deleteList(L->next);
    free(L);
}

int main(void){

    Node* L = createList();

    return 0;
}
