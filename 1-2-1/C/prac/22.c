#include <stdio.h>

void wrt_backward();

int main(){
    wrt_backward();
    
    printf("\n");
    return 0;
}

void wrt_backward(){
    char c;
    if ((c=getchar())!='\n')
        wrt_backward();
    putchar(c);
}