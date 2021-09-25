#include <stdio.h>

int main(){
    float base[5], overtime[5], total[5];

    for (int i = 0; i<5; i++){
        scanf("%f %f", &base[i], &overtime[i]);
    }

    totpay(base, overtime, total);
    
    for (int i = 0; i<5; i++){
        printf("%f\n",total[i]);
    }
}

void totpay(float b[], float o[], float t[]){
    for (int i = 0; i<5; i++){
        t[i] = b[i] + o[i];
    }
}