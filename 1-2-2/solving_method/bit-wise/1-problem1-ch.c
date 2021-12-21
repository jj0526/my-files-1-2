/**
 * 
 * File : 1-problem1-ch.c
 * 
 * Author : Jeon Sihyeon (wjstlgus13@gachon.ac.kr)
 * 
 * Date : 11/28/2021
 * Partner : I worked alone
 * Course : Problem Solving Methods (13967_001)
 * 
 * Summary of File:
 *      This file contains code which reads a chracter and displays
 *      each bit of the character
 * 
 * 
 */
#include <stdio.h>
int display_bit(char ch);   //declaration

int main(){
    for (int i = 0; i<4; i++){
        char ch;
        scanf(" %c", &ch);
        int res = display_bit(ch);  //calls display_bit function
    }
    return 0;
}

/**
 * int display_bit(char ch)
 * 
 * Summary of the display_bit function:
 * 
 *      display_bit function, makes a mask 0x80 and shift it. so it
 *      displays bit of the chracter which the user inputs.
 * 
 * Parameters   : character
 * 
 * Return Value : integer
 * 
 * Description :
 * 
 *      This function utilizes the masking operation.
 * 
 */

int display_bit(char ch){
    int mask = 0x80;

    while(mask>0){
        if ((mask&ch)>0)
            printf("1");        //displays 1 on terminal
        else
            printf("0");        //displays 0 on terminal
        mask = mask>>1;         //right shift 1 bit 
    }
    printf("\n");
    return 0;
}