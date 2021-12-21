#define _CRT_SECURE_NO_WARNINGS
#define MAXNUM 30
#define DEBUG
#define Swap(type, x, y) {type t = x; x = y; y = t;}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Data {
	int tag;
	char date[15];
	char fee[5];
	char name[25];
	int age;
	char organization[35];
	char job[15];
}person;

typedef struct linked_Data {
	int tag;
	char date[15];
	char fee[5];
	char name[25];
	int age;
	char organization[35];
	char job[15];
}Data;

typedef struct LinkedList {
	Data data;
	Data* next;
}LinkedList;

person people[MAXNUM];

/*//P1-1
void search_name(char what[]) {
	for (int i = 0;i < 30;i++) {
		if (strcmp(strstr(people[i].name, " ") + 1, what) == 0) {
			printf("%d/%s/%s/%s/%d/%s/%s\n", people[i].tag, people[i].date,
				people[i].fee, people[i].name, people[i].age, people[i].organization, people[i].job);
		}
	}
}

//P1-2
void search_name_linked(char filename[]) {
	FILE* fp = fopen(filename, "r");
	char* tok;
	char str[256];
	Data data;
	LinkedList* head = (LinkedList*)malloc(sizeof(LinkedList));
	LinkedList* p;
	head->next = NULL;

	while (fgets(str, 256, fp)) {
		tok = strtok(str, "/");
		strcpy(data.tag, tok);
		tok = strtok(NULL, "/");
		strcpy(data.date, tok);
		tok = strtok(NULL, "/\n");
		strcpy(data.fee, tok);
		tok = strtok(NULL, "/\n");
		strcpy(data.name, tok);
		tok = strtok(NULL, "/\n");
		strcpy(data.age, tok);
		tok = strtok(NULL, "/\n");
		strcpy(data.organization, tok);
		tok = strtok(NULL, "/\n");
		strcpy(data.job, tok);
		addList(head, data);
	}
	fclose(fp);
	p = head->next;
	while (p) {
		if (strstr(p->data.name, "Kim") != NULL) {
			printf("%s/%s/%s/%s/%s/%s/%s\n", p->data.tag, p->data.date, p->data.fee, p->data.name, p->data.age, p->data.organization, p->data.job);
		}
		p = p->next;
	}
}

//P2-1
void search(char Un[], char Job[]) {
	for (int i = 0;i < 30;i++) {
		if (strcmp(people[i].organization, Un) == 0 && strcmp(people[i].job, Job) == 0) {
			printf("%d/%s/%s/%s/%d/%s/%s\n", people[i].tag, people[i].date,
				people[i].fee, people[i].name, people[i].age, people[i].organization, people[i].job);
		}
	}
}*/

//P2-2
void search_linked(char filename[]) {
	FILE* fp = fopen(filename, "r");
	char* tok;
	char str[256];
	Data data;
	LinkedList* head = (LinkedList*)malloc(sizeof(LinkedList));
	LinkedList* p;
	head->next = NULL; //dummy head

	char ctag[50][5];
	char cage[50][5];
	int i = 0;
	while (fgets(str, 256, fp))
	{
		tok = strtok(str, "/");
		strcpy(ctag[i], tok);
		tok = strtok(NULL, "/");
		strcpy(data.date, tok);
		tok = strtok(NULL, "/\n");
		strcpy(data.fee, tok);
		tok = strtok(NULL, "/\n");
		strcpy(data.name, tok);
		tok = strtok(NULL, "/\n");
		strcpy(cage[i], tok);
		tok = strtok(NULL, "/\n");
		strcpy(data.organization, tok);
		tok = strtok(NULL, "/\n");
		strcpy(data.job, tok);
		addList(head, data);
		data.tag = atoi(ctag[i]);
		data.age = atoi(cage[i]);
		
	}

	fclose(fp);

	//printList(head);



	p = head->next;

	while (p)
	{

		if (strstr(p->data.organization, "Gachon University") && strstr(p->data.job, "engineer") != NULL)
		{
			printf("(%s/%s/%s/%s/%s/%s/%s)  \n", p->data.tag, p->data.date, p->data.fee, p->data.name, p->data.age, p->data.organization, p->data.job);
		}
		p = p->next;
	}
}

//P3-1
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
	printf("\n\n");
	for (int i = 0; i < 30; i++) {
		printf("%d/%s/%s/%s/%d/%s/%s\n", people[i].tag, people[i].date, people[i].fee, people[i].name, people[i].age, people[i].organization, people[i].job);
	}

	if (AgeDataFile != NULL) {
		fclose(AgeDataFile);
		AgeDataFile = NULL;
	}
}

//P5-1
void sort_linked(char filename[]) {
	FILE* fp = fopen(filename, "r");
	char* tok;
	char str[256];
	Data data;
	LinkedList* head = (LinkedList*)malloc(sizeof(LinkedList));
	LinkedList* p;
	head->next = NULL;

	while (fgets(str, 256, fp)) {
		tok = strtok(str, "/");
		strcpy(data.tag, tok);
		tok = strtok(NULL, "/");
		strcpy(data.date, tok);
		tok = strtok(NULL, "/\n");
		strcpy(data.fee, tok);
		tok = strtok(NULL, "/\n");
		strcpy(data.name, tok);
		tok = strtok(NULL, "/\n");
		strcpy(data.age, tok);
		tok = strtok(NULL, "/\n");
		strcpy(data.organization, tok);
		tok = strtok(NULL, "/\n");
		strcpy(data.job, tok);
		addList(head, data);
	}
	fclose(fp);
	p = head->next;
	while (p) {
		printf("%s/%s/%s/%s/%s/%s/%s\n", p->data.tag, p->data.date, p->data.fee, p->data.name, p->data.age, p->data.organization, p->data.job);
		p = p->next;
	}
}

//P6-1
int delete_array(char deleted_name[]) {
	int count = 30;

	int size_of_name = 0;
	int size_of_deleted_name = strlen(deleted_name);
	int deleted_tag = 0;

	for (int i = 0;i < 30;i++) {
		size_of_name = strlen(people[i].name);
		for (int j = 0;j < size_of_name;j++) {
			if (people[i].name[j] == deleted_name[0]) {
				int count_of_the_same_letter = 0;
				for (int m = 0;m < size_of_deleted_name;m++) {
					if (people[i].name[m + j] != deleted_name[m]) {
						break;
					}
					count_of_the_same_letter++;
					if (size_of_deleted_name == count_of_the_same_letter) {
						deleted_tag = people[i].tag;
						int n;
						for (n = i;n < 29;n++) {
							people[n].tag = people[n + 1].tag;
							strcpy(people[n].date, people[n + 1].date);
							strcpy(people[n].fee, people[n + 1].fee);
							strcpy(people[n].name, people[n + 1].name);
							people[n].age = people[n + 1].age;
							strcpy(people[n].organization, people[n + 1].organization);
							strcpy(people[n].job, people[n + 1].job);
						}
						count--;
						people[n].tag = 0;
						people[n].date[0] = 0;
						people[n].fee[0] = 0;
						people[n].name[0] = 0;
						people[n].age = 0;
						people[n].organization[0] = 0;
						people[n].job[0] = 0;

						for (int k = 0;k < count;k++) {
							if (people[k].tag > deleted_tag) {
								people[k].tag = people[k].tag - 1;
							}
						}
					}
				}
			}
		}
	}
	for (int i = 0;i < count;i++) {
		printf("%d/%s/%s/%s/%d/%s/%s\n", people[i].tag, people[i].date,
			people[i].fee, people[i].name, people[i].age, people[i].organization, people[i].job);
	}
	return count;
}

//P7-1
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

void ReadData(char filename[]){
	int n = 0;
	FILE* inFile = NULL;
	inFile = fopen(filename, "r");
	if (inFile == NULL) {
		printf("\nInput File Could Not Be Opened.\n");
		return;
	}
	while (fscanf(inFile, "%d/%[^/]/%[^/]/%[^/]/%d/%[^/]/%s", &people[n].tag, people[n].date,
		people[n].fee, people[n].name, &people[n].age, people[n].organization, people[n].job) == 7) {
		n++;
	}

	if (inFile != NULL) {
		fclose(inFile);
		inFile = NULL;
	}
}

void addList(LinkedList* head, Data data) {
	LinkedList* p = head;
	LinkedList* add = (LinkedList*)malloc(sizeof(LinkedList));
	add->data = data;
	add->next = NULL;
	
	while (p->next) {
		p = p->next;
	}
	p->next = add;
}


int load_data(FILE *original_data, person *registered_person){
    char temp[10];
    char ctag[5];
    char cage[5];
    if (fscanf(original_data, " %[^/]", ctag)!=EOF){
        fscanf(original_data, " %[/]", temp);
        fscanf(original_data, " %[^/]", registered_person->date);
        fscanf(original_data, " %[/]", temp);
        fscanf(original_data, " %[^/]", registered_person->fee);
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

void main() {
	//File name
	char Filename[] = "registraion_data.txt";
	char AgeFileName[] = "4-1.txt";

	
    //person people[50];
    
    FILE *original_data;
    original_data = fopen("registraion_data.txt", "r");

    if (original_data == NULL)
    {
        printf("This File Could Not Be Opened.\n"); // if there's no such file
        return 0;
    }

    int length = 0; //30
    for (length = 0; load_data(original_data, &(people[length])); length++); //save data on structers

    fclose(original_data);

/*	ReadData(Filename);

	//p1-1
	printf("Search Kim\n\n");
	search_name("Kim");
	printf("\n\n");

	//p1-2
	search_name_linked(Filename);
	printf("\n\n");

	//p2-1
	printf("Search Engineer at Gachon University\n\n");
	search("Gachon University", "engineer");
	printf("\n\n");*/

	//p2-2
	//search_linked(Filename);  //

	//p3-1
	SortTag();
	printf("\n\n");

	//p4-1
	AgeSelectionSort(AgeFileName);
	printf("\n\n");

	//p5-1
	//sort_linked(AgeFileName);

	//p6-1
	int new_length = delete_array("Kim");
	printf("\n\n");

	//p7-1
	person new_registrated_person = { new_length + 1, "2021-11-30", "yes", "Gildong Kang", 25, "Gachon University", "Student" };
	new_registration(new_length, new_registrated_person);
}