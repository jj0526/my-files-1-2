#include <stdio.h>

struct Node{
    int key;
    struct Node *next;
};

int main(){
    struct Node my_node[3];
    my_node[0].next = &my_node[1];
}