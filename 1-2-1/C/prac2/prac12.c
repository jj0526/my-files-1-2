#include <stdio.h>

struct MONTH_DAYS{
    char month_name[10];
    int days;
};
//why 4 structs
int main(){
    
    struct MONTH_DAYS new_month[3] = {{"sdfs", 10},{"weqw", 12},{"asda", 11}};

    for (int i = 0; i<3; i++){
        printf("%s %d", new_month[i].month_name, new_month[i].days);
    }

    return 0;

}