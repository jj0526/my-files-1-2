#include <stdio.h>
#include <string.h>

struct human{
    char name[30];
    int age;
    char hobby[30];
};

struct id{
    char name[30];
    int array_index;
};

int main(){
    struct human dataset[5] = {{"Kim", 39, "Tennis"},{"Ko", 15, "Soccer"}, {"Lee", 17, "Soccer"}, 
    {"Choi", 21, "Tennis"}, {"Park", 10, "Tennis"}};

    struct id index[5];

    for (int i = 0; i<5; i++){
        index[i].array_index = i;
        strcpy(index[i].name, dataset[i].name);
    }

    char finding_name[30];
    scanf(" %s", finding_name);

    int res = find_name(index, 5, finding_name);

    if (res == -1){
        printf("no result found\n");
        return 0;
    }
    
    printf("name : %s age : %d hobby : %s\n", dataset[res].name, dataset[res].age, dataset[res].hobby);

    return 0;
}

int find_name(struct id index[], int Size, char finding_name[]){
    int len_of_finding_name = strlen(finding_name);
    int count = 0;
    for (int i = 0; i < Size; i++){
        count = 0;
        if(strcmp(index[i].name, finding_name)==0){
            return i;
        }
    }
    return -1;
}