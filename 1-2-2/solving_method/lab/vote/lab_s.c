#include <stdio.h>
#include <string.h>

int counting_vote(char voted[][20], int size, int every, int *washington, int *lincoln, int *clinton);

int main()
{
    FILE *myfile;

    myfile = fopen("vote.txt", "r");

    char name[10000][20];
    int age[10000];
    char voted[10000][20];

    if (myfile == NULL)
    {
        printf("This file could not be opened\n");
        return 0;
    }
    int i = 0;
    while (fscanf(myfile, " %s", name[i]) != EOF)
    {
        fscanf(myfile, "%d", &age[i]);
        fscanf(myfile, " %s", voted[i]);
        i++;
    }
    fclose(myfile);

    int every = 0;

    int num_of_washing = 0;
    int num_of_lincoln = 0;
    int num_of_Roosevelt = 0;

    int num_of_votes;

    num_of_votes = counting_vote(voted, i, every, &num_of_washing, &num_of_lincoln, &num_of_Roosevelt);

    fprintf(stdout, "Washington %.1f, Lincoln %.1f, Roosevelt %.1f\n", ((float)100*num_of_washing / num_of_votes),( (float)100*num_of_lincoln / num_of_votes), ((float)100*num_of_Roosevelt / num_of_votes));

    every = 2;
    num_of_votes = counting_vote(voted, i, every, &num_of_washing, &num_of_lincoln, &num_of_Roosevelt);
    fprintf(stdout, "Washington %.1f, Lincoln %.1f, Roosevelt %.1f\n", ((float)100*num_of_washing / num_of_votes), ((float)100*num_of_lincoln / num_of_votes), ((float)100*num_of_Roosevelt / num_of_votes));

    every = 9;
    num_of_votes = counting_vote(voted, i, every, &num_of_washing, &num_of_lincoln, &num_of_Roosevelt);
    fprintf(stdout, "Washington %.1f, Lincoln %.1f, Roosevelt %.1f\n", ((float)100*num_of_washing / num_of_votes), ((float)100*num_of_lincoln / num_of_votes), ((float)100*num_of_Roosevelt / num_of_votes));

    return 0;
}

int counting_vote(char voted[][20], int size, int every, int *washington, int *lincoln, int *Roosevelt)
{
    *washington = 0;
    *lincoln = 0;
    *Roosevelt = 0;
    int num_of_votes = 0;

    for (int m = 0; m < size+1; m += every + 1){
        if (strcmp(voted[m], "Washington") == 0)
            *washington = *washington + 1;
        else if (strcmp(voted[m], "Lincoln") == 0)
            *lincoln = *lincoln + 1;
        else if (strcmp(voted[m], "Roosevelt") == 0)
            *Roosevelt = *Roosevelt + 1;
        num_of_votes++;
        
    }
    
    return num_of_votes;
}