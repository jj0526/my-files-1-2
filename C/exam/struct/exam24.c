#include <stdio.h>
int sum_of(int a[], int n);

int main(){
    int a[100];
    int n;
    scanf("%d", &n);
    for (int i = 0; i<n; i++){
        scanf("%d", &a[i]);
    }
    printf("%d", sum_of(a, n-1));

    return 0;

}
int sum_of(int a[], int n){
    if (n==0){
        return a[0];
    }
    return a[n]+sum_of(a,n-1);
}