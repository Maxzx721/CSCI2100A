#include <stdio.h>
#include <stdlib.h>

#define HASHTABLESIZE 1000

typedef struct Hash{
    int key[HASHTABLESIZE];
    int state[HASHTABLESIZE];
    /* -1=lazy delete, 0=empty, 1=occupied */
}Hash;

int hash(int input){
    return input % HASHTABLESIZE;
}

int h(int k, int input){
    return (hash(input) + k) % HASHTABLESIZE; //linear hashing
}

void init(Hash* hashTable){
    for(int i=0; i<HASHTABLESIZE; i++){
        hashTable->key[i] = -1; //assume value >= 0
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

    int num;

    Hash* hashTable = malloc(sizeof(Hash));
    init(hashTable);

    closedHashingInsert(num, hashTable);
    free(hashTable);

    return 0;
}
