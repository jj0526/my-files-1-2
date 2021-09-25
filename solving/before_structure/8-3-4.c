#include <stdio.h>

void extend(double price[], double quantity[], double amount[], int size);

int main(){
    double price[10] = {10.62, 14.89, 13.21, 16.55, 18.62, 9.47, 6.58, 18.32, 12.15, 3.98};
    double quantity[10] = {4, 8.5, 6, 8.35, 9, 15.3, 3, 5.4, 2.9, 4.8};
    // stores 10 numbers in price[10] and quantity[10]
    double amount[10];

    int size = 10;

    extend(price, quantity, amount, size); // recalled the function extend

    for (int i = 0; i<10; i++){
        printf("%lf ", amount[i] ); // prints amount[i]
    }

    return 0;

}
/*
    calculate the elements in the amount array as the product of the equivalent elements
    in the price and quantity arrays
*/
void extend(double price[], double quantity[], double amount[], int size){
    for (int i = 0; i<size; i++){
        amount[i] = price[i] * quantity[i]; // when i == 1, amount[1] = price[1] * quantity[1]
    }
}