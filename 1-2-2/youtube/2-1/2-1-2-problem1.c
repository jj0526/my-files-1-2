#include <stdio.h>

int main(){
    int a = 3;
    int b = 4;
    printf("정수를 입력하십시오.\n");
    scanf("%d %d", &a, &b);
    
    printf("%d + %d = %d", a, b, a+b);

    return 0;
}

