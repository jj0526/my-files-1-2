#include <stdio.h>
#include <string.h>

int stack[20];
int top = -1;

int calculate(char expression[], int size);
int is_digit(char digit);
void pop();
void push(char exp);

int main(){
    char expression[20] = "234*2*+";

    //scanf(" %s", expression);

    printf("%s\n", expression);

    int res = calculate(expression, strlen(expression));
    for (int i = 0; i<10; i++){
        printf("%d ", stack[i]);
    }
    printf("\n%d", stack[0]);

    return 0;
}

int calculate(char expression[], int size){
    for (int i = 0; i<size; i++){
        printf("char : %c\n", expression[i]);
        if(is_digit(expression[i])==-1){
            printf(" %c is not digit\n", expression[i]);
            return -1;  //failed
        }
        else if(is_digit(expression[i])==1){
            top++;
            push(expression[i]);
            for (int i = 0; i<10; i++){
            printf("%d ", stack[i]);
            }
        }
        else{
            if(expression[i]=='*'){
                stack[top-1] = stack[top-1] * (stack[top]);
            }
            else if(expression[i]=='/'){
                stack[top-1] = stack[top-1] / stack[top];
            }
            else if(expression[i]=='+'){
                stack[top-1] = stack[top-1] + stack[top];
            }
            else if(expression[i]=='-'){
                stack[top-1] = stack[top-1] - stack[top];
            }
            printf("stack[top-1] : %c stack[top] : %c");
            pop();
            for (int i = 0; i<10; i++){
            printf("%d ", stack[i]);
            }
            
        }
        for (int i = 0; i<10; i++){
            printf("%d ", stack[i]);
        }
    }
    return 0; //success
}

int is_digit(char digit){
    printf("check : %c\n", digit);
    if ('0'<=digit && digit<='9')
        return 1;       //number
    else if(digit=='*'|| digit=='-'|| digit=='/'||digit=='+')
        return 0;       //expression
    else
        return -1;
}

void pop(){
    stack[top] = NULL;
    top--;
}

void push(char exp){
    stack[top] = exp-'0';
}