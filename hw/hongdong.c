#include <stdio.h>
int includes(char search_string[], int size);
void divide(char search_string[], char divided1[], char divided2[], int size);

int main(){
    int count = 0;
    char string[100];
    char search_string[20];
    char divided1[20];
    char divided2[20];

    int check;

    int size;

    printf("input a string\n");
    gets(string);
    printf("%s", string);

    printf("input the string you want to find\n");
    while(1){
        puts(search_string);
        printf("%s", search_string);
        size = strlen(search_string);
        printf("%d", size);
        check = includes(search_string, size);
        if (check == 1){
            break;
        }
    }
    
    divide(search_string, divided1, divided2, size);

    printf("%s %s", divided1, divided2);

    int cursor1 = 0, cursor2 = 0, ori = 0, divided1_count = 0;

    int len = strlen(string);

    char first[25], second[25]; // indexs of divided1 and divided2
    int first_count = 0, second_count = 0;

    
    while(string[cursor1]!=NULL){
        ori = 0;
        while(1){
            if(string[cursor1]==divided1[ori]){
                if (ori == strlen(divided1)){
                    first[first_count] = cursor1-strlen(divided1);
                    first_count++;
                }
            }
            else{
                break;
            }
            cursor1++;
            ori++;
        }
        cursor1++;
        printf("%d", cursor1);
    }
    cursor1 = 0;
    while(string[cursor1!=NULL]){
        ori = 0;
        while(1){
            if(string[cursor1]==divided2[ori]){
                if (ori == strlen(divided1)){
                    second[second_count] = cursor1-strlen(divided2);
                    second_count++;
                }
            }
            else{
                break;
            }
            cursor1++;
            ori++;
        }
         cursor1++;
    }
    

    //   i am hong gil dong
}

int includes(char search_string[], int size){
    for (int i = 0; i<size; i++){
        if(search_string[i] == '*'){
            return 1;
        }
        printf("%d",i );
    }
    return 0;
}

void divide(char search_string[], char divided1[], char divided2[], int size){
    int loc; // index of "*"
    for (int i=0; i<size; i++){
        if (search_string[i] == '*'){
            loc = i;
            divided1[i] = NULL;        
            break;
        }
        printf("%d", i);
        divided1[i] = search_string[i];
    }

    for (int i = loc+1; i<size; i++){
        divided2[i-loc-1] = search_string[i];
        if (search_string[i]==NULL){
            break;
        }
    }   
}