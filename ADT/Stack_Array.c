#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{
    int* data;
    int top;
    int size;
}Stack;

void createStack(Stack* astack, int size){
    astack->data = (int*)malloc(sizeof(int) * size);
    astack->size = size;
    astack->top = -1;
}

void makeEmpty(Stack* astack){
    astack->top = -1;
}

int isEmpty(Stack* astack){
    if(astack->top<0){
        return 1;
    }else{
        return 0;
    }
}

int isFull(Stack* astack){
    if(astack->top >= astack->size-1){
        return 1;
    }else{
        return 0;
    }
}

int top(Stack* astack){
    if(!isEmpty(astack)){
        return astack->data[astack->top];
    }else{
        return 0;
    }
}

void push(Stack* astack, int adata){
    if(!isFull(astack)){
        astack->top++;
        astack->data[astack->top] = adata;
    }
}

int pop(Stack* astack){
    if(!isEmpty(astack)){
        int adata = top(astack);
        astack->top--;
        return adata;
    }else{
        return 0;
    }
}

void disposeStack(Stack* astack){
	if(astack != NULL){
		free(astack->data);
		free(astack);
	}
}

int main(void){

    Stack* stack = malloc(sizeof(Stack));
    createStack(stack, 255);

    return 0;
}
