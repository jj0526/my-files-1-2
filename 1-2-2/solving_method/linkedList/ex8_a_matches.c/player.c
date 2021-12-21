#include <stdio.h>

struct player{
    int back_num;
    char name[20];
    int age;
    int goals;
    int A;
    struct player *next;
}players[7];

int main(){
    FILE *player_data;
    player_data = fopen("data.txt", "r");
    int index = 0;
    while(fscanf(player_data, "%d", &players[index].back_num)!=EOF){
        int j = 0;
        /*while (1){
            fscanf(player_data, " %c", &players[i].name[j]);
            if (players[i].name[j]==' ')
                break;
            j++;
            printf("j : %d", j);
        }
        while (1){
            fscanf(player_data, " %c", &players[i].name[j]);
            if (players[i].name[j]==' ')
                break;
            j++;
        }*/
        
        fscanf(player_data, " %s", players[index].name);
        
        j = strlen(players[index].name)+1;
        players[index].name[j-1] = ' ';
        fscanf(player_data, " %s", &players[index].name[j]);
        
        fscanf(player_data, "%d", &players[index].age);
        fscanf(player_data, "%d", &players[index].goals);
        fscanf(player_data, "%d", &players[index].A);
        index++;
    }
    /*for (int m = 0; m<7; m++){
        printf("%d %s %d %d %d\n", players[m].back_num, players[m].name, players[m].age, players[m].goals, players[m].A );
    }
    */

    for (int i = 0; i<6; i++){
        players[i].next = &players[i+1];
    }

    players[6].next = NULL;

    int max_age = players[0].age;

    struct player *ptr;
    ptr = (struct player*)malloc(sizeof(struct player));
    ptr = &players[0];

    while(ptr){
        if (max_age < ptr->age){
            max_age = ptr->age;
        }
        ptr = ptr->next;
    }
    printf("max age : %d\n", max_age);

    ptr = &players[0];

    while(ptr){
        if ((ptr->age)<=29 && (ptr->age)>=25 && (ptr->goals)>=5 && (ptr->A)>=30){
            printf("%d %s %d %d %d\n", ptr->back_num, ptr->name, ptr->age, ptr->goals, ptr->A );
        }
        ptr = ptr->next;
    }


    return 0;
}