#include <stdio.h>
#include <stdlib.h>

#define HASHTABLESIZE 167

typedef struct Hash{
    int key[HASHTABLESIZE];
    int state[HASHTABLESIZE];
}Hash;

int hash(int input){
    return input % HASHTABLESIZE;
}

int h(int k, int input){
    return (hash(input) + k) % HASHTABLESIZE;
}

void init(Hash* hashTable){
    for(int i=0; i<HASHTABLESIZE; i++){
        hashTable->key[i] = -1;
        hashTable->state[i] = 0;
    }
}

void closedHashingInsert(int item, Hash* hashTable){
    int i = hash(item);
    int k = 1;
    while(hashTable->state[i] == 1){
        i = h(k++, item);
    }
    hashTable->key[i] = item;
    hashTable->state[i] = 1;
}

int findValue(int item, Hash* hashTable){
    int i = hash(item);
    int k = 1;
    if(hashTable->state[i] == 0){
        return 0;
    }
    while(hashTable->key[i] != item){
        if(hashTable->state[i] == 0){
            return 0;
        }
        i = h(k++, item);
    }
        return 1;
}

int main(void){

    int N, m, num;
    scanf("%d", &N);

    for(int i=0; i<N; i++){
        long long int n, l = 0, isZero = 0, input[1000], counter = 0;
        
        Hash* hashTable = malloc(sizeof(Hash));
        init(hashTable);
        scanf("%lld %d", &n, &m);
        for(int j=0; j<n; j++){
            scanf("%d", &num);
            if(!num){
                isZero = 1;
                continue;
            }
            if(!m || (num && m % num)){
                continue;
            }
            input[l] = num;
            l++;
            closedHashingInsert(num, hashTable);
        }

        if(!m){
            if(isZero){
                printf("%lld\n", (n - 1) * (n - 2) / 2);
            }else{
                printf("%d\n", 0);
            }
            free(hashTable);
            continue;
        }

        n = l;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                long long int p = input[i] * input[j];
                long long int check = m / p;
                if((m % p == 0) && (check != input[i]) && (check != input[j]) && (findValue(check, hashTable) == 1)){
                    counter++;
                }
            }
        }
        if(m != 0){
            printf("%lld\n", counter / 3);
        }else{
            printf("%lld\n", counter);
        }
        free(hashTable);
    }

    return 0;
}
