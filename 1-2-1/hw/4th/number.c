#include <stdio.h>

int main(){
    int number;
    scanf("%d", &number);

    int number_of_asterisks;
    scanf("%d", &number_of_asterisks);

    while((number_of_asterisks<3)&&(number_of_asterisks>40)){
        printf("input the number again\n");
        scanf("%d", &number_of_asterisks);
    }

    if (number==8){
        printf("  ");
        for (int i = 0; i<number_of_asterisks; i++){
            printf("*");
        }
        printf("\n");
        printf("  ");
        for (int i = 0; i<number_of_asterisks; i++){
            printf("*");
        }
        printf("\n");
        for (int m = 0; m<2; m++){
            for (int i = 0; i<number_of_asterisks; i++){
                printf("**");
                for (int j = 0; j<number_of_asterisks; j++){
                    printf(" ");
                }
            }
        }
        printf("  \n");
        for (int i = 0; i<number_of_asterisks; i++){
            printf("*");
        }
        printf("\n");
        printf("  ");
        for (int i = 0; i<number_of_asterisks; i++){
            printf("*");
        }
        for (int m = 0; m<2; m++){
            for (int i = 0; i<number_of_asterisks; i++){
                printf("**");
                for (int j = 0; j<number_of_asterisks; j++){
                    printf(" ");
                }
            }
        }

    }
    return 0;
}

