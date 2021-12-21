#include <stdio.h>
#include <stdlib.h>


struct NUM{
    int key;
    struct NUM *next;
};

int main(){
    int nums[10] = {17, 39, 11, 9, 42, 12, 15, 8, 13, 41};

    struct NUM number[10];
    for (int i = 0; i<10; i++){
        number[i].key = nums[i];
    }

    for (int i = 0; i<9; i++){
        number[i].next = &number[i+1];
    }
    number[9].next = NULL;

    struct NUM temp;

    for (int i = 0; i<10; i++){
        for (int j = i; j<10; j++){
            if (number[i].key>number[j].key){
                temp.key = number[i].key;
                number[i].key = number[j].key;
                number[j].key = temp.key;
            }
        }
    }
    struct NUM *head = (struct NUM*)malloc(sizeof(struct NUM));
    head = &number[0];

    struct NUM *ptr = (struct NUM*)malloc(sizeof(struct NUM));
    ptr = &number[0];

    while (ptr){
        printf("%d ", ptr->key);
        ptr = ptr->next;
    }

    return 0;
}