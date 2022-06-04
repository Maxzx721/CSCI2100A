#include <stdio.h>
#include <stdlib.h>

typedef struct Heap{
    int capacity;
    int size;
    int* elements;
}Heap;

void createHeap(Heap* heap, int size, int capacity){
    heap->elements = malloc(sizeof(int) * capacity);
    heap->size = size;
    heap->capacity = capacity;
}

int HEAP_FULL(Heap* heap){
    if(heap->size == heap->capacity)
        return 1;
    else
        return 0;
}

int HEAP_EMPTY(Heap* heap){
    if(heap->size == 0)
        return 1;
    else
        return 0;
}

void insertHeap(Heap* heap, int item){
    int i;
    if (HEAP_FULL(heap)) {
        printf("The heap is full.\n");
        exit(1);
    }
    i = heap->size;
    while ((i != 0) && (item < heap->elements[(i-1)/2]) ){
        heap->elements[i] = heap->elements[(i-1)/2];
        i = (i-1)/2;
    }
    heap->elements[i]=item;
    heap->size++;
}

int deleteMin(Heap* heap){
    int parent, child, item, temp;;
    if (HEAP_EMPTY(heap)){
        printf("The heap is empty\n");
        exit(1);
    }
    item = heap->elements[0];
    temp = heap->elements[heap->size - 1];
    heap->size--;
    parent = 0;
    child = 1;
    while (child <= (heap->size - 1)){
        if ((child < (heap->size - 1)) && (heap->elements[child] > heap->elements[child+1]))
            child++;
        if (temp <= heap->elements[child]) 
            break;
        heap->elements[parent] = heap->elements[child];
        parent = child;
        child = 2 * child + 1;
    }
    heap->elements[parent] = temp;
    return item;
}

void destroyHeap(Heap* heap){
    free(heap->elements);
	free(heap);
}

int main(void){
    int x, k, temp[1000];
    char L;
    Heap* heap = malloc(sizeof(Heap));
    createHeap(heap, 0, 1000000);       //0 is a must, 1000000 is the size of the heap

    scanf("%d", &x);
    insertHeap(heap, x);

    for(int i=0; i<k-1; i++){
        temp[i] = deleteMin(heap);
    }
    printf("%d\n",heap->elements[0]);
    for(int i=k-2; i>=0; i--){
        insertHeap(heap, temp[i]);
    }
    destroyHeap(heap);

    return 0;
}
