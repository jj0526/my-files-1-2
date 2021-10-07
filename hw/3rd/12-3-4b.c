#include <stdio.h>

/**
 * File : 12-3-4b.c
 * 
 * Author : Jeon Sihyeon (wjstlgus13@gachon.ac.kr)
 * Date : 9/29/2021
 * Partner : I worked alone
 * Course : Problem Solving Methods (13967_001)
 * 
 * Summary of File : 
 *
 *      This file contains code which shows the recent date of any two dates.
 *      Functions allow the user of the software to see which date is 
 *      recent one of two dates.
 * 
*/

struct Date{
    int month;
    int day;
    int year;
};

struct Date recent(struct Date* first_date, struct Date* second_date);              // forward declaration

int main(){
    struct Date first, second;
    printf("What's the first date? MM/DD/YYYY (in integer)\n");
    while(1){
        scanf("%d %d %d", &first.month, &first.day, &first.year);
        if (((first.month > 0)&&(first.month<=12))&&((first.day>0)&&((first.day<=30)))&&(first.year>0)){
            break;     // if the date is available, escapes from the while
        }
        printf("check the date again\n");
    }
    printf("What's the second date? MM/DD/YYYY (in integer)\n");
    while(1){
        scanf("%d %d %d", &second.month, &second.day, &second.year);
        if ((((second.month>0)&&(second.month<=12))&&((second.day>0)&&((second.day<=30)))&&(second.year>0))||
        ((second.month!=first.month)&&(second.day != first.day)&&(second.year != first.year))){
            break;    // if the date is available and it's not the same as the first one, escapes from the while
        }
        printf("check the date again\n");
    }

    int res1 = recent(&first, &second).month;               // calls the function recent
    int res2 = recent(&first, &second).day;                 // calls the function recent
    int res3 = recent(&first, &second).year;                // calls the function recent

    printf("%d %d %d is the later date.\n", res1, res2, res3);

    return 0;

}

/**
 * 
 * struct Date recent(struct Date* first_date, struct Date* second_date)
 * 
 * Summary of the Recent function : 
 * 
 *      The Recent function return the the later date of any two dates passed to it.
 * 
 * Parameters : struct : containing integers
 * 
 * Return Value : struct -- Note : Modifies the struct "in place"
 * 
 * Description :
 * 
 *      This function utilizes comparing dates.
 *      Note , the struct is modified in place.
 * 
*/

struct Date recent(struct Date* first_date, struct Date* second_date){
    if ((first_date -> year) > (second_date -> year)){ // compares the year first
        return *first_date;
    }
    else if ((first_date->year) < (second_date->year)){
        return *second_date;
    }
    else{
        if (( first_date -> month ) > (second_date -> month)){ // compares the month second
            return *first_date;
        }
        else if (( first_date -> month ) < (second_date -> month)){
            return *second_date;
        }
        else{
            if (( first_date -> day ) > (second_date -> day)){  // compares the day last
                return *first_date;
            }
            else if (( first_date -> day ) < (second_date -> day)){
                return *second_date;
            }
            //The first date and second date can't be the same
        }
    }
}