#include <stdio.h>

int main(){
    long time;
    printf("총 시간(초)를 입력해 주십시오.\n");

    scanf("%ld", &time);
    int hr, min, sec;
    sec = time%60;
    time /= 60;
    min = time%60;
    hr = time/60;
    printf("%d : %d : %d\n", hr, min, sec);

    return 0;
}

