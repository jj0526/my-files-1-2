#include <stdio.h>

struct employee{
    char last_name[21];
    int identification_number;
    float pay_rate, hours_worked;
    float gross;
}employee[6];

int main(){
    for (int i = 0; i<6; i++){
        printf("input the ID number, their names, the pay rate and how long they worked\n");
        scanf("%d %s %f %f", &employee[i].identification_number, &employee[i].last_name, &employee[i].pay_rate, &employee[i].hours_worked);
    }
    for (int i = 0; i<6; i++){
        employee[i].gross = employee[i].pay_rate * employee[i].hours_worked;
    }
    for (int i = 0; i<6; i++){
        printf("%d    %s    %f\n", employee[i].identification_number, employee[i].last_name, employee[i].gross);
    }

    return 0;
    
}