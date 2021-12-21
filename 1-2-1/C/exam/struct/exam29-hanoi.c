//T(n) = 2T(n-1)+1          T(1) = 1

#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    printf("%d", nun_hanoi(n));

    return 0;
}

int nun_hanoi(int n){
    if (n==1){
        return 1;
    }
    return 2*nun_hanoi(n-1)*+1;
}