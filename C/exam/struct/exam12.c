#include <stdio.h>

struct MONTH_DAYS{
    char month_name[10];
    int days;
};

int main(){
    struct MONTH_DAYS convert[12] = {{"january", 31}, {"February", 30}, {"c",31},{"d",30},{"e",31},
    {"f",30},{"g",31}, {"h", 30}, {"I",31},{"j",30},{"k",31},{"l",30}};

    for (int i = 0; i<12; i++){
        printf("%s %d\n",month[i].month_name, month[i].days);
    }

    return 0;
}