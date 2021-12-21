#include <stdio.h>
int character_count(char array[]);

int main(){
    char array[100];

    scanf("%[^\n]", array);

    printf("%d", character_count(array));
}

int character_count(char array[]){
    int count = 0;
    for (int i = 0; i<100; i++){
        if (array[i] == ' '){
            count --;
        }
        if (array[i]=='\0'){
            return i+count;
        }
    }
}