#include <stdio.h>

struct car{
    int mirror;
    int aa;
    int ba;
}c[3] = {{2,3,4}, {5,6,7}, {8,9,10}};

int main(){
    printf("%d",c[1].ba);
    return 0;
}