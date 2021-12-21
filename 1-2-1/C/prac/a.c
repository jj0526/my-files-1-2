#include <stdio.h>

struct Date{
    int yy, mm, dd;
};

struct Emp{
    char EmpName[25];
    float salary;
    struct Date today;
};

void printData(struct Emp *myData);

void main(){
    struct Emp a = {"me", 3000, {2021,10,16}};
    printData(&a);
}
void printData(struct Emp *myData){
    printf("Mr. %s was hired on %d-%d-%d with %.2f per month\n", myData->EmpName, myData->today.yy, myData->today.mm, myData->today.dd, myData->salary);
}