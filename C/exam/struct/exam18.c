#include <stdio.h>

struct Date{
    int month;
    int day;
    int year;
};

int main(){
    struct Date Date1;
    scanf("%d %d %d", &Date1.month, &Date1.day, &Date1.year);

    printf("%d", Days(Date1));

    return 0;
}

int Days(struct Date date1){

    return 360*(date1.year-2000)+(date1.month-1)*30+date1.day-1;
}