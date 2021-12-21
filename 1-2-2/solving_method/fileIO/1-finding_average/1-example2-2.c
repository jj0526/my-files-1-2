/**
 * File : 1-example2.c
 *
 * Author : Jeon Sihyeon (wjstlgus13@gachon.ac.kr)
 * Date : 11/03/2021
 * Partner : I worked alone
 * Course : Problem Solving Methods (13967_001)
 *
 * Summary of File :
 *      This file contains code which shows the average of n numbers.
 *      Functions shows the average of the first number numbers in the file that 
 *      the first number indicates that the next first number numbers are grouped together
 *
**/

#include <stdio.h>

int grouped_avg(FILE *infile, FILE *outfile);   //declaration

int main()
{
    FILE *infile, *outfile;

    int res = grouped_avg(infile, outfile);     //calls grouped_avg function

    if (res==0){        // if there's no such file
        printf("Input File Could Not Be Opened.\n");
        return 0;
    }

    return 0;

}
/**
 * 
 * int grouped_avg(FILE *infile, FILE *outfile)
 * 
 * Summary of the grouped_avg function:
 *      The grouped_avg function shows the result of 
 *      adding the first number numbers
 * 
 * Parameters   :   File pointers
 * 
 * Return value : integer number
 * 
 * Description :
 * 
 *      This function utilizes the summation algorithm . . .
 * 
 * 
**/

int grouped_avg(FILE *infile, FILE *outfile){

    infile = fopen("prob_10_num.txt", "r");     //open the file to read

    int n;

    int scanfed = 0;
    double num[100] = {0};

    if (infile == NULL) //if there's no such file
    {
        return 0;
    }
    int j = 0;                                  //the number of the groups
    while (fscanf(infile, "%d", &n) != EOF)     //before the end of the file
    {
        for (int i = 0; i<n; i++)               //for n(the first number) times
        {
            fscanf(infile, "%d", &scanfed);     //add n numbers
            num[j]+=scanfed;
        }
        num[j]/=n;                              //saves average

        j++;
    }

    fclose(infile);                             //close the file
    
    outfile = fopen("prob_10_num.txt", "a");    //open the file to append

    fprintf(outfile, "\n");

    for (int m = 0; m < j; m++)
    {
        fprintf(outfile, "average : %lf\n", num[m]);    //print the averages of n numbers
    }

    fclose(outfile);                                //close the file

    return 1;

}