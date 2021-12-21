#include <stdio.h>
#include <stdlib.h>

struct NODE{
    int key;
    struct NODE *next;
}node[3]; // declares struct NODE

int main(){
    node[0].next = &node[1]; // assign the address of node[1] to next of node[0]
    node[1].next = &node[2]; // assign the address of node[2] to next of node[1]
    node[0].key = 100; // assign integer 100 into key of node[0]
    node[1].key = 250; // assign integer 250 into key of node[1]
    node[2].key = 467; // assign integer 467 into key of node[2]
    node[2].next = NULL; // assign NULL to next of node[2]

    int num;
    scanf("%d", &num);

    struct NODE *ptr;
    ptr = &node[0];     //ptr has node[0]'s address
    int is_found = 0; // check if the key is found
    while(ptr!=NULL){
        
        if (ptr->key == num){//if key is found
            printf("search key found.");
            is_found = 1;
        }
        ptr = (*ptr).next;  //if key is not found, ptr gets the next address
    }
    if (is_found==0)
        printf("search key not found.");

    return 0;
}