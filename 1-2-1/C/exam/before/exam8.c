#include <stdio.h>
void liquid(int total, int *gal, int *qua, int *pin, int *cup);

int main(){
    int gallons, quarts, pints, cups, total;
    scanf("%d", &total);

    liquid(total, &gallons, &quarts, &pints, &cups);

    printf("%d = %d %d %d %d", total,gallons, quarts, pints, cups);

    return 0;

}

void liquid(int total, int *gal, int *qua, int *pin, int *cup){
    *gal = total/16;
    total %=16;
    *qua = total/4;
    total%=4;
    *pin = total/2;
    *cup = total%=2;
}