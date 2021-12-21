#include <stdio.h>

struct CAR{
    char name[20];
    int year;
}car[2] = {{"Avante", 2007}, {"Sonata", 2008}};

int main(){

    FILE *infile, *outfile;

    infile = fopen("cars.txt", "w");

    if (infile == NULL){
        printf("Could not open cars.txt!\n");
        return 0;
    }

    for (int i = 0; i<2; i++){
        fprintf(infile, "%s %d\n", car[i].name, car[i].year);
    }

    fclose(infile);

    outfile = fopen("cars.txt", "r");

    if (outfile==NULL){
        printf("Could not open cars.txt!\n");
        return 0;
    }

    char names[20];
    int years;

    while (fscanf(outfile, "%s %d", names, &years)==2){
        printf("%s %d\n", names, years);
    }

    fclose(outfile);

    return 0;

}