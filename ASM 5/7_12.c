#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{
    int data;
    struct NODE* prev;
    struct NODE* next;
}node;

typedef struct QUEUE{
    node* head;
    node* tail;
}queue;

node* newNode(int data){
    node* p = malloc(sizeof(node));
    p->data = data;
    p->prev = NULL;
    p->next = NULL;
    return p;
}

queue* newQueue(void){
    queue *p = malloc(sizeof(queue));
    p->head = NULL;
    p->tail = NULL;
    return p;
}

int isEmpty(queue* p){
    return !(p->head) ? 1 : 0;
}

int top(queue* p){
    return p->head->data;
}

int enqueue(queue* p, int data){
    node* tmp = newNode(data);
    if(!(p->head)){
        p->head = tmp;
        p->tail = tmp;
        return 1;
    }
    p->tail->next = tmp;
    tmp->prev = p->tail;
    p->tail = tmp;
    return 1;
}

int dequeue(queue* p){
    int tmp = p->head->data;
    if (p->head == p->tail) {
        free(p->head);
        p->head = NULL;
        p->tail = NULL;
    }
    else {
        node* tmpNode= p->head;
        p->head = tmpNode->next;
        free(tmpNode);
    }
    return tmp;
}

int** build(int n){
    int a, b;
    int** arr = (int**)malloc(sizeof(int*)*n);
    for(int i=0;i<n;i++)
        arr[i]=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            arr[i][j] = 0; 
    for(;;){
        scanf("%d",&a);
        if(a == -1) 
            return arr;
        scanf("%d",&b);
        arr[b-1][a-1] = arr[a-1][b-1]=1;
    }   
}

int dye(int** G, int* color, int n, int pos){
    color[pos] = 1;
    queue *p = newQueue();
    enqueue(p, pos);
    while(!isEmpty(p)){
        int u = dequeue(p);
        for(int v=0; v<n; ++v){
            if(G[u][v] && color[v] == -1){
                color[v] = 1 - color[u];
                enqueue(p,v);
            }else if(G[u][v] && color[v] == color[u])
                return 0;
        }
    }
    return 1;
}

int solve(){
    int n;
    scanf("%d",&n);
    int** p = build(n);
    int color[n];
    for(int i=0;i<n;++i)
        color[i] = -1;
    for(int i=0;i<n; i++)
        if(color[i]==-1)
            if(!dye(p,color,n,i)) return 0;
    return 1;
}

int main(void){
    int n;
    scanf("%d",&n);
    while(n--)
        solve() ? printf("YES\n") : printf("NO\n");

    return 0;
}
