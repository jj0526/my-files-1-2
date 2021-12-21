#include <stdio.h>

double pow(float num1, int num2);

int main(){
    float num1;
    int num2;
    scanf("%f %d", &num1, &num2);

    printf("%lf\n", pow(num1,num2));

    return 0;

}

double pow(float num1, int num2){
    if (num2==0){
        return 1;
    }
    return num1*pow(num1, num2-1);
}