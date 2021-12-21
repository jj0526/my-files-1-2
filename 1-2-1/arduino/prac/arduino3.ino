void setup(){

    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
}

void loop(){
    for (int i = 0; i<256; i++){
        analogWrite(10, i);
        analogWrite(10, 255-i);
        delay(10);
    }
}