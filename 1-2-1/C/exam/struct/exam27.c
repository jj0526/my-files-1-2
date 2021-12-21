#include <stdio.h>
int puzzle(int n);

int main(){
    int n;
    scanf("%d", &n);

    printf("%d", puzzle(n));

    return 0;
}

int puzzle(int n){
    if (n==1)
        return 1;
    if (n%2==0){
        return (puzzle(n/2)+n);
    }
    else{
        return (puzzle(3*n+1));
    }
}