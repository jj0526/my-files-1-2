#include <stdio.h>

struct Date{
    int month;
    int day;
    int year;
};

int main(){
    struct Date date1, date2;

    scanf("%d %d %d", &date1.month, &date1.day, &date1.year);
    scanf("%d %d %d", &date2.month, &date2.day, &date2.year);


    printf("%dth\n",recent(date1, date2));

}

int recent(struct Date date1, struct Date date2){
    if (date1.year>date2.year){
        return 1;
    }
    else{
        return 2;
    }
}