#include <stdio.h>

/**
 * File: linkedList_insert.c
 * 
 * author : Jeon Sihyeon (wjstlgus13@gachon.ac.kr)
 * 
 * Date : 11/17/2021
 * Partner : I worked alone
 * Course : Problem Solving Methods (13967_001)
 * 
 * Summary of File:
 * 
 *      This file contains code which deletes a structer in linked list.
 *      Functions allow the user of the software to input a number that 
 *      they want to delete and delete in the linked list and show if it
 *      can be deleted
 * 
 * 
 */

struct NODE{
    int key;
    struct NODE *next;
}node[3]; // declares struct NODE

int delete_num(struct NODE *ptr, struct NODE *prv_ptr, struct NODE *first, int num);    //function declaration

int main(){
    struct NODE *first;
    first = &node[0];
    node[0].next = &node[1]; // assign the address of node[1] to next of node[0]
    node[1].next = &node[2]; // assign the address of node[2] to next of node[1]
    node[0].key = 100; // assign integer 100 into key of node[0]
    node[1].key = 250; // assign integer 250 into key of node[1]
    node[2].key = 467; // assign integer 467 into key of node[2]
    node[2].next = NULL; // assign NULL to next of node[2]

    int num;
    scanf("%d", &num);

    struct NODE *ptr;
    struct NODE *prv_ptr = NULL;

    ptr = first;     //ptr has node[0]'s address

    delete_num(ptr, prv_ptr, first, num);   //calls delete_num function

    return 0;
}

/**
 * 
 * int delete_num(struct NODE *ptr, struct NODE *prv_ptr, struct NODE *first, int num)
 * 
 * Summary of the delete_num function:
 *      
 *      The delete_num function delete the given integer 
 *          in a linked list in ascending order.
 * 
 * Parameters       :  structer's pointers
 *                              : containing address
 *                      integer number
 * 
 * Return Value : integer -- Note : modifies the structures "in place"
 *                  : return 0 : successfully deleted
 *                      return -1 : failed to delete
 * 
 * Description:
 * 
 *      This function utilizes the deleting a structure in linked list algorithm
 * 
 *      Note, The structers are modified in place.
 * 
 */

int delete_num(struct NODE *ptr, struct NODE *prv_ptr, struct NODE *first, int num){
    
    while(ptr){
        if (ptr->key == num){       //if the same number is found
            if (prv_ptr==NULL){
                first = ptr->next;
                ptr->key = -1;      //initializes ptr's key into -1
                ptr->next = NULL;
                printf("deleted the key successfully\n");
                return 0; // success
            }
            prv_ptr = ptr->next;
            ptr->key = -1;          //initializes ptr-> key into -1
            ptr->next = NULL;       //ptr->next doesnt point anything
            printf("deleted the key successfully\n");
            return 0; // success
        }
        prv_ptr=ptr;            //prv_ptr points ptr's address
        ptr=ptr->next;          //ptr points ptr's next's address
    }
    printf("There's no such value\n");
    return -1; //no such key
}