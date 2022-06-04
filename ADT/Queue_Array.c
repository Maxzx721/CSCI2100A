#include <stdio.h>
#include <stdlib.h>

typedef struct Queue{
    int *data;
    int head;
    int tail;
    int num;
    int size;
}Queue;

void makeEmpty(Queue* aqueue){
    aqueue->head = 0;
    aqueue->tail = -1;
    aqueue->num = 0;
}

void createQueue(Queue* aqueue, int size){
    aqueue->data = (int*)malloc(sizeof(int) * size);
    makeEmpty(aqueue);
    aqueue->size = size;
}

void enqueue(Queue* aqueue, int adata){
    aqueue->tail = (aqueue->tail + 1) % aqueue->size;
    aqueue->data[aqueue->tail] = adata;
    aqueue->num++;
}

int dequeue(Queue* aqueue){
    if(aqueue->num > 0){
        int adata = aqueue->data[aqueue->head];
        aqueue->head = (aqueue->head + 1) % aqueue->size;
        aqueue->num--;
        return adata;
    }else{
        return 0;
    }
}

int isEmpty(Queue* aqueue){
    return (aqueue->num == 0);
}

int isFull(Queue* aqueue){
    return (aqueue->num == aqueue->size);
}

int front(Queue* aqueue){
    return aqueue->data[aqueue->head];
}

void disposeQueue(Queue* aqueue){
	if(aqueue != NULL){
		free(aqueue->data);
		free(aqueue);
	}
}

int main(void){

    Queue* queue = malloc(sizeof(Queue));
    createQueue(queue, 255);

    return 0;
}
