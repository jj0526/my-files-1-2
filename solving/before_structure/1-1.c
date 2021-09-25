#include <stdio.h>

int main(){
    int age[5], scores[5];// makes each array a 5-element integer array
    int maxagegrp[5], minagegrp[5];
    int maxage = -1, minage = 1000, maxscore=-1, minscore=1000;
    int maxagecnt=0, minagecnt=0, maxscorecnt=0, minscorecnt=0;
    int maxscoregrp[5], minscoregrp[100];

    printf("input the age and score of the student\n");

    for (int i = 0; i<5; i++){
        scanf("%d %d", &age[i], &scores[i]);//saves 2 data of age and score
        if ((age[i]<=0)||(scores[i]<=0)){//if age<=0(international age) or the score<=0
            printf("input the age and score again\n");
            i--;
        }
    }
    for (int i = 0; i<5; i++){
        if (maxage < age[i]){
            maxagecnt = 0;
            maxage = age[i];             // new max age found
            maxagegrp[maxagecnt] = i;    //save the age index
        }
        else if(age[i]==maxage){
            maxagecnt++;                 //tie max age found
            maxagegrp[maxagecnt] = i;    //save the age index
        }
        if (minage > age[i]){
            minagecnt = 0;
            minage = age[i];             // new max age found
            minagegrp[minagecnt] = i;    //save the age index
        }
        else if(minage==age[i]){ 
            minagecnt++;                 //tie max age found
            minagegrp[minagecnt] = i;    //save the age index
        }
        if ( maxscore < scores[i] ){
            maxscorecnt = 0;
            maxscore = scores[i];        // new max age found
            maxscoregrp[maxscorecnt] = i;  //save the age index
        }
        else if (maxscore == scores[i]){
            maxscorecnt++;               //tie max age found
            maxscoregrp[maxscorecnt] = i;  //save the age index
        }
        if (minscore > scores[i]){
            minscorecnt = 0;
            minscore = scores[i];         // new max age found
            minscoregrp[minscorecnt] = i; //save the age index
        }
        else if (minscore == scores[i]){
            minscorecnt++;                //tie max age found
            minscoregrp[minscorecnt] = i; //save the age index
        }
    }
    
    for (int i = 0; i<maxagecnt+1; i++){// print the data
        printf("score for an oldest student = %d\n", scores[maxagegrp[i]]);
    }
    for (int i = 0; i<minagecnt+1; i++){
        printf("score for an youngest studnet = %d\n", scores[minagegrp[i]]);
    }
    for (int i = 0; i<maxscorecnt+1; i++){
        printf("age for a student with highest score = %d\n", age[maxscoregrp[i]]);
    }
    for (int i = 0; i<minscorecnt+1; i++){
        printf("age for a student with lowest score = %d\n", age[minscoregrp[i]]);
    }

    return 0;

}