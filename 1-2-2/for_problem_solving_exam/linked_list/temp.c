#include <stdio.h>
#include <stdlib.h>


int main(){
    int *nums, i;
    nums = (int *)malloc(10 * sizeof(int));
    if (nums==NULL){
        printf("malloc failed");
        return 0;
    }
    for (i = 0; i<10; i++){
        printf(":");
        scanf("%d", &nums[i]);
    }
    for (i = 0; i<10; i++) printf("%d", nums[i]);
    free(nums);
}