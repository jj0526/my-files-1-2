#include <stdio.h>

int stack[20];
int top = -1;

int main(){
    char expression[20];
    scanf(" %s", expression);

    int res = read(expression);

    if (res == -1){
        printf("There's an unvalid expression\n");
        return 0;
    }
    for (int i = 0; i<top; i++)
        printf("%d ", expression[i]);

}

int is_digit(char num){
    if (num>'0'&& num<'9')
        return 1;
    else if(num=='*' || num=='-'|| num=='/'||num=='+')
        return 0;
    else
        return -1;
}

int read(char expression[]){
    int index = 0;

    while (expression[index]=='\0'){
        if (is_digit(expression[index]!=-1)){
            push(expression[index]);
        }
        else
            return -1;
    }
    return 0;
}

void push(char pushing){
    if (is_digit(pushing)==1){
        top++;
        stack[top] = pushing;
    }
    else if (is_digit(pushing)==0){
        pop(pushing);
    }
    return 0;
}

int pop(char express){

    stack[top] = NULL;
    top--;
}

int calculate()