#include <stdio.h>

int character_count(char string[], int size);

int main(){
    char string[100];
    int size = 100;

    printf("what's the sentence?\n");

    gets(string);                                //input a string

    int char_cnt = character_count(string, size);//functions

    printf("%d", char_cnt);

}

int character_count(char string[], int size){

    int cnt= 0;
    for (int i = 0; i<size; i++){
        if(string[i]==NULL){
            break;                //if string[i]==NULL, done
        }
        if (string[i]!=' '){
            cnt++;                //counting the number of characters
        }
    }

    return cnt;                   //returns cnt

}