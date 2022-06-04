#include <stdio.h>
#include <stdlib.h>

typedef struct node_s{
    int data;
    struct node_s* next;
}node;

int is_empty(node* stack){
    return (stack->next == NULL);
}

int pop(node* stack){
    int temp;
    node* toBePopped;
    if(!is_empty(stack)){
        temp = stack->next->data;
        toBePopped = stack->next;
        stack->next = stack->next->next;
        free(toBePopped);
        return temp;
    }
    else
        return 0; 
}

void makeEmpty(node* stack){
	if(stack == NULL)
		printf("Must use CreateStack first");
	else
		while(!is_empty(stack))
			pop(stack);
}

node* create_stack(){
    node* emptyStack;
    emptyStack = (node*) malloc(sizeof(node));
    emptyStack->next = NULL;
    makeEmpty(emptyStack);
    return emptyStack;
}

void push(int inputdata, node* stack){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = inputdata;
    newnode->next = stack->next;
    stack->next = newnode; 
}

int top(node* stack){
    if(!is_empty(stack))
        return stack->next->data;
    else
        return 0;
}

void disposeStack(node* stack){
	makeEmpty(stack);
	free(stack);
}

int main(void){

    node* S = create_stack();

    return 0;
}
