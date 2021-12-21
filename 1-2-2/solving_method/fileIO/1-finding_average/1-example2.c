/**
 * File : 1-example2.c
 *
 * Author : Jeon Sihyeon (wjstlgus13@gachon.ac.kr)
 * Date : 11/01/2021
 * Partner : I worked alone
 * Course : Problem Solving Methods (13967_001)
 *
 * Summary of File :
 *      
 *
 *
 *
 *
 *
 *
 */

#include <stdio.h>

int main()
{
    FILE *infile, *outfile;

    infile = fopen("prob_10_num.txt", "r");

    int n;

    int scanfed = 0;
    double num[5] = {0};

    if (infile == NULL)
    {
        printf("Input File Could Not Be Opened.\n");
        return 0;
    }
    int j = 0;
    while (fscanf(infile, "%d", &n) != EOF)
    {
        for (int i = 0; i<n; i++)
        {
            fscanf(infile, "%d", &scanfed);
            num[j]+=scanfed;
        }
        num[j]/=n;

        j++;
    }

    fclose(infile);
    
    outfile = fopen("prob_10_num.txt", "a");

    fprintf(outfile, "\n");

    for (int m = 0; m < 3; m++)
    {
        fprintf(outfile, "average : %lf\n", num[m]);
    }

    fclose(outfile);

    return 0;

}