#include <stdio.h>

int main(){
    FILE *fp;
    char str[10240];
    int ndx;

    fp = fopen("test.txt", "r");

    if (fp==NULL){
        printf("error!\n");
    }

    printf("fgets(str, 1024, fp): %s\n", fgets(str,1024,fp));
    printf("str                 : %s\n", str);

    fseek(fp,10,SEEK_SET);
    printf("%s\n", fgets(str, 1024, fp));

    fseek(fp, 5, SEEK_SET);
    fseek(fp, 5, SEEK_CUR);
    printf("%s\n", fgets(str, 1024, fp));

    fclose(fp);

    return 0;
}