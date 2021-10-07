#include <stdio.h>

int main(){
    char str[100];
    gets(str);

    int size = strlen(str);

    if (find(str, size)>=1){
        printf("%dth index\n",find(str, size));
    }
    else{
        printf("There's no name\n");
    }
}

int find(char str[], int size){
    char name[5] = "name";
    int count = 0;
    for (int i = 0; i<size; i++){
        count = 0;
        if (str[i]==name[0]){
            count++;
            for (int j = 0; j<size-i; j++){
                if (str[j]==name[count]){
                    if (count==4){
                        return j-3;
                    }
                }
                else{
                    continue;
                }
            }
        }
    }
    return 0;
}