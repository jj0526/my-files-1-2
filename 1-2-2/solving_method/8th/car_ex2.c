#include <stdio.h>

struct CAR{
    char name[20];
    int year;
    double price;
}car[4] = {{"Avente",2007,13000.00}, {"Sonata", 2008, 18000.00}, {"SM7", 2009, 22000.00}, {"Equus", 2010, 35000.00}};

int main(){
    FILE *infile, *outfile;

    infile = fopen("cars.txt", "w");

    if (infile == NULL){
        printf("Could not open cars.txt!\n");
        return 0;
    }

    fprintf(infile, "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");

    for (int i = 0; i<4; i++){
        fprintf(infile, "|%-10s |%d |%.2lf|\n", car[i].name, car[i].year, car[i].price);
    }
    fprintf(infile, "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");

    fclose(infile);

    outfile = fopen("cars.txt", "r");

    if (outfile==NULL){
        printf("Could not open cars.txt!\n");
        return 0;
    }

    int ch = fgetc(outfile);

    

    while (ch!=EOF){
        putchar(ch);
        ch = fgetc(outfile);
    }

    fclose(outfile);

    return 0;

}