#include <stdio.h>

/**
 * File: linkedList_insert.c
 * 
 * author : Jeon Sihyeon (wjstlgus13@gachon.ac.kr)
 * Date : 11/17/2021
 * Partner : I worked alone
 * Course : Problem Solving Methods (13967_001)
 * 
 * Summary of File:
 * 
 *      This file contains code which inserts nodes with keys 250, 300, 50, 500
 *      in ascending order.
 *      Functions allow the user of the software to see the numbers 
 *      in the linked list
 * 
 
 */

struct NODE{
    int key;
    struct NODE *next;
}node[7]; // declares struct NODE

int Insert_Key(struct NODE *head, struct NODE *new, int num);   //function declaration
int ScanList( struct NODE *head );          //function declaration

int main(){
    struct NODE head;
    head.next = &node[0];
    node[0].next = &node[1]; // assign the address of node[1] to next of node[0]
    node[1].next = &node[2]; // assign the address of node[2] to next of node[1]
    node[0].key = 100; // assign integer 100 into key of node[0]
    node[1].key = 250; // assign integer 250 into key of node[1]
    node[2].key = 467; // assign integer 467 into key of node[2]
    node[2].next = NULL; // assign NULL to next of node[2]

    int num1 = 250, num2 = 300, num3 = 50, num4 = 500;
    
    node[3].key = num1;
    node[4].key = num2;
    node[5].key = num3;
    node[6].key = num4;         //saves numbers

    Insert_Key(&head, &node[3], num1);  //calls insert_Key function
    Insert_Key(&head, &node[4], num2);  //calls insert_Key function
    Insert_Key(&head, &node[5], num3);  //calls insert_Key function
    Insert_Key(&head, &node[6], num4);  //calls insert_Key function

    ScanList(&head);                    //calls ScanLiast function

    return 0;
}

/**
 * 
 * int Insert_Key(struct NODE *head, struct NODE *new, int num)
 * 
 * Summary of the Insert_Key function :
 *      
 *      The Insert_Key function, inserts the given structures in a linked list
 * 
  * Parameters       :   struct's pointers
 *                              : containing address
 *                      integer number
 * 
 * Return Value : integer
 *                      :
 *                          return -1 : fails to insert
 *                          return 0  : successfully inserted
 *                                    -- NOTE : modifies the structures "in place."
 * 
 * Description:
 *      This function utilizes inserting a structure in linked list
 * 
 *      Note, The structers are modified in place.
 * 
 * 
 */

int Insert_Key(struct NODE *head, struct NODE *new, int num){

    struct NODE *ptr;
    struct NODE *prv_ptr;
    prv_ptr = head;     //ptr has node[0]'s address
    ptr = prv_ptr->next;//ptr has prv_ptr->next's value

    while (ptr){
        if (ptr->key == num){   // if the same number is found
            printf("The key already exists\n");
            return -1; //key already exists
        }
        if (ptr->key > num){    //if ptr->key is higher than num
            prv_ptr->next = new;    //prv_ptr->nxt has new's address
            new->next = ptr;
            printf("key inserted\n");
            return 0; // successful
        }
        prv_ptr = ptr;  //prv_ptr has ptr's address
        ptr = ptr->next;//ptr has ptr->next's value
    }
    prv_ptr->next = new;    //prv_ptr's next has new's address
    printf("key inserted\n");
    return 0; // successful
}
/**
 * 
 * int ScanList(struct NODE *head)
 * 
 * Summary of the ScanList function :  
 * 
 *      The ScanList function, prints the key of each node in sequence
 * 
 * Parameters   :   struct's pointers
 * 
 * Return Value : integer number
 *                          -- NOTE : modifies the structures "in place."
 * 
 * Description :
 *      This function utilizes the print arrays ....
 *      Note, The structures are modified in place
 * 
 * 
 */

int ScanList(struct NODE *head){
    struct NODE *ptr;
    struct NODE *prv_ptr = NULL;
    prv_ptr = head;     //ptr has node[0]'s address
    ptr = prv_ptr->next;//ptr has prv_ptr->next's value

    while(ptr){
        printf("%d ", ptr->key);
        prv_ptr = ptr;
        ptr = ptr->next;
    }

    return 0;
}