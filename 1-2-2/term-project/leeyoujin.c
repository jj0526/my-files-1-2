//P3-1, P4-1

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>

#define MAXNUM 30
#define DEBUG
#define Swap(type, x, y) {type t = x; x = y; y = t;} //This function that changes the values of a and b

//Struct of the personal data in registraion_data.txt
struct PERSONALDATA {
	int tag;
	char date[15];
	char fee_paid[10];
	char name[25];
	int age;
	char organization[35];
	char job[15];
};

//Function prototype
void AgeSelectionSort(struct PERSONALDATA person[], char filename[]);
void ReadData(struct PERSONALDATA person[], char filename[]);
void SortTag(struct PERSONALDATA person[]);

//Global variables
int num = 0;


void main() {
	//Declaration
	struct PERSONALDATA person[MAXNUM];

	//File name
	char DataFilename[] = "registraion_data.txt";
	char AgeFileName[] = "4-1.txt";

	ReadData(person, DataFilename); //P3-1
#ifdef DEBUG
	printf("\nReadData is done.\n\n");
#endif // DEBUG

	SortTag(person); //P3-1
#ifdef DEBUG
	printf("\nSortTag is done.\n\n");
#endif // DEBUG

	AgeSelectionSort(person, AgeFileName); //P4-1
#ifdef DEBUG
	printf("\nAgeSelectionSort is done.\n\n");
#endif // DEBUG

}

//SelectionSort function selects the smallest element of the array and moves it forward to sort.
void AgeSelectionSort(struct PERSONALDATA person[], char filename[]) {  //Insert the array and the size of the array as parameters

	FILE* AgeDataFile = fopen(filename, "w");
	if (AgeDataFile == NULL) {
		printf("\nAgeDatafile File could not be opened.\n");
		return;
	}

	for (int i = 0; i < 29; i++) { 
		int min = i;
		for (int j = (i + 1); j < 30; j++) //Find the minimum element in array
			if (person[j].age < person[min].age)
				min = j;
		Swap(struct PERSONALDATA, person[i], person[min]); //Change the i-th element and the min element
	}
#ifdef DEBUG
	for (int i = 0; i < 30; i++) {
		printf("%d/%s/%s/%s/%d/%s/%s\n", person[i].tag, person[i].date, person[i].fee_paid, person[i].name, person[i].age, person[i].organization, person[i].job);
	}
#endif

	for (int i = 0; i < 30; i++) {
		fprintf(AgeDataFile, "%d/%s/%s/%s/%d/%s/%s\n", person[i].tag, person[i].date, person[i].fee_paid, person[i].name, person[i].age, person[i].organization, person[i].job);
	}

	if (AgeDataFile != NULL) {
		fclose(AgeDataFile);
		AgeDataFile = NULL;
#ifdef DEBUG
		printf("\nAgeDataFile file has been closed.\n");
#endif //DEBUG
	}
}

//The ReadData function fetches data from a file and stores it as an array.
void ReadData(struct PERSONALDATA person[], char filename[]) {


	FILE* PersonDataFile = NULL;
	PersonDataFile = fopen(filename, "r"); //Read the data
	if (PersonDataFile == NULL) {
		printf("\nDatafile File could not be opened.\n");
		return;
	}

	while (fscanf(PersonDataFile, "%d/%[^/]/%[^/]/%[^/]/%d/%[^/]/%s", &person[num].tag, person[num].date, person[num].fee_paid, person[num].name, &person[num].age, person[num].organization, person[num].job) == 7) //Read data
	{
#ifdef DEBUG
		printf("%d/%s/%s/%s/%d/%s/%s\n", person[num].tag, person[num].date, person[num].fee_paid, person[num].name, person[num].age, person[num].organization, person[num].job);
#endif //DEBUG
		num++;
	}

	if (PersonDataFile != NULL) {
		fclose(PersonDataFile);
		PersonDataFile = NULL;
#ifdef DEBUG
		printf("\nPersonDataFile file has been closed.\n");
#endif //DEBUG
	}
}

//The SortTag function uses Bubble Sort to sort from the order in which the tag is small
void SortTag(struct PERSONALDATA person[]) {
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 29; j++)
			if (person[j].tag > person[j + 1].tag)
				Swap(struct PERSONALDATA, person[j], person[j + 1]);
	}
#ifdef DEBUG
	for (int i = 0; i < 30; i++) {
		printf("%d/%s/%s/%s/%d/%s/%s\n", person[i].tag, person[i].date, person[i].fee_paid, person[i].name, person[i].age, person[i].organization, person[i].job);
	}
#endif //DEBUG
}