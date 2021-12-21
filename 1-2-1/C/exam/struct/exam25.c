#include <stdio.h>

int main(){
    int array[8]={20, 30, 10, 50, 15, 45, 80, 25};
    int n = 4;

    printf("%d", add(array, n-1));

    return 0;

}

int add(int arr[], int n){
    if (n==0){
        return arr[0];
    }
    return arr[n] + add(arr, n-1);
}