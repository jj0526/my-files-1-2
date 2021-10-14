void setup(){

    pinMode(8, INPUT);
    pinMode(13, OUTPUT);

}

int num;
void loop(){
    num = digitalRead(8);

    if (num==HIGH){
        digitalWirte(13, LOW);
    }
    else{
        digitalWrite(13, HIGH);
    }
}