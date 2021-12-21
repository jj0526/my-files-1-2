/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <stdio.h>
void two_dimen_erase_data(long arr[][2]);
void erase_data(long arr[]);

int Answer;

int main(void)
{
	int T, test_case;
    int times;
	
	setbuf(stdout, NULL);

	scanf("%d", &T);

    printf("hello");

    long num[100000][2] ={0};
    int index_of_group = 0;
    int index = 0;

    long result[1000000] = {0};

    for (int i = 0; i<100000; i++){
        num[i][1] = i+1;
    }

	for(test_case = 0; test_case < T; test_case++)
	{
        Answer = 0;
        two_dimen_erase_data(num);
        
        erase_data(result);
        
        scanf("%d", &times);

        for (int i = 0; i<times; i++)
            scanf("%li", &num[i][0]);
        
        for (int i = times-1; i>=0; --i){
            if (num[i][1]+num[i][0]<100000)
                num[i][1] =num[num[i][1]+num[i][0]-1][1];
        }

        for (int i = 0; i<times; i++){
            result[num[i][1]]++;
        }
        for (int i = 0; i<times; i++){
            if (result[i]>0)
                Answer++;
        }
        
		printf("Case #%d\n", test_case+1);
	    printf("%d\n", Answer);
        
	}

	return 0;//Your program should return 0 on normal termination.
}

void two_dimen_erase_data(long arr[][2]){
    int i = 0;
    while(arr[i][0]!=0){
        arr[i][0] = 0;
        ++i;
    }
    i = 0;
    while(arr[i][1]!=0){
        arr[i][1] = 0;
        ++i;
    }
}

void erase_data(long arr[]){
    int i = 0;
    while (arr[i]!=0){
        arr[i] = 0;
    }
}
