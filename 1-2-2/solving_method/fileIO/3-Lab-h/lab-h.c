#include <stdio.h>

int main(){
    FILE *info;

    info = fopen("personal.txt", "r");

    char name[10][10], hobby[10][10];
    int age[10];

    int n = 0;
    while (fscanf(info, " %s", name[n])!=EOF){
        fscanf(info, "%d", &age[n]);
        fscanf(info, " %s", hobby[n]);
        n++;
    }

    for (int i = 0; i<6; i++){
        printf("%s %d %s\n", name[i], age[i], hobby[i]);
    }

    fclose(info);

    FILE *write_info;

    write_info = fopen("write.txt", "w");

    fprintf(write_info, "Age from 20 to 29\n-------------------\n");

    for (int i = 0; i<n; i++){
        if (age[i]/10 == 2){
            fprintf(write_info, "%s %d %s\n", name[i], age[i], hobby[i]);
        }
    }

    fprintf(write_info, "\nAge from 30 to 39\n-------------------\n");

    for (int i = 0; i<n; i++){
        if (age[i]/10 == 3){
            fprintf(write_info, "%s %d %s\n", name[i], age[i], hobby[i]);
        }
    }

    fprintf(write_info, "\nAge from 40 to 49\n-------------------\n");

    for (int i = 0; i<n; i++){
        if (age[i]/10 == 4){
            fprintf(write_info, "%s %d %s\n", name[i], age[i], hobby[i]);
        }
    }

    fclose(write_info);

    return 0;
}