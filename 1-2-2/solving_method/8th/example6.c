#include <stdio.h>

int main(){
    FILE *myInFile, *myOutFile;
    char ch;

    myInFile = fopen("data.txt", "r");
    if (myInFile == NULL){
        printf("Could not open data.txt!\n");
        return 0;
    }
    myOutFile = fopen("samedata.txt", "w");
    if (myOutFile==NULL){
        printf("Could not open samedata.txt!\n");
        return 0;
    }

    while ((ch=fgetc(myInFile))!=EOF)
        fputc(ch, myOutFile);
    fclose(myInFile);
    fclose(myOutFile);
}