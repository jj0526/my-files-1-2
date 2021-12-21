#include <stdio.h>

int main(){
    int num1 = 10;
    printf("num1 : %d\n", num1);
    int num2 = num1--;

    printf("num1 : %d num2 : %d\n", num1, num2);

    num1 = 10;
    num2 = --num1;

    printf("num1 : %d num2 : %d\n", num1, num2);

    num1 = 10;
    num2 = num1++;

    printf("num1 : %d num2 : %d\n", num1, num2);

    num1 = 10;
    num2 = ++num1;

    printf("num1 : %d num2 : %d\n", num1, num2);

    return 0;
}

