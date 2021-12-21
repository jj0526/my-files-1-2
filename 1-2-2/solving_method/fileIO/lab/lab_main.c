#include <stdio.h>
#include <string.h>


/**
 * File : lab_main.c
 * 
 * Author : Jeon Sihyeon (wjstlgus13@gachon.ac.kr)
 * Date : 11/02/2021
 * Partner : I worked alone
 * Course : Problem solving method
 * 
 * Summary of File:
 * 
 *      This file contains code which shows the user salaries
 *      Functions allow the user of the software to see calculated salaries
 *      of people and compared the salaries before and after
 * 
**/

struct salary{
    char name[20];
    int age;
    float sal;
};

float sum_of_salaries(struct salary sala[], int size); //declaration
void comp(struct salary sala[], int size, FILE *sal_file1,  float sum1);//declaration

int main(){

    FILE *sal_file1, *sal_file2, *sal_file3;

    sal_file1 = fopen("salary_v1.txt", "r");        // open salary_v1.txt file to read

    if (sal_file1==NULL){                           // if there's no such file
        printf("This File Could Not Be Opened.\n");
        return 0;
    }

    struct salary sala[100];

    char scanfed;

    int index = 1;  //index in name
    int per = 0;    // the number of people

    while (fscanf(sal_file1, " %s", sala[per].name) != EOF){                  //before the end of file
        index = 1;
        fscanf(sal_file1, "%d", &sala[per].age);            //saves int number s
        fscanf(sal_file1, "%f", &sala[per].sal);            //saves float numbers
        per++;
    }

    float sum1 = sum_of_salaries(sala, per);         // calls the function sum_of_salaries

   

    sal_file2 = fopen("salary_v2.txt", "w");        //open salary_v2.txt to write

    for (int i = 0; i<per; i++){
        if ((sala[i].age>=40)&&(sala[i].age<=49)){  //if they're 40s
            sala[i].sal*=0.9;                       // their salaries reduce by 10%
        }
        fprintf(sal_file2, "%-10s %-10d %f\n", sala[i].name, sala[i].age, sala[i].sal);//print their name, age and salary
    }
    fclose(sal_file2);    //close the file
    
    sal_file3 = fopen("salary_v3.txt", "w");        //open salary_v3.txt to write
    for (int i = 0; i<per; i++){
        if ((sala[i].age>=30)&&(sala[i].age<=39)){ // if they're 30s
            sala[i].sal*=1.2;                       // their salaries get 20% more 
        }
        
        fprintf(sal_file3,"%-10s %-10d %f\n", sala[i].name, sala[i].age, sala[i].sal);
    }

    fclose(sal_file3);      //close the file
    fclose(sal_file1);      // close the file
    sal_file1 = fopen("salary_v1.txt", "r");        //open salary_v1.txt to read

    comp(sala, per, sal_file1, sum1);                // calls comp function
    
    fclose(sal_file1);                               //close the sal_file1 file
    return 0;

}

/**
 * 
 * void comp(struct salary sala[], int size, FILE *sal_file1,  float sum1)
 * 
 * Summary of the comp function:
 *      The comp function, compares salary_v1.txt and salary_v3.txt
 *      and calculates the total salary of all employees for salary_v1
 *      and salary_v3, respectively
 * 
 * Parameters : structer array : containing array, integer number and float number
 *              integer number, float number and a file
 * 
 * REturn Value : nothing 
 *                          --  Note : modifies the array "in place"
 * 
 * Description:
 * 
 *      This function write the salaries on compare_v1_v3.txt file
 *      Note, the array is modified in place
 * 
**/

void comp(struct salary sala[], int size, FILE *sal_file1,  float sum1){

    FILE *comps;
    
    comps = fopen("compare_v1_v3.txt", "w");        // open compare_v1_v3.txt to write

    char str[100][100];

    float sum2 = sum_of_salaries(sala, size);       //calls the sum_of_salaries function 
    
    int i = 0;                          //current index
    int len = 0;
    int checking = 0;
    int indexs;
    fprintf(comps, "Name     age           Salary\n");
    while(fscanf(sal_file1, " %[^\n]", str[i]) != EOF){ //save the string into str[i] until the end of the file
        len = strlen(str[i]);           //the length of str[i]
        str[i][len-1] = '\0';           //put '\0' in str[i]
        fputs(str[i], comps);
        fputs( " -> ", comps);
        fprintf(comps, "%f\n", sala[i].sal);    //write down data on comps
        i++;
    }
    
    fprintf(comps, "Total :       %.2f -> %.2f\n", sum1, sum2);   //write down data on comps (total salaries)
    
    fclose(comps);                          //close the comps file

}
/**
 * 
 * float sum_of_salaries(struct salary sala[], int size)
 * 
 * Summary of the comp function:
 *      The sum_of_salaries function finds the sum of the array by adding all the numbers in the array
 * 
 * Parameters : struct : 
 *                  containing array, integer number and float number
 *              integer number
 * 
 * Return Value : float -- Note : modifies the array "in place"
 * 
 * Description :
 * 
 *      This function utilizes adding with calculator
 *      Note, the array is modified in place.
 * 
**/
float sum_of_salaries(struct salary sala[], int size){
    float sum = 0;
    for (int i = 0; i<size; i++){
        sum+=sala[i].sal;       //adds sala[i] and saves into sum
    }
    return sum;
}