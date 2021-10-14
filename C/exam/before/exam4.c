#include <stdio.h>

int main(){
    int num1, num2, big, small;

    scanf("%d %d", &num1, &num2);

    minmax(num1,num2, &big, &small);

    printf("%d %d", big, small);

    return 0;
}

void minmax(int n1, int n2, int *big, int *small){
    if (n1>n2){
        *big = n1;
        *small = n2;
    }
    else{
        *big = n2;
        *small = n1;
    }
}