#include <stdio.h>
int iter_factorial(int n);

int main(){
    int n; 
    scanf("%d", &n);
    printf("%d\n", iter_factorial(n));

    return 0;
}

int iter_factorial(int n){
    if (n==0){
        return 1;
    }
    return n*iter_factorial(n-1);
}