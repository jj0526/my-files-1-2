#include <stdio.h>

struct MonthDays{
    char name[10];
    int days;
};

int main(){
    struct MonthDays convert[12] = {"January",31,"February",29,"March",31,"April", 30,"May",31,"June",30,"July",31,"August",31,
    "September",30,"October",31,"November",30,"December",31};
    for (int i = 0; i<12; i++){
        printf("the number of days in %s is %d\n", convert[i].name, convert[i].days);
    }

    return 0;

}