#include <stdio.h>

int main(){
    int a = 10;
    int b = 11;
    printf("%d %d %d", a<b, a==b, a>b||!0); // 0 = false, non 0 = true

    return 0;
}

