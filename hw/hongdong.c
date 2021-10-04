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

    int size;                    // size of search_string

    printf("input a string\n");
    gets( string);
    printf("%s", string);

    printf("input the string you want to find\n");
    while(1){
        gets(search_string);
        printf("search_string : %s", search_string);
        size = strlen(search_string);
        printf("size : %d", size);
        check = includes(search_string, size);
        if (check == 1){
            break;
        }
        printf("%d", check);
    }
    printf("returned check : %d", check);
    
    divide(search_string, divided1, divided2, size);

    int cursor1 = 0, cursor2 = 0, ori = 0, divided1_count = 0;

    int len = strlen(string);

    printf("len of string : %d", len);

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
    for (int i = 0; i<25; i++){
        if (first[i]!=NULL){
            printf("%d ", first[i]);
        }
        else{
            break;
        }
    }
    for (int i = 0; i<25; i++){
        if (second[i]!=NULL){
            printf("%d ", second[i]);
        }
        else{
            break;
        }
    }
    

    //   i am hong gil dong
}
/**
 * 
 * counting the number of '*', and ' ' available : returning 1   else : 0


*/
int includes(char search_string[], int size){
    int num_of_asterisk = 0;
    for (int i = 0; i<size; i++){
        if(search_string[i] == '*'){
            num_of_asterisk++;
        }
        printf("%d ",i );
    }
    printf("asterisk : %d", num_of_asterisk);
    if (num_of_asterisk==1){
        return 1;
    }
    else{
        return 0;
    }
}
//hong*dong   size : 9
void divide(char search_string[], char divided1[], char divided2[], int size){
    int loc; // index of "*"
    puts(search_string);
    for (int i=0; i<size; i++){
        if (search_string[i] == '*'){
            loc = i;
            divided1[i] = 0;
            break;
        }
        divided1[i] = search_string[i];
    }
    // loc = 4
    for (int i = loc+1; i<size; i++){
        divided2[i-loc-1] = search_string[i];
        if (search_string[i]==0){
            divided2[i-loc-1] = 0;
            break;
        }
    }
}