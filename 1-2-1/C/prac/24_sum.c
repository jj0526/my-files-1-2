#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int a[50];
    int size = 0;
    printf("input the size\n");
    scanf("%d", &size);
    for (int i = 0; i<size; i++){
        scanf("%d", &a[i]);
    }
    printf("%d", sum_of(a, n));
}

int sum_of(int a[], int n){
    int sum = 0;
    for (int i = 0; i<n; i++){
        sum+=a[i];
    }
    return sum;
}