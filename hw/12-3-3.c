#include <stdio.h>

struct Date{
    int month;
    int day;
    int year;
};

/**
 * File : 12-3-3.c
 * author : Jeon Sihyeon (wjstlgus13@gachon.ac.kr)
 * Date : 9/29/2021
 * Partner : I worked alone
 * Course : Problem Solving Methods (13967_001)
 * 
 * Summary of File : 
 * 
 *      This file contains code which counts the days from 1/1/2000.
 *      Functions allow the user of the software to input integers and 
 *      see the number of days from the date 1/1/2000.
 * 
*/

int Days(struct Date* new_date);                        // forward declaration

int main(){
    struct Date today;                                  // declare a new struct "today"
    printf("What's the date today? MM DD YYYY (int integer)");
    while(1){
        scanf("%d %d %d", &today.month, &today.day, &today.year);
        if (((today.month >0)&&(today.month<13))&&((today.day>0)&&(today.day<31))&&((today.year>=2000))){
            break;                                  // If the numbers are available, escapes from the while.
        }
        printf("input the MM/DD/YYYY again\n");
    }

    int result = Days(&today);                       // calls the function Days

    printf("%d days passed from the date %d/%d/%d", result, today.month, today.day, today.year);

    return 0;
}
/**
 * 
 * int Days(struct Date* new_date)
 * 
 * Summary of the Days function:
 * 
 *      the Days function calculates the number of days from the date 1/1/2000
 * 
 * Parameters : struct : containting integers
 * 
 * Return Value : integer     Note 1) the return value is always natural number.
 *                                 2) Modifies the structure "in place"
 * 
 * Description : 
 *      
 *      This function utilizes calculator (with D-day function) . . .
 * 
*/
int Days(struct Date* new_date){

    int passed_years = new_date->year - 2000; // calculates the number of year from the year of 2000
    int passed_months = new_date->month - 1;  // calculates the number of month from the month of 1 (January)
    int passed_days = new_date->day - 1;      // calculates the number of the day from the day of 1 (1st)

    int how_many_days = 360 * passed_years + 30 * passed_months + passed_days; // calculates the number of days from the date 1/1/2000.
    
    return how_many_days;

}