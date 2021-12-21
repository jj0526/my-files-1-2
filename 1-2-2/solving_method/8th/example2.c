#include <stdio.h>
#include <stdlib.h>

int main(){
    int a, sum = 0;
    FILE *inFile, *outFile;

    inFile = fopen("myinFile.txt", "r");
    if (inFile == NULL){
        printf("Input file could not be opened");
        return 0;
    }
    outFile = fopen("myoutFile.txt", "w");
    if (outFile == NULL){
        printf("Output file could not be opened");
        return 0;
    }
    while (fscanf(inFile, "%d", &a)==1){
        printf(stdout, "%d", sum);
        sum = sum + a;
    }
    fprintf(outFile, "The sum is %d\n", sum);
    fclose(inFile);
    fclose(outFile);
    return 0;
}