#include <stdio.h>

int main(){

    int n;
    scanf("%d", &n);

    printf("%d\n", Fibonacci(n+1));

    return 0;
}

int Fibonacci(int n){
    if (n==0){
        return n;
    }
    if (n==1){
        return n;
    }
    return Fibonacci(n-2)+Fibonacci(n-1);
}