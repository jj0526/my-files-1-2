#include <stdio.h>
#include <string.h>

int main(){
    char char1[30];
    char char2[30];
    gets(char1);        //get char get string   줄바꿈 전까지
    scanf(" %s", char2);    //띄어쓰기 전까지

    printf("1 : %s\n 2 : %s", char1, char2);

    return 0;
}