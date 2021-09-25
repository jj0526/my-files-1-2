#include <stdio.h>

void strcopy(char string1[], int size, char string2[]);

int main(){
    char string1[100], string2[100];
    int size = 100;

    printf("what's the sentence\n");
    gets(string2);                  //inputs a string

    strcopy(string1, size, string2);//functions

    return 0;
}

void strcopy(char string1[], int size, char string2[]){
    int i = 0;
    while (string2[i]!='\0'){
        string1[i] = string2[i];//copy on index i
        i++;
    }
    string1[i] = '\0';         //string1 ends with '\0'

    puts(string1); //prints string1

}