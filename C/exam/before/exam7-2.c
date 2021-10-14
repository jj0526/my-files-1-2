#include <stdio.h>

int main(){
    long sec;
    scanf("%ld", &sec);
    int hours, minutes, seconds;

    secs(sec, &hours, &minutes, &seconds);

    printf("%d %d %d", hours, minutes, seconds);
}

void secs(long sec, int *hr, int *min, int *secs){
    *secs = sec%60;
    *min = (sec/60)%60;
    *hr = ((sec/60)/60)%60;
}