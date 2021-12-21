#include <stdio.h>

int main()
{
    int num1 = 10;
    int num2 = -15;

    int result1 = (num1 > 0) && (num1 < 0);
    int result2 = (num1 < 0) || (num2 < 0);

    printf("(num1 > 0) && (num1 < 0)의 값은 %d입니다\n", result1);
    printf("(num1 < 0) || (num2 < 0)의 값은 %d입니다\n", result2);
    printf("!result1의 값은 %d입니다\n", !result1);

    return 0;
}

