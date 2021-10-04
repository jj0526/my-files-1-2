int main{
    int count = 0;
    char string[100];
    char search_string[20];

    int check;

    int size;                    // size of search_string

    printf("input a string\n");
    scanf("%[^\n]", string);    // i am hong gil dong
    printf("%s", string);

    printf("input the string you want to find\n");
    // hong*dong
    while(1){
        scanf("%[^\n]", search_string);
        printf("search_string : %s", search_string);
        size = str_length(search_string);
        printf("size : %d", size);
        check = includes(search_string, size);
        if (check < 2){
            break;
        }
        printf("%d", check);
    }
    if (check){   // with * ex) hong*dong
        char divided1[20];     // hong
        char divided2[20];     // dong
        
    }
    else{//without * ex) hong gil dong



    }
    printf("returned check : %d", check);
    
    divide(search_string, divided1, divided2, size);

    int cursor1 = 0, cursor2 = 0, ori = 0, divided1_count = 0;

    int len = str_length(string);

    printf("len of string : %d", len);

    char first[25], second[25]; // indexs of divided1 and divided2
    int first_count = 0, second_count = 0;

    
    while(string[cursor1]!=NULL){
        ori = 0;
        while(1){
            if(string[cursor1]==divided1[ori]){
                if (ori == str_length(divided1)){
                    first[first_count] = cursor1-str_length(divided1);
                    first_count++;
                }
            }
            else{
                break;
            }
            cursor1++;
            ori++;
        }
        cursor1++;
        printf("%d", cursor1);
    }
    cursor1 = 0;
    while(string[cursor1!=NULL]){
        ori = 0;
        while(1){
            if(string[cursor1]==divided2[ori]){
                if (ori == str_length(divided1)){
                    second[second_count] = cursor1-str_length(divided2);
                    second_count++;
                }
            }
            else{
                break;
            }
            cursor1++;
            ori++;
        }
         cursor1++;
    }
    for (int i = 0; i<25; i++){
        if (first[i]!=NULL){
            printf("%d ", first[i]);
        }
        else{
            break;
        }
    }
    for (int i = 0; i<25; i++){
        if (second[i]!=NULL){
            printf("%d ", second[i]);
        }
        else{
            break;
        }
    }
    
    //   i am hong gil dong
    
}