#include <stdio.h>

int main(){
    int num[20] = {5, 96, 76, 78, 93, 21, 4, 92, 82, 85, 87, 6, 72, 69, 85, 75, 81, 73};

    FILE *myfile;
    myfile = fopen("pro10text.txt", "w");

    int a[10], b[10], c[10];

    int i = 0;
    for (; i<num[0]; i++){
        a[i] = num[i+1];
    }
    int size = i+1;
    //printf("size : %d   ", size);
    for (i = 0; i<num[size]; i++){
        b[i] = num[i+size];
        printf("i : %d ", i);
    }
    size = i + size + 1;
    //printf("size : %d   ", size);
    for (i = 0; i<num[size]; i++){
        c[i] = num[i+size];
        printf("i : %d ", i);
    }
    i = 0;
    while (1)
    {
        if (b[i]==NULL){
            break;
        }
        printf("%d\n", b[i]);
        i++;
    }
    
}