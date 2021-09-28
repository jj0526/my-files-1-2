#include <stdio.h>
void calculate(int *, int *, int *, int *, int *, int *);

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
    *   This file contains code which calculates N1*N2, N1/N2, N1%N2, N1+N2
    *
*/
int main(){
    int N1,N2, re1, re2, re3, re4;              // declared 6 integers

    printf("input the numbers of N1 and N2 (in integer)");

    scanf("%d %d", &N1, &N2);                   // NOTE : we only save positive numbers

    calculate(&N1, &N2, &re1, &re2, &re3, &re4); // calls the function calculate

    printf("%d, %d, %d, %d", re1, re2, re3, re4); // shows the result

    return 0;

}
/**
 * void calculate(int *n1, int *n2, int *re1, int *re2, int *re3, int *re4)
 * 
 * Summary of the calculate function:
 *  
 *    The calculate function calculates N1*N2, N1/N2, N1%N2, N1+N2 
 *    with the integer N1 and N2.
 * 
 * Parameters : pointers : containing integers
 * 
 * Return Value : Nothing  -- note : modifies the pointers
 * 
 * Description : 
 * 
 *     This function utilizes calculator.
 *     Note, the pointers are modified in place.
 * 
 *  calculate calculates N1*N2, N1/N2, N1%N2, N1+N2 and returns the four results.
*/
void calculate(int *n1, int *n2, int *re1, int *re2, int *re3, int *re4){
    *re1 = *n1 * *n2;
    *re2 = *n1 / *n2;
    *re3 = *n1 % *n2;
    *re4 = *n1 + *n2;
}
