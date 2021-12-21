#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct people{
    int tag;
    char date_registered[15];
    char fee_paid[5];
    char name[25];
    int age;
    char organization[35];
    char job[15];
    struct people *next;
};


int load_data(FILE *original_data, struct people *registered_person);
int search_name(char name[25], struct people registered_people[], int size, struct people head);
void search_for_org_and_job(struct people registered_people[], int size, char searching_org[], char searching_job[], struct people head);
void linking(struct people regiesterd_people[], int size, struct people head);  //function declaration 

struct people registered_people[50];

int main(){

    
    
    FILE *original_data;
    original_data = fopen("registraion_data.txt", "r");

    if (original_data == NULL)
    {
        printf("This File Could Not Be Opened.\n"); // if there's no such file
        return 0;
    }

    int length;

    for (length = 0; load_data(original_data, &(registered_people[length])); length++); //save data on structers

    fclose(original_data);

    struct people head;
    head.next = &registered_people[0];              //head's next has registered_people[0]'s address now
    linking(registered_people, length, head);       //calls function

    char searching_name[25] = "Kim";
    int res_search1 = search_name(searching_name, registered_people, length, head); //calls search_name function

    char searching_organization[35] = "Gachon University";
    char searching_job[15] = "engineer";

    search_for_org_and_job(registered_people, length, searching_organization, searching_job, head); //calls search_for_org_and_job function

    return 0;
}



int load_data(FILE *original_data, struct people *registered_person){
    char temp[10];
    char ctag[5];
    char cage[5];
    if (fscanf(original_data, " %[^/]", ctag)!=EOF){
        fscanf(original_data, " %[/]", temp);
        fscanf(original_data, " %[^/]", registered_person->date_registered);
        fscanf(original_data, " %[/]", temp);
        fscanf(original_data, " %[^/]", registered_person->fee_paid);
        fscanf(original_data, " %[/]", temp);
        fscanf(original_data, " %[^/]", registered_person->name);
        fscanf(original_data, " %[/]", temp);
        fscanf(original_data, " %[^/]", cage);
        fscanf(original_data, " %[/]", temp);
        fscanf(original_data, " %[^/]", registered_person->organization);
        fscanf(original_data, " %[/]", temp);
        fscanf(original_data, " %s", registered_person->job);
        registered_person->tag = atoi(ctag);    //saves integer value in tag
        registered_person->age = atoi(cage);    //saves integer value in age
        return 1;
    }

    return 0;
}

/**
 *  void linking(struct people regiesterd_people[], int size, struct people head)
 * 
 *  Summary of linking function :
 *      The linking function links given structures of data ascending order of the index
 * 
 *  Parameters  : structure array : containing structure pointer, character array and integer numbers
 *                  integer number
 *                      structure : containing structure pointer, character array and integer numbers
 * 
 * Return value : nothing   -- NOTE : modifies the arrays "in place"
 * 
 * Description :
 * 
 *      This function utilizes linked list.
 *          Note, the arrays are modified in place
 * 
 * 
 */

void linking(struct people regiesterd_people[], int size, struct people head){
    for (int i = 0; i<size-1; i++){
        regiesterd_people[i].next = &regiesterd_people[i+1];    //regiesterd_people[i].next has regiesterd_people[i+1]'s address
    }
    regiesterd_people[size-1].next = NULL;      //the last structure's next has NULL

    struct people *ptr = (struct people*)malloc(sizeof(struct people));
    ptr = head.next;
    /*while(ptr){
        printf("%d %s %s %s %d %s %s\n", ptr->tag, ptr->date_registered, ptr->fee_paid, ptr->name, ptr->age, ptr->organization, ptr->job);
        ptr = ptr->next;
    }*/
}
/**
 * int search_name(char name[25], struct people registered_people[], int size, struct people head)
 * 
 * Summary of search_name function : 
 * 
 *      The search_name function searches the given array of character using structure pointer.
 *      It displays all information about the people if it's found.
 *
 * Parameters : 
 *              array : containing character
 *                  structer array : containing structure pointer, character array and integer numbers
 *                      integer number
 *                          structure : containing structure pointer, character array and integer numbers
 * 
 * Return value : integer number    -- Note : modifies the arrays "in place"
 * 
 * Description :
 * 
 *      This function utilizes the strcmp function ...
 *      Note, the arrays are modified in place. 
 * 
 */

int search_name(char name[25], struct people registered_people[], int size, struct people head){
    struct people *ptr = (struct people*)malloc(sizeof(struct people));
    ptr = head.next;
    int size_of_searching_name = strlen(name);
    printf("The result of searching for \"Kim\"\n");
    while(ptr){
        int len_name = strlen(ptr->name);
        for (int i = 0; i<len_name; i++){
            if (ptr->name[i]==name[0]){
                int count_same_letter = 0;
                for (int j = 0; j<size_of_searching_name; j++){
                    if (ptr->name[j+i]!=name[j]){   //if they dont include "kim"
                        break;
                    }
                    count_same_letter++;
                    if(count_same_letter == size_of_searching_name){
                        printf("%d %s %s %s %d %s %s\n", ptr->tag, ptr->date_registered, ptr->fee_paid, ptr->name, ptr->age, ptr->organization, ptr->job);
                        break;
                    }
                    
                }
            }
        }
        ptr = ptr->next;
    }
    
    return 0;
}

/**
 *  void search_for_org_and_job(struct people registered_people[], int size, char searching_org[], char searching_job[], struct people head)
 * 
 *  Summary of the search_for_org_and_job function :
 * 
 *      The search_for_org_and_job function searches the given arrays of character using structure pointer. 
 *      if the data is found, it displays all information about the people.
 * 
 * Parameters : array : containing character
 *                  structer array : containing structure pointer, character array and integer numbers
 *                      integer number
 *                          structure : containing structure pointer, character array and integer numbers
 *  
 * Return value : nothing -- Note : modifies the structure array "in place."
 * 
 * Description :
 *      
 *      This function utilizes linked list search algorithm...
 *      Note, the array is modified in place.
 * 
*/

void search_for_org_and_job(struct people registered_people[], int size, char searching_org[], char searching_job[], struct people head){
    struct people *ptr = (struct people*)malloc(sizeof(struct people));
    ptr = head.next;

    printf("\nThe result of searching for %s from %s\n", searching_job, searching_org);

    while(ptr){
        if((strcmp(ptr->organization, searching_org)==0)&&(strcmp(ptr->job, searching_job)==0)){
            printf("%d %s %s %s %d %s %s\n", ptr->tag, ptr->date_registered, ptr->fee_paid, ptr->name, ptr->age, ptr->organization, ptr->job);
        }
        ptr = ptr->next;
    }
}

