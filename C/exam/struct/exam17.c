#include <stdio.h>

struct car{
    int id;
    int miles;
    int gallons;
};

int main(){
    struct car cars[5];
    for (int i = 0;i<5; i++){
        scanf("%d %d %d", &cars[i].id, &cars[i].miles, &cars[i].gallons);
    }
    float avr[5];
    for (int i = 0; i<5; i++){
        avr[i] = (float)cars[i].miles / (float)cars[i].gallons;
        printf("%f\n", avr[i]);
    }
}