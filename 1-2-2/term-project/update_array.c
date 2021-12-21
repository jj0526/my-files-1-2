#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MASK 0x40

struct people{
    int tag;
    char date_registered[15];
    char fee_paid[5];
    char name[25];
    int age;
    char organization[35];
    char job[15];
};

struct people registered_people[50];

char last_name[50][25];

int load_data(FILE *original_data, struct people *registered_person);
int delete_array(struct people registered_people[], int size, char deleted_name[]);
int new_registration( struct people registered_people[], int length, struct people new);
void check_sum();
void save_last_name(int size);
  //declaration

int main(){

    //struct people registered_people[50];
    
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

    char deleted_name[25] = "Kim";
    int new_length = delete_array(registered_people, length, deleted_name);    //calls delete_array function. return value is the number of left people

    /*
    printf("length : %d, new length : %d\n", length, new_length);
    for (int i = 0; i<new_length+1; i++){
        printf("%d %s %s %s %d %s %s\n", registered_people[i].tag, registered_people[i].date_registered, registered_people[i].fee_paid, registered_people[i].name, registered_people[i].age, registered_people[i].organization, registered_people[i].job);
    }
    */

    struct people new_registrated_person = {new_length+1, "2021-11-30", "yes", "Gildong Kang", 25, "Gachon University", "Student"};

    int new_regist_rst = new_registration(registered_people, new_length, new_registrated_person);
    
    //printf("new length : %d\n", new_length);
    
    for (int i = 0; i<new_length+1; i++){
        printf("%d %s %s %s %d %s %s\n", registered_people[i].tag, registered_people[i].date_registered, registered_people[i].fee_paid, registered_people[i].name, registered_people[i].age, registered_people[i].organization, registered_people[i].job);
    }

    save_last_name(new_length+1);

    for (int i = 0; i<new_length+1; i++){
        printf("%s ",last_name[i]);
    }
    printf("\n");

    check_sum();
    int res_of_checksum = compare_checksum();
    if (res_of_checksum == 0){
        printf("success\n");
    }
    else
        printf("failed\n");
}


/**
 * 
 * int load_data(FILE *original_data, struct people *registered_person)
 * 
 * Summary of load_data function :
 * 
 *      the load_data function load data from a file and saves on array in structures.
 * 
 * Parameter : file pointer, structer pointer
 * 
 * Return value : integer number
 * 
 * Description :
 * 
 *      This function utilizes saving data with FILE I/O functions...
 *
 */

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
     
        return 1;   //success
    }

    return 0;   //failed (done)
}

/**
 * 
 * int delete_array(struct people registered_people[], int size, char deleted_name[])
 * 
 * Summary of delete_array function :
 * 
 *      The delete_array function delete a strucutre array and shift all affected data.
 * 
 * Parameter : structure array
 *              integer number
 *                  array containing chracter
 * 
 * Return Value : 
 *          integer number      -- Note : Modifies the arrays "in place."
 * 
 * Description :
 * 
 *      This function utilizes deleting array algorithm...
 *      Note, the arrays are modified in place.
 * 
 */
int delete_array(struct people registered_people[], int size, char deleted_name[]){
    
    int count = size; //30
    //printf("count : %d\n", count);

    int size_of_name = 0;
    int size_of_deleted_name = strlen(deleted_name);    //if deleted_name is "kim", the value is 3

    int deleted_tag = 0;

    for (int i = 0; i<size; i++){
        size_of_name = strlen(registered_people[i].name);
        for (int j = 0; j<size_of_name; j++){
            if (registered_people[i].name[j]==deleted_name[0]){ // if "k" is found
                
                int count_of_the_same_letter = 0;
                for (int m = 0; m<size_of_deleted_name; m++){
                    if (registered_people[i].name[m+j]!=deleted_name[m]){   //if they dont include "kim"
                        break;
                    }
                    count_of_the_same_letter++;
                    if(size_of_deleted_name == count_of_the_same_letter){   //if "kim is found"
                        deleted_tag = registered_people[i].tag;
                        int n;
                        for (n = i; n<size-1; n++){
                            registered_people[n].tag = registered_people[n+1].tag;
                            strcpy(registered_people[n].date_registered, registered_people[n+1].date_registered );
                            strcpy(registered_people[n].fee_paid, registered_people[n+1].fee_paid );
                            strcpy(registered_people[n].name, registered_people[n+1].name);
                            registered_people[n].age = registered_people[n+1].age;
                            strcpy(registered_people[n].organization, registered_people[n+1].organization);
                            strcpy(registered_people[n].job, registered_people[n+1].job);   //copy registered_people[n+1] values into registered_people[n]
                        }
                        count--;
                        registered_people[n].tag = 0;
                        registered_people[n].date_registered[0] = 0;
                        registered_people[n].fee_paid[0] = 0;
                        registered_people[n].name[0] = 0;
                        registered_people[n].age = 0;
                        registered_people[n].organization[0] = 0;
                        registered_people[n].job[0] = 0;        //deletes the last structer

                        for (int k = 0; k<count; k++){
                            if (registered_people[k].tag > deleted_tag){
                                registered_people[k].tag = registered_people[k].tag - 1;    //if the tag has bigger value than the deleted person's tag, then it has tag-1 value now
                            }
                        }
                        //printf("deleted\n");
                    }
                }
            }
        }
    }

    return count;   //returns the number of data
}

/**
 * 
 * int new_registration(struct people registered_people[], int length, struct people new)
 * 
 * Summary of new_registration function :
 * 
 *      The new_registration insert an structure between certain data and
 *      shift all affected data
 * 
 * Parameters    : structure array : containing structure pointer, character array and integer numbers
 *                      integer number
 *                          structure : containing structure pointer, character array and integer numbers
 * 
 * Return Value : integer number    -- Note : modifies the structure array "in place"
 * 
 * Description :
 * 
 *      This function utilizes inserting data in array...
 *      Note, the structure arrays are modified in place
 */

int new_registration(struct people registered_people[], int length, struct people new){

    int j = 0; // 27

    for (int i = 0; i<length-1; i++){
        if (registered_people[i].age/10==new.age/10+1){ // 30 years old group
            for (j = length; j>i; j--){
                registered_people[j].tag = registered_people[j-1].tag;
                strcpy(registered_people[j].date_registered, registered_people[j-1].date_registered );
                strcpy(registered_people[j].fee_paid, registered_people[j-1].fee_paid );
                strcpy(registered_people[j].name, registered_people[j-1].name);
                registered_people[j].age = registered_people[j-1].age;
                strcpy(registered_people[j].organization, registered_people[j-1].organization);
                strcpy(registered_people[j].job, registered_people[j-1].job);   //copy registered_people[j-1] data into registered_people[j]
            }
            registered_people[j].tag = new.tag;
            strcpy(registered_people[j].date_registered, new.date_registered);
            strcpy(registered_people[j].fee_paid, new.fee_paid);
            strcpy(registered_people[j].name, new.name);
            registered_people[j].age = new.age;
            strcpy(registered_people[j].organization,  new.organization);
            strcpy(registered_people[j].job, new.job);    //saves new registered person's data
            break;
        }
    }
    return 0;
}

void save_last_name(int size){
    for (int i = 0; i<size; i++){
        int size_of_the_name = strlen(registered_people[i].name);
        int index_of_the_name = 0;
        for (int j = 0; j<size_of_the_name; j++){
            if (registered_people[i].name[j] == ' '){
                for (int m = j+1; m<size_of_the_name+1; m++){
                    last_name[i][index_of_the_name] = registered_people[i].name[m];
                    index_of_the_name++;
                }
                break;
            }
        }
    }
    for (int i = 0; i<size; i++){
        printf("%d %s %s %s %d %s %s\n", registered_people[i].tag, registered_people[i].date_registered, registered_people[i].fee_paid, registered_people[i].name, registered_people[i].age, registered_people[i].organization, registered_people[i].job);
    }
}

void check_sum(){
    int checksum = 0;
    char recent_data[5][25];
    for (int i = 0; i<5; i++){
        strcpy(recent_data[i], last_name[i]);
    }
    for (int i = 0; i<5; i++){
        int count = strlen(recent_data[i]);
        for (int j = 0; j<count; j++){
            checksum += MASK ^ recent_data[i][j];
        }
        //printf("%s\n", recent_data[i]);
    }
    //printf("%d\n", checksum);
   
    FILE *saved_data = fopen("8-1.txt", "w");
    fprintf(saved_data, "%d\n", checksum);
    for (int i = 0; i<5; i++){
        fprintf(saved_data,"%s\n", recent_data[i]);
    }
    fclose(saved_data);
}

int compare_checksum(){
    char read_data[5][25];
    FILE *saved_data = fopen("8-1.txt", "r");

    int first_data_checksum = 0;
    int second_checksum = 0;
    fscanf(saved_data, "%d", &first_data_checksum);
    //printf("first_data_checksum : %d\n", first_data_checksum);

    char temp[5];
    for (int i = 0; i<5; i++){
        //fscanf( saved_data," %s", read_data[i]);
        fscanf(saved_data," %[^\n]", read_data[i]);
        //printf("%s", read_data[i]);
    }
    for (int i = 0; i<5; i++){
        int count = strlen(read_data[i]);
        for (int j = 0; j<count; j++){
            second_checksum += MASK^read_data[i][j];
        }
    }
    //printf("second_checksum : %d\n", second_checksum);
    if (first_data_checksum==0){
        printf("The data isn't sent\n");
        return -1;  //failed
    }
    if((second_checksum ^ first_data_checksum) == 0){ //check if the original data and copied data are same.
        printf("data is sent successfully.\n");
        return 0;
    }
    else
        printf("different data sent!\n"); //if not, print error!
    fclose(saved_data);
    return -1;
}
