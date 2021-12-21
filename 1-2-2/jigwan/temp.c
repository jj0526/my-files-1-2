#include <stdio.h>
#pragma warning(disable: 4996)

int main(void)
{
    int age[100], scores[100];

    for (int i = 0; i < 5; i++)
    {
        scanf("%d %d", &age[i], &scores[i]);
    }
    int age_highest, age_lowest, score_highest, score_lowest;

    students(&age_highest, &age_lowest, &score_highest, &score_lowest, age, scores);

    printf("%d %d %d %d", age_highest, age_lowest, score_highest, score_lowest);
}

void students(int *age_highest, int *age_lowest, int *score_highest, int *score_lowest, int age[], int score[])
{
    *age_highest = age[0];

    for (int i = 0; i < 5; i++)
    {
        if (*age_highest < age[i])
            *age_highest = age[i];
    }

    *age_lowest = age[0];

    for (int i = 0; i < 5; i++)
    {
        if (*age_lowest > age[i])
            *age_lowest = age[i];
    }

    *score_highest = score[0];

    for (int i = 0; i < 5; i++)
    {
        if (*score_highest < score[i])
            *score_highest = score[i];
    }

    *score_lowest = score[0];

    for (int i = 0; i < 5; i++)
    {
        if (*score_lowest > score[i])
            *score_lowest = score[i];
    }

}

/*
    선언을 한다 age랑 scores
    scanf로 5개를 받는다
    함수를 만들고
    그 함수안에서 제일 높은거랑 낮은거 찾기 (pointer 이용해서 값을 바꿔줌)
    출력
*/
/*
    같은 기능이니까 함수 1개를 만들어서 2번 사용한다 (highest,)
    vs
    함수 1개 안에서 2개 다 한다
*/