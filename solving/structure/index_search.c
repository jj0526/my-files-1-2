#include <stdio.h>

struct ppl{
    char name[10];
    int age;
    char hobby[20];
}human[5];

int main(){

    for (int i = 0; i<5; i++){
        printf("person %d\n", i+1);
        printf("name : ");
        gets(human[i].name);
        printf("age : ");
        scanf("%d", &human[i].age);
        printf("hobby : ");
        gets(human[i].hobby);
    }
    int a = find(&human);

    if (a>0){
        printf("%s %d %s\n", human[a].name, human[a].age, human[a].hobby);
    }
    else{
        printf("not found\n");
    }

    return 0;

}

int find(struct ppl* human){
    char find_name[10];
    gets(find_name);
    for (int i = 0; i<5; i++){
        if (human[i].name == find_name){
            return i;
        }
    }
    return 0;
    
}