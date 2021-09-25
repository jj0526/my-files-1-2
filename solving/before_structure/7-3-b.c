#include <stdio.h>
void secs(int hrs, int mins, int sec, int *totSec);

int main(){
    int hrs, mins, sec, totSec;

    printf ("input the number of hours, minutes and seconds\n");

    scanf("%d %d %d", &hrs, &mins, &sec);

    secs(hrs, mins, sec, &totSec);

    printf("%d", totSec);

}

void secs(int hrs, int mins, int sec, int *totSec){
    *totSec = 3600 * hrs + 60 * mins + sec;

}