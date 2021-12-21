#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{
    int key;
    struct NODE *next;
}N node[3]; // declares struct NODE

int main(){
    N *first;
    first->next = &node[0];
    node[0].next = &node[1]; // assign the address of node[1] to next of node[0]
    node[1].next = &node[2]; // assign the address of node[2] to next of node[1]
    node[0].key = 100; // assign integer 100 into key of node[0]
    node[1].key = 250; // assign integer 250 into key of node[1]
    node[2].key = 467; // assign integer 467 into key of node[2]
    node[2].next = NULL; // assign NULL to next of node[2]


    int num;
    scanf("%d", &num);

    N new;
    new.key = num;

    N *ptr;
    N *prv_ptr = NULL;

    ptr = &first;     //ptr has node[0]'s address

    insert_num(&ptr, &prv_ptr, &first, new, num);// should i put node?

    return 0;
}

int insert_num(struct NODE *ptr, struct NODE *prv_ptr, struct NODE *first, struct NODE new, int num){
    /*if(ptr->key > num){
        first->next = &new;
        new.next = &ptr;
        printf("key inserted\n");
        return 1; //success
    }*/
    prv_ptr = ptr;
    ptr = ptr->next;
    
    while (ptr){
        if (ptr->key == num){
            printf("The key already exists\n");
            return 0;
        }
        if (ptr->key > num){
            prv_ptr->next = &new;
            new.next = ptr;
            printf("key inserted\n");
            return 1; // success
        }
        prv_ptr = ptr;
        ptr = ptr->next;
    }
    prv_ptr->next = &new;
    printf("key inserted\n");
    return 1;
}