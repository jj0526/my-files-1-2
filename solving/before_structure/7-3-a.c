#include <stdio.h>
int secs(int hrs, int mins, int sec);

int main(){
    int hrs, mins, sec;

    printf ("input the number of hours, minutes and seconds\n");

    scanf("%d %d %d", &hrs, &mins, &sec);

    int totSec = secs(hrs, mins, sec);

    printf("%d", totSec);

}

int secs(int hrs, int mins, int sec){
    int totSec = 3600 * hrs + 60 * mins + sec;

    return totSec;
}