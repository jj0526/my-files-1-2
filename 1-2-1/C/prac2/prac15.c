#include <stdio.h>

struct emp{
    int ID;
    char name[10];
    float pay;
    float hrs;
};


int main(){
    struct emp employee[6];
    for (int i; i<6; i++){
        scanf("%d %s %f %f", &employee[i].ID, &employee[i].name,&employee[i].pay,&employee[i].hrs);
    }

    printf("ID Number   Name    Pay Rate     Hours worked   gross pay\n");
    for (int i = 0; i<6; i++){
        printf("%d %s %f %f %.2f\n", employee[i].ID, employee[i].name,employee[i].pay,employee[i].hrs, employee[i].pay*employee[i].hrs);
    }
    return 0;
}