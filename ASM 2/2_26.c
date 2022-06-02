#include <stdio.h>
#include <stdlib.h>

typedef struct Queue{
    int *data;
    int head;
    int tail;
    int num;
    int size;
}Queue;

void createQueue(Queue* aqueue, int size){
    aqueue->data = (int*)malloc(sizeof(int) * size);
    aqueue->head = 0;
    aqueue->tail = -1;
    aqueue->num = 0;
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

void makeEmpty(Queue* aqueue){
    aqueue->head = 0;
    aqueue->tail = -1;
    aqueue->num = 0;
}

int main(void){

    int N, i, j, steps;
    char input[4];
    Queue* queue = malloc(sizeof(Queue));
    createQueue(queue, 1000);

    scanf("%d\n", &N);
    char ans[N][1001];

    for(i=0; i<N; i++){
        fgets(input, 4, stdin);
        if(input[0] == 'S'){
            while(input[0] != 'X'){
                fgets(input, 4, stdin);
                if(input[0] == 'D'){
                    dequeue(queue);
                }else if(input[0] == 'E'){
                    input[0] = ' ';
                    enqueue(queue, atoi(input));
                }
            }
        }
        j = 0;
        while(isEmpty(queue) == 0){
            steps = dequeue(queue);
            if(steps == 0){
                ans[i][j] = '0';
            }else if(steps == 1){
                ans[i][j] = '1';
            }
            j++;
        }
        ans[i][j] = '\0';
        makeEmpty(queue);
    }

    free(queue->data);

    for(i=0; i<N; i++){
        printf("%s\n", ans[i]);
    }

    return 0;
}