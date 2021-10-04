#include <stdio.h>
int includes(char search_string[], int size);
void divide(char search_string[], char divided1[], char divided2[], int size);
int find_substring(char string[], char search_string[], int size, int search_size);
int find_substring_with_wildcard(char string[], char divided1[], char divided2[], int size, int divided1_size, int divided2_size, char matched_string[]);
int str_length(char str[]);
int find_first_match(char string[], char search_string[], int size, int search_size);
int count_white_space_between(char string[], int size);
void* memset(void* ptr, int value, unsigned int num);
const int maxSize = 4096;

int main(){
    char string[maxSize];
    for (int i = 0; i < 5; ++i){
        printf("input a string\n");
        scanf(" %[^\n]", string);    // i am hong gil dong
        printf("%s\n", string);
        int size = str_length(string);
        char search_string[20];
        int wildcard_check;
        printf("input the string you want to find\n");
        scanf(" %[^\n]", search_string);
        printf("search_string : %s\n", search_string);
        int search_size = str_length(search_string);
        wildcard_check = includes(search_string, search_size);
        while(wildcard_check == -1){
            printf("input the string you want to find again\n");
            scanf(" %[^\n]", search_string);
            printf("search_string : %s\n", search_string);
            wildcard_check = includes(search_string, search_size);
        }
        if (wildcard_check){
            char divide1[20], divide2[20];
            memset(divide1, 0, 20);
            memset(divide2, 0, 20);
            divide(search_string, divide1, divide2, search_size);
            int divide1_size = str_length(divide1);
            int divide2_size = str_length(divide2);
            char matched_string[maxSize];
            memset(matched_string, 0, maxSize);
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


*/
int includes(char search_string[], int size){
    int num_of_asterisk = 0;
    int num_of_space = 0;
    for (int i = 0; i<size; i++){
        if(search_string[i] == '*'){
            num_of_asterisk++;
            if (i==0 || i == size - 1){
                return -1;
            }
        }
        if (search_string[i] == ' '){
            num_of_space ++;
        }
    }
    if (((num_of_asterisk==1)&&(num_of_space == 0))||((num_of_asterisk ==0)||(num_of_space==1))){
        return num_of_asterisk;
    }
    else{
        return -1;
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
    for (int i = loc+1; i<size+1; i++){
        if (search_string[i]==0){
            divided2[i-loc-1] = 0;
            break;
        }
        divided2[i-loc-1] = search_string[i];
    }
}

int find_substring(char string[], char search_string[], int size, int search_size){
    int count_of_search_string = 0;
    int temp;
    for (int first_match = find_first_match(string, search_string, size, search_size);
        first_match > -1;
        first_match = (temp = find_first_match(string + first_match + search_size, search_string, size - first_match, search_size)) > -1 ? first_match + search_size + temp : -1){
        count_of_search_string++;
    }
    return count_of_search_string;              // returns the number of count_of_search_string;
}
int find_substring_with_wildcard(char string[], char divided1[], char divided2[], int size, int divided1_size, int divided2_size, char matched_string[]){
    int count_of_search_string = 0;
    int matched_string_index = 0;
    int temp = 0;
    for (int divided1_match = find_first_match(string, divided1, size - divided2_size, divided1_size);
        divided1_match > -1;
        divided1_match = ((temp = find_first_match(string + divided1_match + divided1_size, divided1, size - divided2_size - divided1_match - divided1_size + 1, divided1_size)) > -1 ?
        divided1_match + divided1_size + temp: temp)){
        int divided2_match = divided1_match + divided1_size + find_first_match(string + divided1_match + divided1_size, divided2, size - divided1_match - divided1_size + 1, divided2_size);
        if (divided2_match < divided1_match + divided1_size)
            continue;
        if (count_white_space_between(string + divided1_match, divided2_match - divided1_match) > 2)
            continue;
        count_of_search_string++;
        //concat matched_string
        if (count_of_search_string != 1){
            matched_string[matched_string_index] = ',';
            matched_string_index++;
            matched_string[matched_string_index] = ' ';
            matched_string_index++;
        }
        for (int i = divided1_match; i < divided2_match + divided2_size; ++i){
            matched_string[matched_string_index] = string[i];
            matched_string_index++;
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
void* memset(void* ptr, int value, unsigned int num){
    char* temp = (char*)ptr;
    for (int i = 0; i<num; i++){
        temp[i] = value;
    }
    return ptr;
}