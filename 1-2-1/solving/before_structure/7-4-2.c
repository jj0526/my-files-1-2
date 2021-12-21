#include <stdio.h>

void amount(int total, int *gallons, int *quarts, int *pints, int *cups);

int main(){
    int total, gallons, quarts, pints, cups;

    printf("input the number of the cups\n");
    scanf("%d", &total);

    amount(total, &gallons, &quarts, &pints, &cups);

    printf("%d %d %d %d", gallons, quarts, pints, cups);

    return 0;

}

void amount(int total, int *gallons, int *quarts, int *pints, int *cups){
    *gallons = total/16;
    *quarts = (total % 16) / 4;
    *pints = ((total%16) %4 ) / 2;
    *cups = total % 2;
}