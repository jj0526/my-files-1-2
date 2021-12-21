#include <stdio.h>

void mile2km(float miles[]);

int main(){
    float miles[10];
    for (int i = 0; i<10; i++){
        scanf("%f", miles[i]);
    }

    return 0;

}

void mile2km(float miles[]){
    for (int i = 0; i<10; i++){
        miles[i] = miles[i] * 1.6093;
    }

    for (int i = 0; i<10; i++){
        printf("%f", miles[i]);
    }

}