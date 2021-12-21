#include <stdio.h>

int stack[5];
int front = -1, back = -1;

void enQueue(int num);
int deQueue();
int is_full();
int is_empty();

int main(){
    int num;
    scanf("%d", &num);

    enQueue(num);
    enQueue(2);
    enQueue(3);
    enQueue(4);
    enQueue(6);
    enQueue(7);
    int dequeue_res = deQueue();
    if (dequeue_res==-1)
        printf("failed to dequeue\n");
    else{
        printf("dequeued successfully\n");
    }
    dequeue_res = deQueue();
    dequeue_res = deQueue();
    enQueue(4);

    for (int i = 0; i<5; i++){
        printf("%d ", stack[i]);
    }
}

void enQueue(int num){
    if(back==-1){
        front++;
        back++;
        stack[0] = num;
        
    }
    else if(is_full()==0){
        back++;
        stack[back%5] = num;
    }
    else{
        stack[back%5] = num;
    }
    for (int i = 0; i<5; i++){
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int deQueue(){
    if(is_empty()==-1)
        return -1;   // failed to dequeue
    stack[front%5] = 0;
    front++;
    return 0;
}

int is_full(){
    if(front%5==(back+1)%5){
        return -1; //full
    }
    else
        return 0; // not full
}

int is_empty(){
    if(back%5 == (front+1)%5)
        return -1;   //empty
    return 0;        //not empty
}