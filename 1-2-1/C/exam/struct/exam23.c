#include <stdio.h>

int main(){
    int n;

    scanf("%d", &n);

    printf("%d", iter_factorial(n));

    return 0;
}

int iter_factorial(int n){
    if (n==1){
        return 1;
    }
    return n*iter_factorial(n-1);
}