/**
 * File : lab_g_grouping.c
 *
 * Author : Jeon Sihyeon (wjstlgus13@gachon.ac.kr)
 * Date : 11/02/2021
 * Partner : I worked alone
 * Course : Problem Solving Methods (13967_001)
 *
 * Summary of File :
 *
 *      This file contains code which group data by age and hobby.
 *      with the file personal.txt, the functions group by age on age.txt and by hobby on hobby.txt
 *
 **/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *personal_file, *age_file, *hobby_file;

    char name[100];
    int age[100];
    char hobby[100];

    personal_file = fopen("personal.txt", "r"); // open the file personal_file to read

    if (personal_file == NULL)
    {
        printf("This File Could Not Be Opened.\n"); // if there's no such file
        return 0;
    }
    int i = 0;
    while (fscanf(personal_file, " %c", &name[i]) != EOF)   // if the returned value is EOF(-1), it escapes the while loop
    {
        fscanf(personal_file, "%d %c", &age[i], &hobby[i]); // saves data into the array age and hobby
        i++;
    }

    fclose(personal_file);

    age_file = fopen("age.txt", "w");           // open the file age.txt to write

    int std = 0;
    int *check = (int *)malloc(i * sizeof(int)); // make check array size of i

    for (int m = 0; m < i; m++)
    {
        check[m] = 0;                           // initializes check array into 0
    }

    for (int m = 0; m < i; m++)
    {
        if (check[m] == 0)                      // if check[m] was not used before
        {
            for (int n = m; n < i; n++)         // because there's no same value before
            {
                if (age[m] == age[n])           // if the same age is found
                {
                    fprintf(age_file, "%c %d %c\n", name[n], age[n], hobby[n]); 
                    check[n] = 1;               // check that check[n] was used
                }
            }
        }
    }

    fclose(age_file);                           //close age_file

    hobby_file = fopen("hobby.txt", "w");           // open the file hobby.txt to write

    for (int m = 0; m < i; m++)                     //!NOTE:all the values check array was changed into 1 if they're not used
    {
        if (check[m] == 1)                          // if check[m] was not used before 
        {
            for (int n = m; n < i; n++)             // because there's no same value before
            {
                if (hobby[m] == hobby[n])           // if the same hobby is found
                {
                    fprintf(hobby_file, "%c %d %c\n", name[n], age[n], hobby[n]);
                    check[n] = 0;                   // checks that check[n] was used
                }
            }
        }
    }

    fclose(hobby_file);                             //close hobby_file

    return 0;

}