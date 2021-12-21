#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
    int c;
    srand(time(NULL));
    c = rand()%10;
    printf("%d", c);
}