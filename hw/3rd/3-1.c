#include <stdio.h>
void totpay(float b[], float o[], float t[]);
/****
    *file : 3-1.c
    *
    * Author : Jeon Sihyeon (wjstlgus13@gachon.ac.kr)
    * 
    * Date : 9/26/2021
    * 
    * Partner : I worked alone
    * Course : Problem Solving Methods (13967_001)
    * 
    * Summary of File:
    *   This file contains code which shows the total payment of base and total payments.
    *
*/
int main(){
    float base[5], overtime[5], total[5];

    printf("input 5 base and overtime payments");

    for (int i = 0; i<5; i++){
        scanf("%f %f", &base[i], &overtime[i]); // NOTE :  we only save positive numbers.
        if ((base[i]<=0)||overtime[i]<=0){
            printf("input the base salary and overtime again\n");
            i--;                                 // so it inputs the number again
        }
    }

    totpay(base, overtime, total); // calls the function totpay
    
    for (int i = 0; i<5; i++){
        printf("%f\n",total[i]);
    }
}
/** 
  *
  * void totpay(float b[], float o[], float t[])
  * 
  * Summary of totpay function :
  * 
  *     The totpay function computes the total pay for each person by adding the base salary
  *     and overtime payment, and storing the result in total
  * 
  * Parameters : array : containting float numbers
  * 
  * Return Value : Nothing -- Note : Modifies the array "in place"
  * 
  * Description :
  *     
  *     This function utilizes calculator
  *     Note, the array is modified in place.
  * 
*/
void totpay(float b[], float o[], float t[]){
    for (int i = 0; i<5; i++){
        t[i] = b[i] + o[i]; // saves sum of base[i] and overtime[i] into total[i]
    }
}