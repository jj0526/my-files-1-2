#include <stdio.h>

struct stock{
    char name[20];
    float eps;
    int ppe;
};

int main(){
    struct stock new_stock[5];
    for (int i = 0; i<5; i++){
        scanf(" %s %f %d", new_stock[i].name, &new_stock[i].eps, &new_stock[i].ppe);
    }

    for (int i = 0; i<5; i++){
        printf("%s stock is %f * %d = %f\n", new_stock[i].name, new_stock[i].eps, new_stock[i].ppe, new_stock[i].eps*new_stock[i].ppe);
    }

    return 0;

}