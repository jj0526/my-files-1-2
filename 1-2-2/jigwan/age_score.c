#include <stdio.h>

int main(){
    int age[100], score[100];

    for (int i = 0; i<5; i++){
        scanf("%d %d", &age[i], &score[i]);
    }

    int  highest, lowest;

    find_highest_and_lowest(&highest, &lowest, age, score);

    print("%d %d", highest, lowest);

}

void find_highest_and_lowest(int *high, int *low, int age[], int score[]){
    //0번째 인덱스 high
    // for 문 돌림
    // 만약에 high보다 더 값이 높을거 찾았어
    // 그러면 high = 그 값 해줌
    
    
}