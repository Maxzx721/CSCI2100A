#include <stdio.h>
#include <stdlib.h>

int main(void){

    int m,n,i,j;

    scanf("%d", &m);
    int max[m];

    for(i=0; i<m; i++){
        scanf("%d", &n);
        int* num = malloc(sizeof(int) * n);
        for(j=0; j<n; j++){
            scanf("%d", &num[j]);
        }
        max[i] = 0;
        for(j=0; j<n; j++){
            if(num[j] % 2 != 0){
                continue;
            } else if(num[j] > max[i]){
                max[i] = num[j];
            }
        }

        free(num);
        num = NULL;
    }

    for(i=0; i<m; i++){
        printf("%d\n", max[i]);
    }

    return 0;
}
