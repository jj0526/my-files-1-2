/**
 * 
 * File : 2-problem2-convert.c
 * 
 * Author : Jeon Sihyeon (wjstlgus13@gachon.ac.kr)
 * 
 * Date : 11/28/2021
 * Partner : I worked alone
 * Course : Problem Solving Methods (13967_001)
 * 
 * Summary of File:
 *      This file contains code which shows binary and hexadecimal of decimal numbers.
 *      Functions allow the user of the software to see the converted decimal numbers
 *      from 1 to 1000 to binary string and hexadecimal string.
 * 
 */

#include <stdio.h>
#include <string.h>

const int max = 1000;

int reverse(char array[], int size);
void conv_nums_and_display(int num);    //declaration

int main(){
    
    int num = 1;

    conv_nums_and_display(num);     //calls conv_nums_and_display function
    
    return 0;
}

/**
 * 
 * int reverse(char array[], int size)
 * 
 * Summary of the reverse:
 *      
 *      The reverse function, reverses the given array of characters
 * 
 * Parameters   : arrary : containing characters
 *                  integer
 * 
 * Return value : integer number    NOTE : modifies the array "in in place."
 * 
 * Description :
 *      
 *      This function utilizes the reverse algorithm ...
 *      Note, the array is modified in place
 * 
 */
int reverse(char array[], int size){
    int temp = 0;
    for (int i = 0; i<size/2; i++){
        temp = array[i];
        array[i] = array[size-i-1];
        array[size-i-1] = temp;     //swaps between array[i] and array[size-i-1]
    }
    return 1;
}

/**
 * 
 * void conv_nums_and_display(int num)
 * 
 * Summary of the conv_nums_and_display function:
 * 
 *      The conv_nums_and_display function, converts decimal numbers from 1 to 1000 
 *      to binary string and hexadecimal string and displays them.
 * 
 * Parameters :     integer number
 * 
 * Return value : Nothing 
 * 
 * Description :
 * 
 *      This function utilizes the modulo operators
 * 
 */

void conv_nums_and_display(int num){
    
    char bin[1000][15];
    char hex[1000][10];
    
    int num1 = num;
    int i = 0;

    while(num1<=max){
        int j = 0;
        num = num1;
        while(num>=0){
            bin[i][j] = num%2 + '0';    //saves number for ascii code
            num/=2;
            j++;
            if (num==0)
                num = -1;               //escapes the while loop
            bin[i][j] = NULL;
        }
        i++;
        num1++;
    }
    
    i = 0;
    num = 1;
    num1 = num;                         //saves 1 on num1
    while (num1<=max){
        int j = 0;
        num = num1;
        while (num>=0){
            if (num%16>=10){
                hex[i][j] = num%16 + 'A'-10;    //saves the alphabet for ascii code
            }
            else
                hex[i][j] = num%16 + '0';       //saves the number for ascii code
            num/=16;
            j++;
            if (num==0)
                num = -1;           //escapes while loop
            hex[i][j] = NULL;
        }
        i++;
        num1 ++;
    }

    for (int m = 0; m<max; m++){
        reverse(bin[m], strlen(bin[m]));    //calls reverse function
        reverse(hex[m], strlen(hex[m]));    //calls reverse function
    }

    for (int m = 0; m<max; m++){
        printf("DEC %-4d :    BIN %-12s  HEX %s\n", m+1, bin[m], hex[m]);   //displays
    }
}