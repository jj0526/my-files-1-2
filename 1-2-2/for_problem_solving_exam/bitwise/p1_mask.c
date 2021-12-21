#include <stdio.h>
void display_bit(int mask, char num, char bit[]);

int main(){
    int mask = 0x80;

    char num;
    char bit[30];
    scanf("%c", &num);

    display_bit(mask, num, bit);

    printf("%s", bit);

    return 0;
}

void display_bit(int mask, char num, char bit[]){
    int i = 0;
    while(mask!=0){
        if ((mask&num)>0){
            bit[i] = '1';
        }
        else
            bit[i] = '0';
        printf("bit : %c\n", bit[i]);
        mask = mask >> 1;
        i++;
        printf("%d\n", mask);
    }
    bit[i] = NULL;
}