#include <stdio.h>
#pragma warning (disable: 4996)

void extend(float price[], float quantity[], float amoumt[]);

void main(void)
{
    float price[10] = { 1.11, 2.22, 3.33, 4.44, 5.55, 6.66, 7.77, 8.88, 9.99, 10.11 };
    float quantity[10] = { 1, 1.5, 2, 2.5, 3, 3.5, 4, 4.5, 5, 5.5 };
    float amount[10];

    extend(price, quantity, amount);

    for (int i = 0; i<10; i++){
        printf("%f * %f =%f\n", price[i], quantity[i], amount[i]);
    }

}

void extend(float price[], float quantity[], float amoumt[])
{
    for (int i = 0; i<10; i++){
        amount[i] = price[i] * quantity[i];
    }
}