#include <stdio.h>
void extend(float price[], float quantity[], float amount[]);

int main(){
    float price[10] = {10.62, 14.89, 13.21, 16.55, 18.62, 9.47, 6.58, 18.32, 12.15, 3.98};
    float quantity[10] = {4, 8.5, 6, 8.35, 9, 15.3, 3, 5.4, 2.9, 4.8};
    float amount[10];

    extend(price, quantity, amount);

    for (int i = 0; i<10; i++){
        printf("%.4f ", amount[i]);
    }

    return 0;

}

void extend(float price[], float quantity[], float amount[]){
    for (int i = 0; i<10; i++){
        amount[i] = price[i] * quantity[i];
    }
}