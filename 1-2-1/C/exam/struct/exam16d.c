struct link{
    char key[10];
    struct link *next;
}node[5];

int main(){
    for (int i = 0; i<4; i++){
        node[i].next = &node[i+1];
    }
}