#include <stdio.h>

struct date
{
    int month, day, year;
}date1;

int main(){
    scanf("%d %d %d", &date1.month, &date1.day, &date1.year);

    printf("%d %d %d", date1.month, date1.day, date1.year);

    return 0;
}
