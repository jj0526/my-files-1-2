#include <stdio.h>

void cal(double average[], int size);                      // forward declaration

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
//variable name : CARS in array