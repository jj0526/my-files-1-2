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
 *      This file contains code which inserts a structer among nodes.
 *      Functions allow the user of the software to input a number and insert
 *      among the linked list containing numbers in a order and shows 
 *      if it's inserted succesfully or not.
 * 
 * 
 */

struct NODE{
    int key;
    struct NODE *next;
}node[3]; // declares struct NODE

int insert_num(struct NODE *ptr, struct NODE *prv_ptr, struct NODE *first, struct NODE *new, int num);
//function declaration

int main(){
    struct NODE *first;
    first = &node[0];
    node[0].next = &node[1]; // assign the address of node[1] to next of node[0]
    node[1].next = &node[2]; // assign the address of node[2] to next of node[1]
    node[0].key = 100;      // assign integer 100 into key of node[0]
    node[1].key = 250;      // assign integer 250 into key of node[1]
    node[2].key = 467;      // assign integer 467 into key of node[2]
    node[2].next = NULL;    // assign NULL to next of node[2]


    int num;
    scanf("%d", &num);

    struct NODE new;
    new.key = num;          //make a new now called "new" with num value in the key

    struct NODE *ptr;
    struct NODE *prv_ptr = NULL;

    ptr = first;     //ptr has first's address

    
    insert_num(ptr, prv_ptr, first, &new, num); //calls the insert_num function

    return 0;
}

/**
 * 
 * int insert_num(struct NODE *ptr, struct NODE *prv_ptr, struct NODE *first, struct NODE *new, int num)
 * 
 * Summary of the insert_num function :
 * 
 *      The insert_num function insert the given integer 
 *          in ascending order.
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

int insert_num(struct NODE *ptr, struct NODE *prv_ptr, struct NODE *first, struct NODE *new, int num){
    while (ptr){
        
        if (ptr->key == num){       //if the same number is found
            printf("The key already exists\n");
            return -1;              //fails to insert (already exists)
        }
        if (ptr->key > num){        // if ptr->key is bigger than num
            if (prv_ptr == NULL){   // if ptr is the first node
                new->next = ptr;    //new->next has the address of ptr
                first = new;        //first points new now
                printf("key inserted\n");
                return 0;   // success
            }
            prv_ptr->next = new;
            new->next = ptr;
            printf("key inserted\n");
            return 0;       // success
        }
        prv_ptr = ptr;      //prv_ptr points ptr's address
        ptr = ptr->next;    //ptr points ptr's next's value
    }
    prv_ptr->next = new;    //prv_ptr points new now
    printf("key inserted\n");
    return 0;   //success
}