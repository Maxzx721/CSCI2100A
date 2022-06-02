#include <stdio.h>
#include <stdlib.h>

int main(void){
    int N;
    scanf("%d", &N);

    for(int i=0; i<N; i++){
        int m, n;
        scanf("%d %d", &m, &n);
        int *array1 = malloc(sizeof(int) * m), *array2 = malloc(sizeof(int) * n), *ans = malloc(sizeof(int) * (m + n));
        for(int j=0; j<m; j++){
            scanf("%d", &array1[j]);
        }
        for(int j=0; j<n; j++){
            scanf("%d", &array2[j]);
        }
        int j = m - 1, k = n - 1, l = m + n;
        while(l > 0)
            ans[--l] = (k < 0 || (j >= 0 && array1[j] >= array2[k])) ? array1[j--] : array2[k--];
        if((m + n) % 2 == 0){
            double num = (double) (ans[(m+n)/2-1] + ans[(m+n)/2]) / 2.0;
            printf("%.1f\n", num);
        }else{
            printf("%.1f\n", (double) ans[(m+n)/2]);
        }
        free(array1);
        free(array2);
        free(ans);
    }

    return 0;
}
