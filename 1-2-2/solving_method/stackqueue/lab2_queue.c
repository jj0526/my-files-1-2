/**
 * File : lab2_queue.c
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

int enqueue(int num);
int dequeue();
int queue_full();
int queue_empty();

int queue[10];
int front = -1, back = -1;

int main(){
    int num;
    scanf("%d", &num);

    int res1 = enqueue(num);    //calls enqueue function
    if (res1==0)
        printf("enqueued the number successfully\n");
    else
        printf("failed to enqueue the number\n");
    
    int res3 = enqueue(2);  //calls enqueue function
    if (res3==0)
        printf("enqueued the number successfully\n");
    else
        printf("failed to enqueue the number\n");
    

    if(back==-1){
        printf("no data in queue array\n");
    }
    else{
        printf("current data : ");
        for (int i = 0; i<back+1; i++)
            printf("%d ", queue[i]);        //display current data in queue array
    }


    int res2 = dequeue();   //calls res2 function
    if (res2==0)
        printf("\ndequeued the number successfully\n");
    else
        printf("failed to dequeue number\n");


    if(back==-1){
        printf("no data in queue array\n");
    }
    else{
        printf("current data : ");
        for (int i = 0; i<back+1; i++)
            printf("%d ", queue[i]);    //display current data in queue array
    }

    return 0;
}

/**
 * int enqueue(int num)
 * 
 * Summary of the enqueue function :
 * 
 *      The enqueue function insert the given integer into the last index of queue array
 * 
 * Parameters : integer number
 * 
 * Return value : integer number
 * 
 * Description :
 *      
 *      This function utilizes the enqueue in queue array...
 * 
 */

int enqueue(int num){
    if (queue_full()!=-1){  //if the queue is not full
        if (front==-1){ //if there's no data in the queue
            front++;
            back++;
            queue[back] = num;
        }
        else{
            back++;
            queue[back] = num;
        }
        return 0;
    }
    else   //if the queue is full
        return -1;
}

/**
 * int dequeue()
 * 
 * Summary of the dequeue function :
 * 
 *      The dequeue function deletes the first index of the queue array
 * 
 * Parameters : nothing
 * 
 * Return value : integer number
 * 
 * Description : 
 * 
 *      This function utilizes the dequeue in queue
 * 
 */

int dequeue(){
    if (queue_empty()!=-1){ //if the queue isn't empty
        if (back==0){
            queue[back] = NULL;
            front--;
            back--;

        }
        else{
            int temp = 0;
            while(1){   // shift number
                if (queue[temp]==NULL)
                    break;
                queue[temp] = queue[temp+1];
                temp++;
            }
            back--;
        }
        return 0;   //dequeued successfully
    }
    else    //if the queue is empty
        return -1;  //failed to dequeue
}

/**
 * int queue_full()
 * 
 * Summary of the queue_full function :
 *      
 *      The queue_full checks if queue array is full or not
 * 
 * Paremeters :
 *          nothing
 * 
 * Return value : integer number
 * 
 * Description :
 * 
 *      If the array is full, it returns -1
 *      If the array isn't full, it returns 0
 * 
 * 
 */


int queue_full(){
    if (back==9)
        return -1;  //full
    else
        return 0;   //not full
}

/**
 * int queue_empty()
 * 
 * Summary of the queue_empty function :
 * 
 *      The queue_empty function checks if the array queue is empty of not
 * 
 * Parameters : nothing
 * 
 * Return value : integer number
 * 
 * Description :
 * 
 *      If the queue is empty, it returns -1
 *      If the queue isn't empty, it returns 0
 * 
 */



int queue_empty(){
    if (back==-1){
        return -1;  //empty
    }
    else
        return 0;   //not empty
}