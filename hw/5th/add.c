#include <stdio.h>

int main(){
    int a[10] = {10,20,30,40};
    int n;
    scanf("%d", &n);

    int res = sum_of(a, n);

    printf("%d", res);
}

int sum_of(int a[], int n){
    int sum = 0;
    int i = 0;
    if(n<2){
        return a[0];
    }

    return (a[n-1] + sum_of(a, n-1));

}