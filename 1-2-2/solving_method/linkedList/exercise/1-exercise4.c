#include <stdio.h>
#include <stdlib.h>

struct NODE{
    int key;
    struct NODE *next;
}; // declares struct NODE

int main(){
    struct NODE *node0 = (struct NODE*)malloc(sizeof(struct NODE)); // allocates the memory for *node0
    struct NODE *node1 = (struct NODE*)malloc(sizeof(struct NODE)); // allocates the memory for *node1
    struct NODE *node2 = (struct NODE*)malloc(sizeof(struct NODE)); // allocates the memory for *node2
    node0->next = node1; // assign the address of node1 to next of node0
    node1->next = node2; // assign the address of node2 to next of node1
    node0->key = 100; // assign integer 100 into key of node0
    node1->key = 200; // assign integer 200 into key of node1
    node2->key = 300; // assign integer 300 into key of node2
    node2->next = NULL; // assign NULL to next of node2

    free(node0);
    free(node1);
    free(node2); // free the memory allocated

    return 0;
}