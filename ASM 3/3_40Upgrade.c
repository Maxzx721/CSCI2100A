#include <stdio.h>

int pointer, output[10000];

void inorder(int ans[], int i, int size){
    if(i < size){
        inorder(ans, i * 2 + 1, size);
        if(ans[i] != 0){
            output[pointer] = ans[i];
            pointer++;
        }
        inorder(ans, i* 2 + 2, size);
    }
}

int main(void){

    int N, M, i, j, value[10000];
    scanf("%d", &N);

    for(i=0; i<N; i++){
        pointer = 0;
        scanf("%d", &M);
        for(j=0; j<M; j++){
            scanf("%d", &value[j]);
        }
        inorder(value, 0, M);
        for(j=0; j<pointer-1; j++){
            printf("%d ", output[j]);
        }
        printf("%d\n", output[j]);
    }

    return 0;
}