#include <stdio.h>

int main(){
    int list[5] = {5, 10, 15, 25, 45};

    int lo = 0, hi = 4;
    int key;
    scanf("%d", &key);

    for (int i = 0; i<5; i++){
        scanf("%d", &list[i]);
    }

    printf("%d", bs(list, lo, hi, key ));
}

int bs(int list[], int lo, int hi, int key){
    int mid;

    if (lo>hi)
        return -1;
    mid = (lo+hi)/2;
    if (list[mid]==key)
        return 0;
    else if (list[mid]>key)
        bs(list, lo, mid-1, key);
    else if (list[mid]<key)
        bs(list, mid+1, hi, key);
}