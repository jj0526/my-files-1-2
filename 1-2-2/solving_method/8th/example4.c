#include <stdio.h>

int main(){
    int i;
    FILE *myFile;
    myFile = fopen("myinFile.txt", "r");

    if (myFile == NULL)
        printf("File could not be opened");
    else{
        char ch = fgetc(myFile);
        while (ch!=EOF){
            putchar(ch);
            ch = fgetc(myFile);
        }
        printf("Finished printing the file\n");
        fclose(myFile);
    }
}