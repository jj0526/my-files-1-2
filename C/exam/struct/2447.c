#include <stdio.h>

//이진수 변환
int main(){
    int n;

    scanf("%d", &n);

    bi(n);
    return 0;
}

void bi(int n){
    if (n!=1){
        bi(n/2);
    }
    printf("%d", n%2);
}//11