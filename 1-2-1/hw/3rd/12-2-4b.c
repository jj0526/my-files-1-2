#include <stdio.h>

void cal(double average[], int size);                   // forward declaration

/**
  * File : 12-2-4a.c
  * 
  * Author : Jeon Sihyeon(wjstlgus13@gachon.ac.kr)
  * date : 9/29/2021
  * Partner : I worked alone
  * Course : Problem Solving Methods (13967_001)
  * 
  * 
  * Summary of File:
  *     
  *     This file contains code which shows a report 
  * 
  *     This report shows listing each car number,the miles per gallon achieved by the car 
  *     and average miles per gallon achieved by the five cars. 
  *     Functions calculates average miles per gallon.
  * 
*/
struct car{
    int car_number;
    int miles_driven;
    int gallons;
}CARS[5];
//variable name : CARS

int main(){
    printf("input the car number, the numbers of miles driven and the amount of gallons used (in integer)\n");
    // NOTE : gets only integer numbers
    for (int i = 0; i<5; i++){              // NOTE : gets only positive integers
        scanf("%d %d %d", &CARS[i].car_number, &CARS[i].miles_driven, &CARS[i].gallons);
        if ((CARS[i].car_number<=0)||(CARS[i].miles_driven<=0)||(CARS[i].gallons<=0)){
            i--;                                                  //so it can get the numbers again.
            printf("input the numbers again\n");
        }
    }
    double average[5];        // declared in double so it's more accurate
    int size = 5;

    cal(average, size);       // calls the function cal

    printf("Car Number      Miles Driven      Gallons Used     miles per gallon\n");

    for (int i = 0; i<5; i++){
        printf(" %5.2d           %5.2d              %5.2d                %.4lf\n",CARS[i].car_number, CARS[i].miles_driven, CARS[i].gallons, average[i]);
    }

    return 0;

}
/**
  * void cal(double average[], int size)
  * 
  * Summary of the cal function :
  * 
  *     The cal function, calculates the average miles per gallon achieved by the five cars
  * 
  * Parameters : array : containing double numbers.
  * 
  * Return Value : Nothing -- Note : Modifies the array "in place".
  * 
  * Description :
  * 
  *     This function utilizes calculator . . .
  *     Note, the array is modified in place.
  * 
  * 
*/
void cal(double average[], int size){
    for (int i = 0; i<5; i++){
        average[i] = (double)(CARS[i].miles_driven) / (double)(CARS[i].gallons); //calculates average[i] with 2 doubles
    }
}