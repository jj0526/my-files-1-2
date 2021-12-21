/**
* File: termproject_group_c.c
*
* Author:	MinA Lee (lma0424@gachon.ac.kr)
*			Lee YouJin (kynhun20@gachon.ac.kr)
*			Park, sung woo (park0714a@naver.com)
*			Jo Jun Hyeong (jjh970323@gachon.ac.kr)
*			Jeon si hyeon (wjstlgus13@gachon.ac.kr)
*			Jang dong jun (tiranojang@naver.com)
* Date: 12/03, 2021
* Course: Problem Solving Methods
*
* Summary of File:
*
*	This file contains code which search, reorganize and update data by using array and linked list.
*
*/
#define _CRT_SECURE_NO_WARNINGS
#define MAXNUM 30
#define DEBUG
#define Swap(type, x, y) {type t = x; x = y; y = t;}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MASK 0x40

struct NODE {
	int tag;
	char date[15];
	char fee[5];
	char name[25];
	int age;
	char organization[35];
	char job[15];
	struct NODE* next;
};

typedef struct Data {
	int tag;
	char date[15];
	char fee[5];
	char name[25];
	int age;
	char organization[35];
	char job[15];
}person;

person people[MAXNUM];		// array for save data
int number = 0;		// number of data in file
char last_name[50][25];		// array to save last name

/**
*
* ReadData(char filename[])
*
* Summary of the Days function:
*
*	The ReadData function read input file & save as array
*
* Parameters:	none
* Return Value: result: none
*
*/
void ReadData(char filename[]) {
	int n = 0;
	number = 0;
	FILE* inFile = NULL;
	inFile = fopen(filename, "r");
	if (inFile == NULL) {
		printf("\nInput File Could Not Be Opened.\n");
		return;
	}
	while (fscanf(inFile, "%d/%[^/]/%[^/]/%[^/]/%d/%[^/]/%s", &people[n].tag, people[n].date,
		people[n].fee, people[n].name, &people[n].age, people[n].organization, people[n].job) != EOF) {
		n++;
		number++;
	}

	if (inFile != NULL) {
		fclose(inFile);
		inFile = NULL;
	}
}

/**
*
* linked_list(struct NODE* head)
*
* Summary of the Days function:
*
*	The linked_list function read input file & save as array
*
* Parameters:	head: containing struct NODE*
* Return Value: result: none
*
*/
void linked_list(struct NODE* head)
{
	struct NODE* ptr, * pre;
	struct NODE* newnode;

	int i = 0;
	while (people[i].tag != '\0') {
		if (i == number) break;
		pre = head;
		ptr = head->next;
		newnode = (struct NODE*)malloc(sizeof(struct NODE));
		if (newnode == (struct NODE*)NULL) exit(1);
		while (ptr != NULL) {
			pre = ptr;
			ptr = ptr->next;
		}
		newnode->tag = people[i].tag;
		strcpy(newnode->date, people[i].date);
		strcpy(newnode->fee, people[i].fee);
		strcpy(newnode->name, people[i].name);
		newnode->age = people[i].age;
		strcpy(newnode->organization, people[i].organization);
		strcpy(newnode->job, people[i].job);
		newnode->next = ptr;
		pre->next = newnode;
		i++;
	}
}

//P1-1
/**
*
* search_name(char what[])
*
* Summary of the search_name function:
*
*	The search_name function search & print the data containing certain name in array
*
* Parameters:	what[]: containing characters
* Return Value: result: none
*
*/
void search_name(char what[]) {
	for (int i = 0;i < number; i++) {
		if (strcmp(strstr(people[i].name, " ") + 1, what) == 0) {
			printf("%d/%s/%s/%s/%d/%s/%s\n", people[i].tag, people[i].date,
				people[i].fee, people[i].name, people[i].age, people[i].organization, people[i].job);
		}
	}
}

//P1-2
/**
*
* search_name_linked(struct NODE* head)
*
* Summary of the search_name_linked function:
*
*	The search_name_linked function search & print the data containing certain name in linked list
*
* Parameters:	head: containing struct NODE*
* Return Value: result: none
*
*/
void search_name_linked(struct NODE* head) {
	struct NODE* p;

	p = head->next;
	while (p != NULL) {
		char* temp;
		temp = strstr(p->name, "Kim");
		if (temp != NULL) {
			printf("%d/%s/%s/%s/%d/%s/%s\n", p->tag, p->date, p->fee, p->name, p->age, p->organization, p->job);
		}
		p = p->next;
	}
}

//P2-1
/**
*
* search_univ(char Un[], char Job[])
*
* Summary of the search_univ function:
*
*	The search_univ function search & print the data containing certain organization & job in array
*
* Parameters:	Un[]: containing characters
*				Job[]: containing characters
* Return Value: result: none
*
*/
void search_univ(char Un[], char Job[]) {
	for (int i = 0;i < number;i++) {
		if (strcmp(people[i].organization, Un) == 0 && strcmp(people[i].job, Job) == 0) {
			printf("%d/%s/%s/%s/%d/%s/%s\n", people[i].tag, people[i].date,
				people[i].fee, people[i].name, people[i].age, people[i].organization, people[i].job);
		}
	}
}

//P2-2
/**
*
* search_linked(struct NODE* head)
*
* Summary of the search_linked function:
*
*	The search_linked function search & print the data containing certain organization & job in linked list
*
* Parameters:	head: containing struct NODE*
* Return Value: result: none
*
*/
void search_linked(struct NODE* head) {
	struct NODE* p;

	p = head->next;

	while (p != NULL) {
		if (strstr(p->organization, "Gachon University") != NULL && strstr(p->job, "engineer") != NULL) {
			printf("%d/%s/%s/%s/%d/%s/%s  \n", p->tag, p->date, p->fee, p->name, p->age, p->organization, p->job);
		}
		p = p->next;
	}
}

//P3-1
/**
*
* SortTag()
*
* Summary of the SortTag function:
*
*	The SortTag function sort array in tag order
*
* Parameters:	none
* Return Value: result: none
*
*/
void SortTag() {
	for (int i = 0;i < 30;i++) {
		for (int j = 0;j < 29;j++) {
			if (people[j].tag > people[j + 1].tag) {
				Swap(person, people[j], people[j + 1]);
			}
		}
	}
	for (int i = 0; i < 30; i++) {
		printf("%d/%s/%s/%s/%d/%s/%s\n", people[i].tag, people[i].date, people[i].fee, people[i].name, people[i].age, people[i].organization, people[i].job);
	}
}

//P4-1
/**
*
* AgeSelectionSort
*
* Summary of the AgeSelectionSort function:
*
*	The AgeSelectionSort function sort array in age group order
*
* Parameters:	Filename[]: containing characters
* Return Value: result: none
*
*/
void AgeSelectionSort(char Filename[]) {
	FILE* AgeDataFile = fopen(Filename, "w");
	if (AgeDataFile == NULL) {
		printf("\nAgeDataFile could not be opened.\n");
		return;
	}
	for (int i = 0;i < 29;i++) {
		int min = i;
		for (int j = (i + 1);j < 30;j++) {
			if (people[j].age < people[min].age) {
				min = j;
			}
		}
		Swap(person, people[i], people[min]);
	}
	for (int i = 0; i < 30; i++) {
		fprintf(AgeDataFile, "%d/%s/%s/%s/%d/%s/%s\n", people[i].tag, people[i].date, people[i].fee, people[i].name, people[i].age, people[i].organization, people[i].job);
	}
	if (AgeDataFile != NULL) {
		fclose(AgeDataFile);
		AgeDataFile = NULL;
	}
}

//P5-1
/**
*
* sort_linked(char filename[], struct NODE* head2)
*
* Summary of the sort_linked function:
*
*	The sort_linked function save sorted data in linked list
*
* Parameters:	Filename[]: containing characters
*				head2: containing struct NODE*
* Return Value: result: none
*
*/
void sort_linked(char filename[], struct NODE* head2) {
	ReadData(filename);
	linked_list(head2);

	struct NODE* p;

	p = head2->next;
	while (p != NULL) {
		printf("%d/%s/%s/%s/%d/%s/%s\n", p->tag, p->date, p->fee, p->name, p->age, p->organization, p->job);
		p = p->next;
	}
}

//p6-1
/**
*
* delete_array(char deleted_name[])
*
* Summary of the delete_array function:
*
*	The delete_array function delete data in array
*
* Parameters:	deleted_name[]: containing characters
* Return Value: result: none
*
*/
void delete_array(char deleted_name[]) {
	int deleted_tag = 0;
	for (int i = 0;i < 30;i++) {
		if (strstr(people[i].name, deleted_name) != NULL) {
			int n;
			deleted_tag = people[i].tag;
			for (n = i;n < 29;n++) {
				people[n] = people[n + 1];
			}
			number--;

			people[n].tag = 0;
			people[n].date[0] = 0;
			people[n].fee[0] = 0;
			people[n].name[0] = 0;
			people[n].age = 0;
			people[n].organization[0] = 0;
			people[n].job[0] = 0;
			for (int k = 0; k < number; k++) {
				if (people[k].tag > deleted_tag) {
					people[k].tag = people[k].tag - 1;    //if the tag has bigger value than the deleted person's tag, then it has tag-1 value now
				}
			}
		}
	}
	for (int i = 0; i < number; ++i) {
		printf("%d/%s/%s/%s/%d/%s/%s\n", people[i].tag, people[i].date, people[i].fee, people[i].name, people[i].age, people[i].organization, people[i].job);
	}
}

//6-2
/**
*
* update_linked(struct NODE* head)
*
* Summary of the update_linked function:
*
*	The delete_array function delete data in linked list
*
* Parameters:	head: struct NODE*
* Return Value: result: none
*
*/
void update_linked(struct NODE* head) {
	struct NODE* ptr, * pre;
	ptr = head;
	pre = NULL;

	while (ptr) {
		if (strstr(ptr->name, "Kim") != NULL) {
			if (pre == NULL) {
				head = ptr->next;
			}
			else {
				pre->next = ptr->next;
			}
			free(ptr);
			ptr = head;
		}
		pre = ptr;
		ptr = ptr->next;
	}
	ptr = head->next;
	while (ptr != NULL) {
		printf("%d/%s/%s/%s/%d/%s/%s\n", ptr->tag, ptr->date, ptr->fee, ptr->name, ptr->age, ptr->organization, ptr->job);
		ptr = ptr->next;
	}
}

//P7-1
/**
*
* new_registration(int length, person new)
*
* Summary of the new_registration function:
*
*	The new_registration function insert new data
*
* Parameters:	length: containing int
*				new: containing person
* Return Value: result: none
*
*/
void new_registration(int length, person new) {
	int j = 0;
	for (int i = 0;i < length - 1;i++) {
		if (people[i].age / 10 == new.age / 10 + 1) {
			for (j = length;j > i;j--) {
				people[j].tag = people[j - 1].tag;
				strcpy(people[j].date, people[j - 1].date);
				strcpy(people[j].fee, people[j - 1].fee);
				strcpy(people[j].name, people[j - 1].name);
				people[j].age = people[j - 1].age;
				strcpy(people[j].organization, people[j - 1].organization);
				strcpy(people[j].job, people[j - 1].job);
			}
			people[j].tag = new.tag;
			strcpy(people[j].date, new.date);
			strcpy(people[j].fee, new.fee);
			strcpy(people[j].name, new.name);
			people[j].age = new.age;
			strcpy(people[j].organization, new.organization);
			strcpy(people[j].job, new.job);
			break;
		}
	}
	for (int i = 0;i < length + 1;i++) {
		printf("%d/%s/%s/%s/%d/%s/%s\n", people[i].tag, people[i].date,
			people[i].fee, people[i].name, people[i].age, people[i].organization, people[i].job);
	}
}
//7-2
/**
 * void linkedlist_new(struct NODE* new, struct NODE* head)
 * 
 * Summary of the linkedlist_new function:
 *      the linkedlist_new function, inserts a given data into it's age group
 *      and links them.
 * 
 * Parameters   : struct pointers
 * 
 * Return value : nothing       -- Note : modifies the struct "in place"
 * 
 * 
 */

void linkedlist_new(struct NODE* new, struct NODE* head) {
	struct NODE* ptr = (struct NODE*)malloc(sizeof(struct NODE));
	struct NODE* prv = (struct NODE*)malloc(sizeof(struct NODE));
	prv = head;
	ptr = prv->next;
	while (ptr) {
		if ((new->age) / 10 == ((ptr->age) / 10 - 1)) {
			prv->next = new;
			new->next = ptr;
			break;
		}

		prv = ptr;
		ptr = ptr->next;
	}
	ptr = head->next;
	printf("\n\n");

	while (ptr) {
		printf("%d %s %s %s %d %s %s\n", ptr->tag, ptr->date, ptr->fee, ptr->name, ptr->age, ptr->organization, ptr->job);
		ptr = ptr->next;
	}
}


/**
*
* save_last_name(int size)
*
* Summary of the save_last_name function:
*
*	The save_last_name function find & save last name of data
*
* Parameters:	size: containing int
* Return Value: result: none
*
*/
void save_last_name(int size) {
	int n = 0;
	for (int i = size-1; i>size-5  ; i--) {
		int size_of_the_name = strlen(people[i].name);
		int index_of_the_name = 0;
		for (int j = 0; j < size_of_the_name; j++) {
			if (people[i].name[j] == ' ') {
				for (int m = j + 1; m < size_of_the_name + 1; m++) {
					last_name[n][index_of_the_name] = people[i].name[m];
					index_of_the_name++;
				}
				break;
			}
		}
		printf("%s", people[i]);
	}
	/*
	for (int i = 0; i < size; i++) {
		printf("%d %s %s %s %d %s %s\n", people[i].tag, people[i].date, people[i].fee, people[i].name, people[i].age, people[i].organization, people[i].job);
	}*/
	for (int i = 0; i<5; i++){
		printf("last name : %s", last_name[i]);
	}
}

//P8-1
/**
*
* check_sum()
*
* Summary of the check_sum function:
*
*	The check_sum function make checksum data
*
* Parameters:	none
* Return Value: result: none
*
*/
void check_sum(){
	int checksum = 0;
	char recent_data[5][25];
	for (int i = 0; i < 5; i++) {
		strcpy(recent_data[i], last_name[i]);
	}
	for (int i = 0; i < 5; i++) {
		int count = strlen(recent_data[i]);
		for (int j = 0; j < count; j++) {
			checksum += MASK ^ recent_data[i][j];
		}
		//printf("%s\n", recent_data[i]);
	}
	//printf("%d\n", checksum);

	FILE* saved_data = fopen("8-1.txt", "w");
	fprintf(saved_data, "%d\n", checksum);
	for (int i = 0; i<5; i++){
        fprintf(saved_data,"%s\n", recent_data[i]);
    }
	fclose(saved_data);
}

/**
*
* compare_checksum()
*
* Summary of the check_sum function:
*
*	The compare_checksum function compare checksum data
*
* Parameters:	none
* Return Value: result: int type(error code)
*
*/
int compare_checksum() {
	char read_data[5][25];
	FILE* saved_data = fopen("8-1.txt", "r");

	int first_data_checksum = 0;
	int second_checksum = 0;
	fscanf(saved_data, "%d", &first_data_checksum);
	//printf("first_data_checksum : %d\n", first_data_checksum);

	char temp[5];
	for (int i = 0; i < 5; i++) {
		//fscanf( saved_data," %s", read_data[i]);
		fscanf(saved_data, " %[^\n]", read_data[i]);
		//printf("%s", read_data[i]);
	}
	for (int i = 0; i < 5; i++) {
		int count = strlen(read_data[i]);
		for (int j = 0; j < count; j++) {
			second_checksum += MASK ^ read_data[i][j];
		}
	}
	//printf("second_checksum : %d\n", second_checksum);
	if (first_data_checksum == 0) {
		printf("The data isn't sent\n");
		return -1;  //failed
	}
	if ((second_checksum ^ first_data_checksum) == 0) { //check if the original data and copied data are same.
		printf("data is sent successfully.\n");
		return 0;
	}
	else
		printf("different data sent!\n"); //if not, print error!
	fclose(saved_data);
	return -1;
}

void main() {
	//File name
	char Filename[] = "registraion_data.txt";
	char AgeFileName[] = "4-1.txt";

	struct NODE* head = (struct NODE*)malloc(sizeof(struct NODE));
	head->next = NULL;

	struct NODE* head2 = (struct NODE*)malloc(sizeof(struct NODE));
	head2->next = NULL;

	ReadData(Filename);

	linked_list(head);

	//p1-1
	printf("Search Kim in array\n\n");
	search_name("Kim");
	printf("\n\n");


	//p1-2
	printf("Search Kim in linked list\n\n");
	search_name_linked(head);
	printf("\n\n");

	//p2-1
	printf("Search Engineer at Gachon University in array\n\n");
	search_univ("Gachon University", "engineer");
	printf("\n\n");

	//p2-2
	printf("Search Engineer at Gachon University in linked list\n\n");
	search_linked(head);
	printf("\n\n");

	//p3-1
	printf("Sort the data in the array in tag# order\n\n");
	SortTag();
	printf("\n\n");

	//p4-1
	printf("Sort the data in the array in age group order\n\n");
	AgeSelectionSort(AgeFileName);
	printf("\n\n");

	//p5-1
	printf("new linked list\n\n");
	sort_linked(AgeFileName, head2);

	//p6-1
	printf("\nDelete Kim in array\n\n");
	delete_array("Kim");
	printf("\n\n");

	//p6-2
	printf("Delete Kim in linked list\n\n");
	update_linked(head2);
	printf("\n\n");

	//p7-1
	printf("Update Gildong Kang in array\n\n");
	person new_registrated_person = { number + 1, "2021-11-30", "yes", "Gildong Kang", 25, "Gachon University", "Student" };
	new_registration(number, new_registrated_person);
	printf("\n\n");

	//p7-2
	printf("Update Gildong Kang in linked list\n");
	struct NODE new_registrated_person_linked = { number + 1, "2021-11-30", "yes", "Gildong Kang", 25, "Gachon University", "Student" , NULL };
	linkedlist_new(&new_registrated_person_linked, head2);


	//p8-1
	printf("\nChecksum\n\n");
	save_last_name(number + 1);
	
	printf("\n\n");

	check_sum();
	int res_of_checksum = compare_checksum();
	if (res_of_checksum == 0) {
		printf("success\n");
	}
	else
		printf("failed\n");

}