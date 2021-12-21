#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void linking(struct people regiesterd_people[], int size);
int load_data(FILE *original_data, struct people *registered_person);
int delete_linked_list(struct people registered_people[], int size, char deleted_name[], struct people *head);
void print_data(struct people data[], struct people head);

int main(){

    struct people registered_people[50];
    
    FILE *original_data;
    original_data = fopen("registraion_data.txt", "r");

    if (original_data == NULL)
    {
        printf("This File Could Not Be Opened.\n"); // if there's no such file
        return 0;
    }

    int length = 0; //30
    for (length = 0; load_data(original_data, &(registered_people[length])); length++); //save data on structers

    fclose(original_data);
    //printf("length : %d\n", length);

    linking(registered_people, length);
    
    char deleted_name[25] = "Kim";
    
    struct people head;
    head.next = &registered_people[0];

    int new_length = delete_linked_list(registered_people, length, deleted_name, &head);    //calls delete_array function. return value is the number of left people
    

    print_data(registered_people, head);
    /*
    printf("length : %d, new length : %d\n", length, new_length);
    for (int i = 0; i<new_length+1; i++){
        printf("%d %s %s %s %d %s %s\n", registered_people[i].tag, registered_people[i].date_registered, registered_people[i].fee_paid, registered_people[i].name, registered_people[i].age, registered_people[i].organization, registered_people[i].job);
    }
    */

    /*
    struct people new_registrated_person = {new_length+1, "2021-11-30", "yes", "Gildong Kang", 25, "Gachon University", "Student"};

    int new_regist_rst = new_registration(registered_people, new_length, new_registrated_person);
    */
    //printf("new length : %d\n", new_length);
    
    /*for (int i = 0; i<new_length+1; i++){
        printf("%d %s %s %s %d %s %s\n", registered_people[i].tag, registered_people[i].date_registered, registered_people[i].fee_paid, registered_people[i].name, registered_people[i].age, registered_people[i].organization, registered_people[i].job);
    }*/

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
        fscanf(original_data, " %[^\n]", registered_person->job);
        registered_person->tag = atoi(ctag);    //saves integer value in tag
        registered_person->age = atoi(cage);    //saves integer value in age
     
        return 1;
    }

    return 0;
}

void linking(struct people regiesterd_people[], int size){
    for (int i = 0; i<size-1; i++){
        regiesterd_people[i].next = &regiesterd_people[i+1];
    }
    regiesterd_people[size-1].next = NULL;
}

int delete_linked_list(struct people registered_people[], int size, char deleted_name[], struct people *head){
    struct people *ptr = (struct people*)malloc(sizeof(struct people));
    struct people *prv_ptr = (struct people*)malloc(sizeof(struct people));

    int new_len = size;

    prv_ptr = head;
    ptr = head->next;
    
    while(ptr){
        int index = 0;
        int len_of_name = strlen(ptr->name);
        while(1){
            if (index>len_of_name-2)
                break;
            if (ptr->name[index] == deleted_name[0]){
                if (ptr->name[index+1] == deleted_name[1] && ptr->name[index+2]==deleted_name[2]){
                    ptr->next = NULL;
                    prv_ptr->next = ptr->next;
                    ptr = ptr->next;
                    new_len--;
                }
            }
            index++;
            
        }
        prv_ptr = ptr;
        ptr = ptr->next;
        
    }
    return new_len;
}

void print_data(struct people data[], struct people head){
    struct people *ptr = (struct people*)malloc(sizeof(struct people));
    ptr = head.next;
    while(ptr){
        printf("%d %s %s %s %d %s %s\n", ptr->tag, ptr->date_registered, ptr->fee_paid, ptr->name, ptr->age, ptr->organization, ptr->job);
    }
}