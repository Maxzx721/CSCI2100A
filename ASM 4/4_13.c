#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct HeapStruct {
    int capacity;
    int size;
    int *elements;
};typedef struct HeapStruct Heap;

int HEAP_FULL(Heap* h){
    if(h->size == h->capacity)
        return 1;
    else
        return 0;
}

int HEAP_EMPTY(Heap* h){
    if(h->size == 0)
        return 1;
    else
        return 0;
}

void createHeap(Heap* h, int size, int capacity){
    h->elements = (int*)malloc(sizeof(int)*capacity);
    h->size=size;
    h->capacity=capacity;
}

void insertHeap(Heap *h, int item){

    int i;
    if (HEAP_FULL(h)) {
    printf("The heap is full.\n");
    exit(1);
    }

    i = h->size;
    while ( (i!=0) && (item < h->elements[(i-1)/2]) ){
    h->elements[i] = h->elements[(i-1)/2];
    i = (i-1)/2;
    }

    h->elements[i]=item;
    h->size++;
}

int deleteHeap(Heap *h){
    int parent, child;
    int item, temp;
    if (HEAP_EMPTY(h)){
    printf("The heap is empty\n");
    exit(1);
}
    item = h->elements[0];
    temp = h->elements[h->size - 1];
    h->size--;
    parent = 0;
    child = 1;
    while (child <= (h->size - 1)){
        if ( (child < (h->size - 1)) && (h->elements[child] > h->elements[child+1] ) )
            child++;
        if (temp<=h->elements[child]) 
            break;
        h->elements[parent] = h->elements[child];
        parent = child;
        child = 2*child + 1;
    }
    h->elements[parent] = temp;
    return item;
}

int main(void){

    int x, k, temp[1000];
    char L;
    Heap* heap = malloc(sizeof(Heap));
    createHeap(heap,0,1000000);

    scanf("%d", &k);
    while(L != 'S'){
        scanf("%c", &L);
        if(L == 'I'){
            scanf("%d", &x);
            insertHeap(heap, x);
        }else if(L == 'O'){
            for(int i=0; i<k-1; i++){
                temp[i] = deleteHeap(heap);
            }
            printf("%d\n",heap->elements[0]);
            for(int i=k-2; i>=0; i--){
                insertHeap(heap, temp[i]);
            }
        }
    }
    free(heap);

    return 0;
}
