#include <stdio.h>
#include <string.h>
int group_in_age_order(char name[][10], int age[], char hobby[][10], int size);
int group_in_hobby_order(char name[][10], int age[], char hobby[][10], int size);
int grouping_with_bubblesort(char name[][10], int age[], char hobby[][10], int size);
int selection_sort(char name[][10], int age[], char hobby[][10], int size);

int main(){

    char name[30][10];
    int age[30];
    char hobby[30][10];
    FILE *origin_file;

    origin_file = fopen("person.txt", "r");
    int i = 0;
    
    int size = 0;
    if (origin_file==NULL){
        printf("failed to load\n");
    }
    while(fscanf(origin_file, " %s", &name[i])!=EOF){
        fscanf(origin_file, "%d", &age[i]);
        fscanf(origin_file, " %s", &hobby[i]);
        i++;
        size = i;
    }
    fclose(origin_file);

    int a = group_in_age_order(name, age, hobby, size);
    int b = group_in_hobby_order(name, age, hobby, size);
    int c = grouping_with_bubblesort(name, age, hobby, size);
    int d = selection_sort(name, age, hobby, size);

    return 0;
}

int group_in_age_order(char name[][10], int age[], char hobby[][10], int size){
    FILE *age_file;
    age_file = fopen("age.txt", "w");

    if (age_file==NULL){
        printf("failed to load\n");
        return -1;
    }

    int check[30];
    for (int i = 0; i<30; i++)
        check[i] = 0;

    for (int i = 0; i<size; i++){
        for (int j = i; j<size; j++){
            if ((check[j]!=1)&&(age[i]/10==age[j]/10)){
                fprintf(age_file, "%s %d %s\n", name[j], age[j], hobby[j]);
                check[j] = 1;
            }
        }
    }
    fclose(age_file);
    return 0;
}

int group_in_hobby_order(char name[][10], int age[], char hobby[][10], int size){
    FILE *hobby_file;
    hobby_file = fopen("hobby.txt", "w");

    if(hobby_file==NULL){
        printf("failed to load\n");
        return -1;
    }

    int check[30];
    for (int i = 0; i<30; i++)
        check[i] = 0;
    
    for (int i = 0; i<size; i++){
        for (int j = i; j<size; j++){
            if (check[j]!=1 && strcmp(hobby[i], hobby[j])==0){
                fprintf(hobby_file, "%s %d %s\n", name[j], age[j], hobby[j]);
                check[j] = 1;
            }
        }
    }
    fclose(hobby_file);
    return 0;
}

int grouping_with_bubblesort(char name[][10], int age[], char hobby[][10], int size){
    FILE *age_bs = fopen("age_sort.txt", "w");

    for (int i = 0; i<size; i++){
        for (int j = i; j<size; j++){
            if (age[i]>age[j]){
                char temp_name[10];
                strcpy(temp_name, name[i]);
                char temp_hobby[10];
                strcpy(temp_hobby, hobby[i]);
                int temp_age = age[i];
                strcpy(name[i], name[j]);
                strcpy(hobby[i], hobby[j]);
                age[i] = age[j];

                strcpy(name[j], temp_name);
                strcpy(hobby[j], temp_hobby);
                age[j] = temp_age;
            }
        }
    }
    for (int i = 0; i<size; i++){
        fprintf(age_bs, "%s %d %s\n", name[i], age[i], hobby[i]);
    }
    fclose(age_bs);
}

int selection_sort(char name[][10], int age[], char hobby[][10], int size){
    FILE *age_ss = fopen("age_sort.txt", "w");

    for (int i = 0; i<size; i++){
        int min = age[i];
        int index = i;
        for (int j = i; j<size; j++){
            if (min>age[j]){
                min = age[j];
                index = j;
            }
        }
        char temp_name[10];
        strcpy(temp_name, name[i]);
        char temp_hobby[10];
        strcpy(temp_hobby, hobby[i]);
        int temp_age = age[i];

        strcpy(name[i], name[index]);
        strcpy(hobby[i], hobby[index]);
        age[i] = age[index];

        strcpy(name[index], temp_name);
        strcpy(hobby[index], temp_hobby);
        age[index] = temp_age;
        printf("%d ",min);

    }
    for (int i = 0; i<size; i++){
        fprintf(age_ss, "%s %d %s\n", name[i], age[i], hobby[i]);
    }
    return 0;
}