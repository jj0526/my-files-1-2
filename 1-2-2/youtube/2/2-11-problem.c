#include <stdio.h>

int main(){
    int num1;
    int num2;

    printf("두 정수를 입력해 주십시오\n");
    scanf("%d %d", &num1, &num2);

    printf("%d + %d = %d\n", num1, num2, num1+num2);
    printf("%d - %d = %d\n", num1, num2, num1-num2);
    printf("%d x %d = %d\n", num1, num2, num1*num2);
    printf("%d / %d = %.3f\n", num1, num2, (float)num1/num2);
    printf("%d / %d 의 몫 : %d\n", num1, num2, num1/num2);
    printf("%d / %d 의 나머지 %d\n", num1, num2, num1%num2);
}

