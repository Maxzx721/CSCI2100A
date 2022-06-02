#include <stdio.h>
#include <math.h>

int main(void){

    int loop, count;

    scanf("%d", &loop);
    unsigned int numbers[loop*2], ans;

    for(int i=0; i<loop; i++){
        scanf("%u %u", &numbers[i+i], &numbers[i+i+1]);
    }

    for(int i=0; i<loop; i++){
    
        ans = numbers[i+i+1];
        count = 0;
        
        while(numbers[i+i+1] != 0){
            numbers[i+i+1] = numbers[i+i+1] / 2;
            count++;
        }
        
        while(numbers[i+i] != 0){
            ans += (unsigned int) ((numbers[i+i] % 2) * pow(2, count));
            numbers[i+i] = numbers[i+i] / 2;
            count++;
        }

    printf("%u\n", ans);

    }

    return 0;

}
