#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{
    int *data;
    int top;
    int size;
}Stack;

void createStack(Stack* astack, int size){
    astack->data = (int*)malloc(sizeof(int) * size);
    astack->size = size;
    astack->top = -1;
}

void makeEmpty(Stack* astack){
    astack->top = -1;
}

int isEmpty(Stack* astack){
    if(astack->top<0){
        return 1;
    }else{
        return 0;
    }
}

int isFull(Stack* astack){
    if(astack->top >= astack->size-1){
        return 1;
    }else{
        return 0;
    }
}

int top(Stack* astack){
    if(!isEmpty(astack)){
        return astack->data[astack->top];
    }else{
        return 0;
    }
}

void push(Stack* astack, int adata){
    if(!isFull(astack)){
        astack->top++;
        astack->data[astack->top] = adata;
    }
}

int pop(Stack* astack){
    if(!isEmpty(astack)){
        int adata = top(astack);
        astack->top--;
        return adata;
    }else{
        return 0;
    }
}

int factorial(int f){
    if(f <= 1){
        return 1;
    }else{
        return f * factorial(f-1);
    }
}

int calculate(int t1, int t2, char x){
    if(x == '+'){
        return t2 + t1;
    }else if(x == '-'){
        return t2 - t1;
    }else if(x == '*'){
        return t2 * t1;
    }else if(x == '/'){
        return t2 / t1;
    }else if(x == '!'){
        return factorial(t1);
    }
}

int main(void){

    int c, steps, i, j, k, temp1, temp2;
    Stack* stack = malloc(sizeof(Stack));
    createStack(stack, 255);

    scanf("%d\n", &c);
    int ans[c], error[c];
    char ex[256];

    for(i=0; i<c; i++){
        fgets(ex, 256, stdin);
        for(j=0; j<255; j++){
            if(ex[j] == '\0' || ex[j] == '\n'){
                ans[i] = pop(stack);
                makeEmpty(stack);
                break;
            }else if(ex[j] == ' '){
                continue;
            }else if(atoi(ex) != 0 || ex[j] == '0'){
                while(ex[j] != ' '){
                    j++;
                }
                j--;
                push(stack, atoi(ex));
                for(k=0; k<=j; k++){
                    ex[k] = ' ';
                }
            }else if(ex[j] == '!'){
                temp1 = pop(stack);
                temp2 = 0;
                if(temp1 < 0){
                    error[i] = 1;
                    break;
                }
                steps = calculate(temp1, temp2, ex[j]);
                push(stack, steps);
                for(k=0; k<=j; k++){
                    ex[k] = ' ';
                }
            }else if(ex[j] == '/'){
                temp1 = pop(stack);
                temp2 = pop(stack);
                if(temp1 == 0){
                    error[i] = 2;
                    break;
                }
                steps = calculate(temp1, temp2, ex[j]);
                push(stack, steps);
                for(k=0; k<=j; k++){
                    ex[k] = ' ';
                }
            }else{
                temp1 = pop(stack);
                temp2 = pop(stack);
                steps = calculate(temp1, temp2, ex[j]);
                push(stack, steps);
                for(k=0; k<=j; k++){
                    ex[k] = ' ';
                }
            }
        }
    }
    
    free(stack->data);

    for(i=0; i<c; i++){
        if(error[i] == 1){
            printf("factorial of an negative number\n");
        }else if(error[i] == 2){
            printf("division by zero\n");
        }else{
            printf("%d\n", ans[i]);
        }
    }

    return 0;
}
