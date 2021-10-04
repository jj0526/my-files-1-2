#include <stdio.h>
#include <string.h>

struct ppl{
    char name[10];
    int age;
    char hobby[20];
};

struct index{
    char name[10];
    int array_index;
};

int find(struct index* arrays);

/**
 * File : index_search.c
 * 
 * Author : Jeon Sihyeon (wjstlgus13@gachon.ac.kr)
 * Date : 9/30/2021
 * Partner : I worked alone
 * Course : Problem Solving Methods (13967_001)
 * 
 * Summary of Fie : 
 * 
 *      This file contains code which shows 5 people's names, ages and hobbies
 *      Functions allow the user of the software to search the index for a name, and find their dataset.
 * 
*/

int main(){

    struct ppl dataset[5] = {{"Kim", 39, "Tennis"},{"Ko",15,"Soccer"}, {"Lee",17, "Soccer"}, {"Choi",21,"Tennis"},{"Park",10,"Tennis"}};
    //initializes dataset
    struct index array_index[5];  // declared 2 struct arrays (5*2)

    for (int i = 0; i<5; i++){
        array_index[i].array_index = i;                //save index number into array_index[i].array_index
        strcpy(array_index[i].name, dataset[i].name); // copy the array into array_index[i].name
    }

    int a = find(array_index);  //calls function find 

    if (a>0){                 // if it's found with strcmp
        printf("name : %s      age : %d       hobby : %s\n", dataset[a].name, dataset[a].age, dataset[a].hobby);
    }
    else{
        printf("not found\n");// if a<=0, not found.
    }

    a = find(array_index);      //calls function find

    if (a>0){
        printf("name : %s      age : %d       hobby : %s\n", dataset[a].name, dataset[a].age, dataset[a].hobby);
    }                           // print the result
    else{
        printf("not found\n");
    }

    return 0;

}

/**
 * 
 * int find(struct index* arrays)
 * 
 * Summary of the find function :
 * 
 *      The find function, search the index of the struct
 * 
 * Parameters : struct array : containing strings (10 characters)*5 and integers
 * 
 * Return Value : integer -- Note : Modifies the array "in place".
 * 
 * Description :
 * 
 *      This function utilizes index Search . . .
 *      Note, the array is modifies in place.
*/
int find(struct index* arrays){

    char find_name[10];

    printf("input the name you want to find\n");
    scanf(" %[^\n]", find_name);                    // input the name the user want to find
    for (int i = 0; i<5; i++){
        if (strcmp(arrays[i].name,find_name)==0){   // find the same name
            return i;                               // returns the index
        }
    }
    return 0;
}