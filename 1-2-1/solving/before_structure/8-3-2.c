#include <stdio.h>

void show(float rates[], int size);

int main(){
    float rates[10] = {6.5, 8.2, 8.5, 8.3, 8.6, 9.4, 9.6, 9.8, 10.0};// stored 9 numbers

    int size = 9;
    show(rates, size); // recalls the function show

    return 0;
    
}
/*
    shows() displays the numbers in the array
*/
void show(float rates[], int size){
    for (int i = 0; i<size; i++){
        printf("%.1f ", rates[i]); // prints rates[i] (0 into 9)
    }
}