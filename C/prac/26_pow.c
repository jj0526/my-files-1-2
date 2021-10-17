#include <stdio.h>
double pow(float under, int power);
int main(){
    float under;
    int power;

    scanf("%f %d", &under, &power);

    printf("%.2lf\n", pow(under, power));

    return 0;
}

double pow(float under, int power){
    if (power == 0)
        return 1;
    return under*pow(under, power-1);
}