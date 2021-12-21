#include <stdio.h>

struct stock{
    char name[30];
    float earnings_per_share;
    float price_ratio;
    float real_price;
}stock[5];

int main(){
    
    for (int i = 0; i<5; i++){
        printf("input the stock's name, earnings per share and the price to earning ratio\n");
        scanf(" %s %f %f", stock[i].name, &stock[i].earnings_per_share, &stock[i].price_ratio);

        stock[i].real_price = stock[i].price_ratio*stock[i].earnings_per_share;
    }
    for (int i = 0; i<5; i++){
        printf("the anticipated price for a share of %s stock is %f\n", stock[i].name, stock[i].real_price);
    }
    
    return 0;
    
}