#include <stdio.h>
void calculate(int *, int *, int *, int *, int *, int *);

int main(){
    int N1,N2, re1, re2, re3, re4;

    scanf("%d %d", &N1, &N2);

    calculate(&N1, &N2, &re1, &re2, &re3, &re4);

    printf("%d, %d, %d, %d", re1, re2, re3, re4);

    return 0;

}

void calculate(int *n1, int *n2, int *re1, int *re2, int *re3, int *re4){
    *re1 = *n1 * *n2;
    *re2 = *n1 / *n2;
    *re3 = *n1 % *n2;
    *re4 = *n1 + *n2;
}


/*
Today, im going to talk about my best friend.
i first met my best friend hye-jin during an after school program when i was 5 years old.
we went to the same elementary school and we hung out almost everyday, even on weekends.
we stopped talking and hanging out because we ended up going to different schools  
we have tried to plan a meet up again but we were so busy studying.
when we finally had time to meet, covid became an issue.
i hope covid pandemic ends soon.
so i can go outside and meet my best friend.
I hope we can hang out like we used to when we were little in the future.
Thank you for watching my video.*/