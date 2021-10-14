#include <stdio.h>

int main(){
    int num1, num2;
    scanf("%d %d", &num1, &num2);

    swap(&num1, &num2);

    printf("%d %d", num1, num2);

}
void swap(int *n1, int *n2){
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}