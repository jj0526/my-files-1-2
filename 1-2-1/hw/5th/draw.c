#include <stdio.h>

void wrt_backward(void);

void main(){
    printf("input a line");
    wrt_backward();
    printf("\n");
}

void wrt_backward(){
    int c;
    if ((c==getchar())!='\n')
        wrt_backward();
    putchar(c);
}