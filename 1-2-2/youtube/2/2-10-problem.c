#include <stdio.h>

int main(){
    int student1;
    int student2;
    int student3;

    printf("3명의 학생의 점수를 정수로 입력하여 주십시오\n");
    scanf("%d %d %d", &student1, &student2, &student3);

    float avg = (float)(student1+student2+student3)/3;

    printf("세 학생의 평균은 %.1f입니다.\n", avg);

    return 0;

}

