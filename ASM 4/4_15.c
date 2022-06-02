#include <stdio.h>

int main(void){

    int N, n, k, i, j ,l;
    scanf("%d", &N);

    for(i=0; i<N; i++){
        scanf("%d %d", &n, &k);
        int num[n][n];
        for(j=0; j<n; j++){
            for(l=0; l<n; l++){
                scanf("%d", &num[j][l]);
            }
        }
        int S = num[0][0], L = num[n-1][n-1], M, C;
        
        while(S < L){
            M = (S + L) / 2;
            l = n - 1;
            C = 0;
            for(j=0; j<n; j++){
                while(l >= 0 && num[j][l] > M){
                    l--;
                }
                C += l + 1;
            }
            if(C < k){
                S = M + 1;
            }else{
                L = M;
            }
        }
        printf("%d\n", L);
    }
    return 0;
}
