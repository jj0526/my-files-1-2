#include <stdio.h>

int main(){
    int hr, min, sec;
    scanf("%d %d %d", &hr, &min, &sec);

    printf("%d", secs(hr, min, sec));

    return 0;

}

int secs(int hr, int min, int sec){
    return sec + 60 * min +3600*hr;
}
