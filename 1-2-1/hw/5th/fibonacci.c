#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    printf("%d", fib(n));

    return 0;
}

int fib(int n){
    if (n<0)
        return -1;
    if (n<2)
        return n;
    return (fib(n-1) + fib(n-2));
}