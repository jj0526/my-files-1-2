#include <stdio.h>
int includes(char search_string[], int size);
void divide(char search_string[], char divided1[], char divided2[], int size);
int find_substring(char string[], char search_string[], int size, int search_size);
int find_substring_with_wildcard(char string[], char divided1[], char divided2[], int size, int divided1_size, int divided2_size, char matched_string[]);
int str_length(char str[]);
int find_first_match(char string[], char search_string[], int size, int search_size);
int count_white_space_between(char string[], int size);
void* reset_array(void* ptr, int value, unsigned int num);
const int maxSize = 4096;
/**
 * File : my_hong.c
 * 
 * Author : Jeon Sihyeon (wjstlgus13@gachon.ac.kr)
 * Date : 10/06/2021
 * Partner : I worked alone
 * Course : Problem Solving Methods (13967_001)
 * 
 * Summary of File :
 * 
 *  ////////////////////
 * 
*/
int main(){
    char string[maxSize];
    for (int i = 0; i < 5; ++i){
        printf("input a string\n");
        scanf(" %[^\n]", string);                                   // saves the sentence into string
        printf("%s\n", string);
        int size = str_length(string);
        char search_string[20];

        printf("input the string you want to find\n");
        scanf(" %[^\n]", search_string);                            //saves the word you want to find into search_string

        int search_size = str_length(search_string);
        int wildcard_check = includes(search_string, search_size);
        
        while(wildcard_check == -1){
            printf("input the string you want to find again\n");
            scanf(" %[^\n]", search_string);
            printf("search_string : %s\n", search_string);
            wildcard_check = includes(search_string, search_size);
        }//re-input the sentence into search_string until it becomes available

        if (wildcard_check){
            char divide1[20], divide2[20];
            reset_array(divide1, 0, 20);
            reset_array(divide2, 0, 20);
            divide(search_string, divide1, divide2, search_size);
            int divide1_size = str_length(divide1);             // divide1's size
            int divide2_size = str_length(divide2);             // divide2's size
            char matched_string[maxSize];
            reset_array(matched_string, 0, maxSize);
            int match_count = find_substring_with_wildcard(string, divide1, divide2, size, divide1_size, divide2_size, matched_string);
            
            printf("match_count : %d\n", match_count);
            
            if (match_count > 0){
                if (match_count==1){
                    printf("Match : %s\ntotal : %d case\n", matched_string,match_count);
                }
                else{
                    printf("Match : %s\ntotal : %d cases\n", matched_string,match_count);
                }
            }
            else{
                printf("no matched string\n");
            }
        }
        else{
            int match_count = find_substring(string, search_string, size, search_size);

            if (match_count > 0){
                printf("\n%d case(s) found\n", match_count);
            }
            else{
                printf("\nnot found\n");
            }
        }
    }
    return 0;
}
/**
 * 
 * counting the number of '*', and ' ' available : returning 1   else : 0
 * 
 * 


*/
int includes(char search_string[], int size){
    int num_of_asterisk = 0;
    int num_of_space = 0;
    for (int i = 0; i<size; i++){
        if(search_string[i] == '*'){
            num_of_asterisk++;                      // counting the number of wildcards
            if ((i==0) || (i == size - 1)){
                return -1;                          // returns -1 (not available)
            }
        }
        if (search_string[i] == ' '){
            num_of_space ++;                        // counting the number of spaces
        }
    }
    if (((num_of_asterisk==1)&&(num_of_space == 0))||((num_of_asterisk ==0)||(num_of_space==1))){
        return num_of_asterisk;                     //returns the number of sterisks in search_string 
    }
    else{
        return -1;                                   // returns -1 (not available)
    }
}
//hong*dong   size : 9
void divide(char search_string[], char divided1[], char divided2[], int size){
    int loc;        // index of "*"
    puts(search_string);
    for (int i=0; i<size; i++){
        if (search_string[i] == '*'){
            loc = i;
            divided1[i] = 0;            // saves 0 in the end of the string divided1
            break;
        }
        divided1[i] = search_string[i]; // saves search_string[i] into divided1[i] before *
    }
    for (int i = loc+1; i<size+1; i++){
        if (search_string[i]==0){
            divided2[i-loc-1] = 0;      // saves 0 in the end of the string divided2
            break;
        }
        divided2[i-loc-1] = search_string[i]; // saves search_string[i] into divided2[i-loc-1]
    }
}

int find_substring(char string[], char search_string[], int size, int search_size){
    int count_of_search_string = 0;
    int temp = 0;                       //index of the match

    int first_match = find_first_match(string, search_string, size, search_size);

    while(first_match > -1){
        temp = find_first_match(string + first_match + search_size, search_string, size - first_match, search_size);
        count_of_search_string++;
        if (temp>-1){
            first_match =  first_match + search_size + temp;
        }
        else{
            first_match = -1;
        }

    }

    return count_of_search_string;              // returns the number of count_of_search_string;
}

int find_substring_with_wildcard(char string[], char divided1[], char divided2[], int size, int divided1_size, int divided2_size, char matched_string[]){
    int count_of_search_string = 0;
    int matched_string_index = 0;
    int temp = 0;
    int divided1_match = find_first_match(string, divided1, size - divided2_size, divided1_size);

    printf("%d", divided1_match);

    while(divided1_match > -1){
        int divided2_match = divided1_match + divided1_size + find_first_match(string + divided1_match + divided1_size, divided2, size - divided1_match - divided1_size + 1, divided2_size);
        
        if (divided2_match < divided1_match + divided1_size){ // if find_first_match(...) was negative
            temp = find_first_match(string + divided1_match + divided1_size, divided1, size - divided2_size - divided1_match - divided1_size + 1, divided1_size);
            // since it's in while and i need to put a "continue" on the next
            if (temp>-1){
                divided1_match = divided1_match + divided1_size + temp;
            }
            else{
            divided1_match = temp;
            }
            continue;
        }
        if (count_white_space_between(string + divided1_match, divided2_match - divided1_match) > 2){
            temp = find_first_match(string + divided1_match + divided1_size, divided1, size - divided2_size - divided1_match - divided1_size + 1, divided1_size);

            if (temp>-1){
                divided1_match = divided1_match + divided1_size + temp;
            }
            else{
            divided1_match = temp;
            }
            continue;
        }
        count_of_search_string++;
        //concat matched_string
        if (count_of_search_string != 1){
            matched_string[matched_string_index] = ',';
            matched_string_index++;
            matched_string[matched_string_index] = ' ';
            matched_string_index++;
        } // if count_of_search_string != 1, adds ", "
        for (int i = divided1_match; i < divided2_match + divided2_size; ++i){
            matched_string[matched_string_index] = string[i];
            matched_string_index++;
        } // saves string[i] into matched_string[matched_string_index]

        temp = find_first_match(string + divided1_match + divided1_size, divided1, size - divided2_size - divided1_match - divided1_size + 1, divided1_size);
        //calls the function find_first_match
        if (temp>-1){
            divided1_match = divided1_match + divided1_size + temp;
        }
        else{
            divided1_match = temp;
        }
    }
    return count_of_search_string;
}
int str_length(char str[]){
    int len_of_str = 0;
    while(str[len_of_str]!=0){
        len_of_str++;
    }
    return len_of_str;
}

int find_first_match(char string[], char search_string[], int size, int search_size) {
    for (int i = 0; i < size - search_size + 1; ++i) {
        if (string[i] == search_string[0]) {
            for (int j = 0; string[i + j] == search_string[j]; ++j) {
                if (j == search_size - 1) {
                    return i;
                }
            }
        }
    }
    return -1;
}

int count_white_space_between(char string[], int size){
    int count_white_space = 0;
    for (int i = 0; i<size; i++){
        if (string[i]==' '){
            count_white_space ++;
        }
    }
    return count_white_space;
}
void* reset_array(void* ptr, int value, unsigned int num){
    char* temp = (char*)ptr;
    for (int i = 0; i<num; i++){
        temp[i] = value;
    }
    return ptr;
}