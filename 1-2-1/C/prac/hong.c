#include <stdio.h>
void wildcard(char string[], char search_string[], char first[], char second[]);
int strlen(char string[]);
int strlen(char string[]);

int main(){
    char string[500];
    char search_string[100];
    char first[100];
    char second[100];

    printf("string : ");
    scanf(" %[^\n]", string);
    printf("search string : ");
    scanf(" %[^\n]", search_string);

    wildcard(string, search_string, first, second);

    printf("%s, %s\n", first, second);

}

void wildcard(char string[], char search_string[], char first[], char second[]){
    int len = strlen(search_string);
    int index_of_wildcard;
    for (int i = 0; i<len; i++){
        if (search_string[i]=='*'){
            index_of_wildcard = i;
            break;
        }
        first[i] = search_string[i];
    }
    first[index_of_wildcard] = NULL;
    for (int i = index_of_wildcard+1; i<len+1; i++){
        second[i-index_of_wildcard-1] = search_string[i];
    }
    second[len-index_of_wildcard] = NULL;
}

int strlen(char string[]){
    int j = 0;
    while(1){
        if (string[j]!=NULL){
            j++;
        }
        else{
            return j;
        }
    }
}
