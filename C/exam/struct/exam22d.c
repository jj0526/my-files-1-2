#include <stdio.h>
void wrt_backward(void);

int main(){
    wrt_backward();
    printf("\n");

    return 0;
}

void wrt_backward(){
    int c;
    if ((c=getchar())!='\n')
        wrt_backward();
    putchar(c);
}