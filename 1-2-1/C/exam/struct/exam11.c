#include <stdio.h>
void compute(float stock_price[]);

struct stock{
    char name[20];
    float earnings;
    float ratio;
}item[5];

int main(){
    for (int i = 0; i<5; i++){
        gets(item[i].name);
        scanf(" %f %f", &item[i].earnings, &item[i].ratio);
        printf("i = %d\n", i);
        //scanf("%s %f %f", &item[i].name, &item[i].earnings, &item[i].ratio);
    }
    for (int i = 0; i<5; i++){
        printf("%f %f", item[i].earnings, item[i].ratio);
        printf("\n");
    }
    float stock_price[5];
    compute(stock_price);
    for (int i = 0; i<5; i++){
        printf("%f ", stock_price[i]);
    }
}

void compute(float stock_price[]){
    for (int i = 0; i<5; i++){
        stock_price[i] = item[i].earnings * item[i].ratio;
    }
}