#include <stdio.h>
#include <stdlib.h>

int main(void){

    int loop, i, j;

    scanf("%d\n", &loop);
    char** c = malloc(sizeof(char*) * loop);

    for(int i=0; i<loop; i++){
        c[i] = malloc(sizeof(char) * 256);
        gets(c[i]);
    }

    for(i=0; i<loop; i++){

        int start = 0, end = 0;
        char temp;
 
        while(c[i][end] !=  '\0'){
            if(c[i][end] == ' '){
                int l = (end - start) / 2;
                for(j=0; j<l; j++) {
                    temp = c[i][start+j];
                    c[i][start+j] = c[i][end-1-j];
                    c[i][end-1-j] = temp;
                }
                start = end + 1;
                end++;
                continue;
            } else if(c[i][end+1] == '\0'){
                int l = (end + 1 - start) / 2;
                for(j=0; j<l; j++) {
                    temp = c[i][start+j];
                    c[i][start+j] = c[i][end-j];
                    c[i][end-j] = temp;
                }
            }
            end++;
        }
            printf("%s\n", c[i]);
    }
        
    for(i=0; i<loop; i++){
        free(c[i]);
        c[i] = NULL;
    }

    free(c);
    c = NULL;

    return 0;

}
