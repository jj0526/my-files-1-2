/**
 * File : lab1_stack.c
 *
 * Author : Jeon Sihyeon (wjstlgus13@gachon.ac.kr)
 * Date : 12/01/2021
 * Partner : I worked alone
 * Course : Problem Solving Methods (13967_001)
 *
 * Summary of File :
 *      This file contains code which push or pop an integer number
 *      Functions allow the user of the software to input an integer number
 *      and see the data in stack
 * 
**/

#include <stdio.h>

int stack[10];
int top = -1;

int push(int num);
int pop();
int stack_full();
int stack_empty();

int main(){
    int num;
    scanf("%d", &num);

    int check1 = push(num); //calls function push
    if (check1==0)
        printf("pushed the number successfully\n");
    else
        printf("failed to push the number\n");
    
    int check3 = push(2);   //calsl function push
    if (check3==0)
        printf("pushed the number successfully\n");
    else
        printf("failed to push the number\n");
    

    if(top==-1){
        printf("no data in stack array\n");
    }
    else{
        printf("current data : ");
        for (int i = 0; i<top+1; i++)
            printf("%d ", stack[i]);        //display current data in stack array
    }

    int check2 = pop(); //calls function pop
    if (check2==0)
        printf("\npopped the last number successfully\n");
    else
        printf("failed to pop the last number\n");
    

    if(top==-1){
        printf("no data in stack array\n");
    }
    else{
        printf("current data : ");
        for (int i = 0; i<top+1; i++)
            printf("%d ", stack[i]);        //display current data in stack array
    }

    return 0;
}


/**
 * int push(int num)
 * 
 * Summary of the push function:
 * 
 *      push function checks if the stack is full. it pushes an
 *      given integer number into the last index of the stack array.
 * 
 * Parameters : integer number
 * 
 * Return value : integer number
 * 
 * Description :
 * 
 *      This function utilizes the push data in stack algorithm...
 *
 */

int push(int num){
    if (stack_full()!=-1){  //if the stack is not full
        top++;
        stack[top] = num;
        return 0;
    }
    else    //if the stack is full
        return -1;
}

/**
 * int pop()
 * 
 * Summary of the pop function:
 * 
 *      The pop function eliminates the last data in stack array
 * 
 * Parameters   : nothing
 * 
 * Return value : integer number
 * 
 * Description :
 * 
 *      This function utilizes the pop in stack algorithm...
 * 
 */


int pop(){
    if (stack_empty()!=-1){ //if the stack isn't empty
        stack[top] = NULL;
        top--;
        return 0;
    }
    else    //if the stack is empty
        return -1;
}


/**
 * int stack_full()
 * 
 * Summary of the stack_full:
 * 
 *      The stack_full function checks if the stack array is full or not
 * 
 * Parameters : nothing
 * 
 * Return value : integer number
 * 
 * Description :
 * 
 *      if the return value is -1, the stack array is full
 *      if the return value is 0, the stack array is not full
 * 
 * 
 */

int stack_full(){
    if (top == 9)
        return -1;  //full
    else
        return 0;   //not full
}

/**
 * int stack_empty()
 * 
 * Summary of the stack_empty function:
 * 
 *      The stack_empty function checks if the stack array is full or not
 * 
 * Parameters : nothing
 * 
 * Return value : integer number
 * 
 * Description :
 * 
 *      if the return value is -1, the stack array is empty
 *      if the return value is 0, the stack array isn't empty
 */


int stack_empty(){
    if (top==-1)
        return -1;   //empty
    else
        return 0;   //not empty
}