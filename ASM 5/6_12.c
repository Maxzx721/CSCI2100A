#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    int M;
    scanf("%d", &M);

    for(int i=0; i<M; i++){
        int N;
        char temp[2], arr[1000][3]={"\0"};;
        scanf("%d", &N);
        for(int j=0; j<N; j++){
            scanf("%s", arr[j]);
        }
        for(int j=0; j<N; j++){
            for(int k=j+1; k<N; k++){
                if(arr[j][0]>arr[k][0]){
                    strcpy(temp, arr[j]);
                    strcpy(arr[j], arr[k]);
                    strcpy(arr[k], temp);
                }
                if(arr[j][0]==arr[k][0]){
                    if((arr[j][1]=='\0')&&(arr[k][1]=='\0'))
                        continue;
                    else if(arr[j][1]=='\0'){
                        if(arr[j][0]>arr[k][1]){
                            strcpy(temp, arr[j]);
                            strcpy(arr[j], arr[k]);
                            strcpy(arr[k], temp);
                        }
                    }
                    else if(arr[k][1]=='\0'){
                        if(arr[k][0]<arr[j][1]){
                            strcpy(temp, arr[j]);
                            strcpy(arr[j], arr[k]);
                            strcpy(arr[k], temp);
                        } 
                    }
                    else if(arr[j][1]>arr[k][1]){
                        strcpy(temp, arr[j]);
                        strcpy(arr[j], arr[k]);
                        strcpy(arr[k], temp);
                    }     
                }
            }
        }
        for(int j=0; j<N; j++){
            printf("%s", arr[j]);
        }
        printf("\n");
    }

    return 0;
}
