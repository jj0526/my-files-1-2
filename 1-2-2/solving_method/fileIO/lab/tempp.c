#include <stdio.h>

int main(){
    char str[20];
    scanf("%[^\n]", str);
    printf("%s end", str);

    return 0;
}