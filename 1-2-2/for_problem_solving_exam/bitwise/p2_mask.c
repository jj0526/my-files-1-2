#include <stdio.h>
void convert(int num, char bin[15], char hex[5]);

int main(){
    for (int i = 1; i<20; i++){
        char bin_string[15];
        char hex_string[5];
        convert(i, bin_string, hex_string);
        printf("bin : %s, HEX : %s\n", bin_string, hex_string);

    }
}

void convert(int num, char bin[15], char hex[5]){
    int temp1 = num, temp2 = num;
    int index = 0;
    while(1){
        if (temp1==0){
            break;
        }
        bin[index] = temp1%2 + '0';
        index++;
        temp1/=2;
    }
    bin[index] = NULL;
    index = 0;
    while(1){
        if (temp2==0){
            break;
        }
        if(temp2%16>9){
            hex[index] = temp2%16 + 'A' - 10;
        }
        else{
            hex[index] = temp2%16 + '0';
        }
        temp2/=16;
        index++;
    }
    hex[index] = NULL;
    
}