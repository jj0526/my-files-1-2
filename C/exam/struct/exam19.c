#include <stdio.h>

struct Date{
    int month;
    int day;
    int year;
};

int main(){
    struct Date Date1;
    int total;

    scanf("%d %d %d", &Date1.month, &Date1.day, &Date1.year);

    printf("%d", Days(&Date1));

    return 0;
    
}

int Days(struct Date *Date1){
    return (Date1->year -2000)*360+(Date1->month - 1)*30 + (Date1->day-1);
}