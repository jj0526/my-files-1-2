#include <stdio.h>

struct Date{
    int month;
    int day;
    int year;
};

int main(){
    struct Date today;
    scanf("%d %d %d", &today.month, &today.day, &today.year);

    printf("%d", Days(today));

    return 0;
}

int Days(struct Date today){
    return (today.day-1+30*(today.month-1)+360*(today.year-2000));
}