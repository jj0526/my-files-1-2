#include <stdio.h>

struct date{
    int month, day, year;
}date;

int main(){
    int m, d, y;
    printf("input the current month, day, year : ");
    scanf("%d %d %d", &m, &d, &y);
    date.month = m;
    date.day = d;
    date.year = y;

    printf("%d.%d.%d\n", date.month, date.day, date.year);

    return 0;

}