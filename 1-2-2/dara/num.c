#include <stdio.h>

int main(){
    int a = 10, b=3;

    change(&a, &b);

    int res_sum = sum(a, b);

    return 0;

}

void change(int *num1, int *num2){
    int temp = *num1;
    ...
}

int sum(int num1, int num2){
    return num1+num2;
}