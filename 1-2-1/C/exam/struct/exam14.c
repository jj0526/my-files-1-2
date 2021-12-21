#include <stdio.h>

struct employee{
    int ID;
    char name[20];
    float pay_rate, hours_worked;
};

int main(){
    struct employee employ[6] = {{3462,"Jones",4.62, 40},{6793,"Robbins",5.83,38.6},{6985,"Smith",5.22,45.5},
    {7834,"Swain",6.89, 40}, {8867,"Timmins",6.43,35.5},{9002,"Williams", 4.75,42}};

    float total[6];
    for (int i = 0; i<6; i++){
        total[i] = employ[i].pay_rate * employ[i].hours_worked;
    }
    printf("ID Number         Name          Pay Rate        Hours Worked        Total pay\n");
    for (int i = 0; i<6; i++){
        printf("%d   %s    %.2f          %.2f           %.2f\n", employ[i].ID, employ[i].name, employ[i].pay_rate, employ[i].hours_worked, total[i]);
    }
    return 0;
    
}
