#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *infile;
    char line[100];
    int lcount = 0;

    if ((infile = fopen("charstream.txt", "r"))==NULL){
        printf("File could not be opened\n");
        return 0;
    }
    while (fgets(line, sizeof(line), infile)!=EOF){
        lcount++;
        printf("Line %d : %s", lcount, line);
    }
    fclose(infile);
}