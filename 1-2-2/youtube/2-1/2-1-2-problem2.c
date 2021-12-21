#include <stdio.h>

int main(){
    char name[50];
    printf("성함이 어떻게 되시나요?\n");
    scanf(" %s", name);
    printf("%s씨 환영합니다\n", name);

    return 0;
}

