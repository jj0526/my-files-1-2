#include <stdio.h>

int main(){
    int i;
    FILE *myFile;
    double price[2] = {139.55, 19.03};
    char description[][20] = {"glove", "CD"};

    myFile = fopen("price.dat", "w");
    if (myFile == NULL)
        printf("\nFile could not be opened");
    else{
        for (i = 0; i<2; i++){
            fprintf(myFile, "%-9s %6.2f\n", description[i], price[i]);
        }
        fclose(myFile);
    }

}