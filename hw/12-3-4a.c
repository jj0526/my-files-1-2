/**
 * 
 * File : 12-3-4a.c
 * 
 * Author : Jeon Sihyeon (wjstlgus13@gachon.ac.kr)
 * Date : 9/29/2021
 * Partner : I worked alone
 * Course : Problem Solving Methods (13967_001)
 * 
 * Summary of File:
 * 
 *      This file contains code shows the recent date of any two dates.
 *      Functions return the the later date of any two dates passed to it.
*/

struct Date{
    int month;
    int day;
    int year;
};
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
    if ((first_date -> year) > (second_date -> year)){               // compares the year first
        return *first_date;
    }
    else if ((first_date->year) < (second_date->year)){
        return *second_date;
    }
    else{
        if (( first_date -> month ) > (second_date -> month)){        // compares the month second
            return *first_date;
        }
        else if (( first_date -> month ) < (second_date -> month)){
            return *second_date;
        }
        else{
            if (( first_date -> day ) > (second_date -> day)){         // compares the day last
                return *first_date;
            }
            else if (( first_date -> day ) < (second_date -> day)){
                return *second_date;
            }
            //The first date and second date can't be the same
        }
    }
}