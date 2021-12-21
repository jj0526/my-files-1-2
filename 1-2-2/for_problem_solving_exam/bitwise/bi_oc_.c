#include <stdio.h>
int myatoi(int num, int base, char arr[], int *is_negative);
int main(){
    int num, base;
    scanf("%d %d", &num, &base);

    int is_negative = 0;

    char arr[30];

    int len = myatoi(num, base, arr, &is_negative);

    if (is_negative==0){
        printf("%s", arr);
    }
    else{
        printf("-%s", arr);
    }
    return 0;
}

int myatoi(int num, int base, char arr[], int *is_negative){
    if (num==0)
        return 0;
    if (num<0){
        num = -1 * num;
        *is_negative = -1;
    }
    int index=0;
    if(base>9){
        while(1){
            printf("num/base : %d\n", num/base);
            
            index++;
            if (num/base>9){
                arr[index] = num/base + 'A' - 10;
            }
            else{
                arr[index] = num/base + '0';
            }
            printf("char : %c", arr[index]);
            num%=base;
            if (num/base==0){
                break;
            }
        }
        if (num>9){
            index++;
            arr[index] = 'A' + num; - 10;
        }
        else{
            index++;
            arr[index] = num + '0';
        }
        arr[index+1] = NULL;
    }
    else{
        while(1){
            printf("num : %d, base : %d, index : %d,  %d\n",num, base, index, num/base);
            arr[index] = num/base + '0';
            index++;
            num%=base;
            if(num/base==0){
                break;
            }
        }
        arr[index] = num + '0';
        index++;
        arr[index] = NULL;
    }
    printf("%s\n", arr);
    
    return index;
}