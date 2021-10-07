#include <stdio.h>
int includes(char search_string[], int size);
void divide(char search_string[], char divided1[], char divided2[], int size);
int find_substring(char string[], char search_string[], int size, int search_size);
int find_substring_with_wildcard(char string[], char divided1[], char divided2[], int size, int divided1_size, int divided2_size, char matched_string[]);
int str_length(char str[]);
int find_first_match(char string[], char search_string[], int size, int search_size);
int count_white_space_between(char string[], int size);
void* reset_array(void* ptr, unsigned int num);
//declartion of functions prototypes

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
 *      This file contains code which finds the exact string or partial string.
 *      Functions allow the user of the software to see the result of finding the exact strings
 *      or partial strings. It works with both finding exact strings without '*'
 *      and partial strings with '*'.
 *
*/

int main(){
    char string[maxSize];
    for (int i = 0; i < 5; ++i){
        printf("input a string\n");
        scanf(" %[^\n]", string);                                   // saves the sentence into string
        int size = str_length(string);                              //calls the function str_length
        char search_string[20];

        printf("input the string you want to find\n");
        scanf(" %[^\n]", search_string);                            //saves the word you want to find into search_string

        int search_size = str_length(search_string);                // calls the function str_length
        int wildcard_check = includes(search_string, search_size);  // calls the function wildcard_check
        
        while(wildcard_check == -1){
            printf("input the string you want to find again\n");
            scanf(" %[^\n]", search_string);
            wildcard_check = includes(search_string, search_size);              //calls the function includes
        }//re-request the sentence and saves into search_string until it becomes available

        if (wildcard_check){
            char divide1[20], divide2[20];
            reset_array(divide1, 20);                           //calls the function reset_array
            reset_array(divide2, 20);                           //calls the function reset_array
            divide(search_string, divide1, divide2, search_size);//calls the function divide
            int divide1_size = str_length(divide1);             // divide1's size
            int divide2_size = str_length(divide2);             // divide2's size
            char matched_string[maxSize];
            reset_array(matched_string, maxSize);               //calls the function reset_array
            int match_count = find_substring_with_wildcard(string, divide1, divide2, size, divide1_size, divide2_size, matched_string);     //calls the function match_count
            
            if (match_count > 0){
                if (match_count==1){
                    printf("Match : %s\ntotal : %d case\n", matched_string, match_count);        //shows the matched strings and the number of matched cases 
                }
                else{
                    printf("Match : %s\ntotal : %d cases\n", matched_string, match_count);       //shows the matched strings and the number of matched cases 
                }
            }
            else{
                printf("no matched string\n");
            }
        }
        else{
            int match_count = find_substring(string, search_string, size, search_size);          //calls the function match_count

            if (match_count > 0){                                                                //if there's any matched cases
                printf("%d case(s) found\n", match_count);
            }
            else{
                printf("not found\n");
            }
        }
    }
    return 0;
}

/**
 * 
 * int includes(char search_string[], int size)
 * 
 * Summary of the includes function:
 *      
 *      The includes function counts the number of '*' and ' ' and checks 
 *      if they're right string
 * 
 * Parameters :
 *       array : containing characters, int : integer number
 * 
 * Return Value : integer number -- Note : Modifies the array "in place".
 *                  avaiable : returns -1, 0 or 1
 *                                  -1 : not available
 *                                       0 : exact string
 *                                            1 : partial string
 * 
 * Description:
 * 
 *      This function utilizes counting . . .
 *      Note, the array is modified in place.
 * 
 * counting the number of '*', and ' ' available : returning 1   else : 0
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
        return num_of_asterisk;                     //returns the number of sterisks in search_string               NOTE : we only return the positive value
    }
    else{
        return -1;                                   // returns -1 (not available)
    }
}

/**
 * 
 * void divide(char search_string[], char divided1[], char divided2[], int size)
 * 
 * Summary of the divide function :
 * 
 *      The divide function, divides the search string into 2 strings (left side and right side of "*")
 * 
 * Parameters : 
 *          array : containing characters
 *          int : integer number
 * 
 * Return Value : 
 *          Nothing  -- Note : modifies the arrays "in place".
 * 
 * Description:
 *          Note, the arrays are modified in place 
 *
*/

void divide(char search_string[], char divided1[], char divided2[], int size){
    int loc;        // index of "*"
    for (int i=0; i<size; i++){
        if (search_string[i] == '*'){
            loc = i;                    // saves the index of '*'
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

/**
 * 
 * int find_substring(char string[], char search_string[], int size, int search_size)
 * 
 * Summary of the find_substring function : 
 * 
 *      The find_substring function, counts the number of search string in string
 * 
 * Parameters   :
 *              array : containing characters
 *              int : containing an integer
 * 
 * Return Value : integer       -- Note : modifies the arrays "in place"
 * 
 * Description :
 * 
 *      This function utilizes strstr function . . .
 *      Note, the arrays are modified in place. 
 *
*/

int find_substring(char string[], char search_string[], int size, int search_size){
    int count_of_search_string = 0; 
    int temp = 0;                       //index of the match

    int first_match = find_first_match(string, search_string, size, search_size);           // calls the function find_first_match

    while(first_match > -1){
        temp = find_first_match(string + first_match + search_size, search_string, size - first_match, search_size);    //calls the function find_first_match
        count_of_search_string++;

        if (temp>-1){                               //if it found matched string
            first_match =  first_match + search_size + temp;
        }
        else{
            first_match = -1;                       // escapes from while loop
        }

    }

    return count_of_search_string;                  // returns the number of count_of_search_string;        NOTE : we only return 0 and positive numbers
}

/**
 * int find_substring_with_wildcard(char string[], char divided1[], char divided2[], int size, int divided1_size, int divided2_size, char matched_string[])
 * 
 * Summary of the find_substring_with_wildcard :
 *      The find_substring_with_wildcard, finds the partial string and saves into the string matched_string.
 * 
 * Parameters   :
 *          array : containing characters
 *          int : containing an integer number
 * 
 * Return Value : integer number -- Note : modifies the arrays "in place".
 * 
 * Description : 
 * 
 * 
 * NOTE : exception - ex) hong dong hong dong   partial string : hong*dong     count : 2
 * 
 *      This function utilizes strstr function . . .
 *      Note, the arrays are modified in place.
 * 
*/

int find_substring_with_wildcard(char string[], char divided1[], char divided2[], int size, int divided1_size, int divided2_size, char matched_string[]){
    int count_of_search_string = 0;
    int matched_string_index = 0;
    int temp = 0;
    int divided1_match = find_first_match(string, divided1, size - divided2_size, divided1_size); // calls the function find_first_match

    while(divided1_match > -1){
        int divided2_match = divided1_match + divided1_size + find_first_match(string + divided1_match + divided1_size, divided2, size - divided1_match - divided1_size + 1, divided2_size);
        // calls the function find_first_match and find the index of divided2[0] in the string
        if (divided2_match < divided1_match + divided1_size){ // if find_first_match(...) was negative and if divided2 is not found
            break;
        }
        // if divided2 is found
        if (count_white_space_between(string + divided1_match, divided2_match - divided1_match) > 2){//calls the function count_white_space_between and checks if there are spaces more than 2
            temp = find_first_match(string + divided1_match + divided1_size, divided1, size - divided2_size - divided1_match - divided1_size + 1, divided1_size);//calls the function and find next divided1 ex) 2nd hong in hong hong gil dong
            if (temp>-1){
                divided1_match = divided1_match + divided1_size + temp; // saves new index of divided1 into divided1_match
            }
            else{
            divided1_match = temp; // saves temp into divided1_match    ex) hong go gil dong
            }
            continue;
        }

        count_of_search_string++;       //concat matched_string

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
        //calls the function find_first_match and find the substring
        if (temp>-1){
            divided1_match = divided1_match + divided1_size + temp; // saves new index of divided1 into divided1_match
        }
        else{
            divided1_match = temp;          //temp == -1, so it escapes from while loop
        }
    }
    return count_of_search_string;
}

/**
 * 
 * int str_length(char str[])
 * 
 * Summary of the str_length function :
 * 
 *      The str_length function, shows the size of string str
 * 
 * Parameters : 
 *          array : containing characters
 * 
 * Return Value : integer number -- Note : modifies the array "in place"
 * 
 * Description :
 * 
 *      This function utilizes strlen function . . .
 *      Note, the array is modified in place
 *  
*/

int str_length(char str[]){
    int len_of_str = 0;
    while(str[len_of_str]!=0){
        len_of_str++;   // counts the size of the string str
    }
    return len_of_str; // returns the length of the string str
}

/**
 * 
 * int find_first_match(char string[], char search_string[], int size, int search_size)
 * 
 * Summary of the find_first_match function :
 * 
 *      The find_first_match function, find the exact string of search_string in the string string 
 *      and shows the index of it.
 * 
 * Parameters :
 *          array : containing characters
 *          int : containing a integer
 * 
 * Return Value : integer  -- Note : modifies the arrays "in place".
 * 
 * Description:
 * 
 *      This function utilizes strstr function . . .
 *      Note, the arrays are modifies in place.
 * 
*/

int find_first_match(char string[], char search_string[], int size, int search_size) {
    for (int i = 0; i < size - search_size + 1; ++i) {
        if (string[i] == search_string[0]) {
            for (int j = 0; string[i + j] == search_string[j]; ++j) {
                if (j == search_size - 1) {
                    return i;           // returns the first index of search_string in string
                }
            }
        }
    }
    return -1;
}

/**
 * 
 * int count_white_space_between(char string[], int size)
 * 
 * Summary of the count_white_space_between function :
 * 
 *      The count_white_space_between function, counts the number of ' 's in the string
 * 
 * Parameters : 
 *          array : containing characters
 *          int : containing an integer
 * 
 * Return Value : integer -- Note : Modifies the array "in place".
 * 
 * Description :
 * 
 *      Thie function utilizes counting a character. . .
 *      Note, the array is modified in place.
 * 
*/

int count_white_space_between(char string[], int size){
    int count_white_space = 0;
    for (int i = 0; i<size; i++){
        if (string[i]==' '){
            count_white_space ++;   // counts the number of ' '
        }
    }
    return count_white_space;       // returns the number of ' '
}

/**
 * 
 * void* reset_array(void* ptr, unsigned int num)
 * 
 * Summary of the reset_array function :
 * 
 *      the reset_array function, resets the give array (saving NULL)
 * 
 * Parameters :
 *      ptr : a pointer to an array (void pointer)
 *      num : size of array passed by ptr (unsigned integer)
 * 
 * Return Value : void pointer
 *      Note : returns any type of pointer
 * 
 * Description :
 * 
 *      This function utilizes the function memset in string.h
 *      Note : ptr is a void pointer, so that we can pass any type of pointer to this function.
 *      
*/

void* reset_array(void* ptr, unsigned int num){
    char* temp = (char*)ptr;
    for (int i = 0; i<num; i++){
        temp[i] = 0;    //saves NULL into temp[i]
    }
    return ptr;         //returns the original pointer
}