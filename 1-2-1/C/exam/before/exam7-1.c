#include <stdio.h>

int main(){
    int quarters, dimes, nickels, pennies;
    float money;
    scanf("%f", &money);

    money+=0.001;

    int real_money = (int)(100*(money));
    printf("money = %d\n", real_money);

    change(real_money, &quarters, &dimes, &nickels, &pennies);

    printf("%d %d %d %d",quarters, dimes, nickels, pennies);

    return 0;
}

void change(int money, int *quart, int *dime, int *nick, int *penny){
    *quart = money/25;
    money %= 25;
    *dime = money/10;
    money %= 10;
    *nick = money/5;
    money %= 5;
    *penny = money;

}