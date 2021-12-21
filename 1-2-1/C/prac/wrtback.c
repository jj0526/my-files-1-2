#include <stdio.h>

int main(){
    wrt_back();

    return 0;
}

void wrt_back(){
    char c;
    if ((c = getchar())!='\n'){
        wrt_back();
    }
    putchar(c);
}