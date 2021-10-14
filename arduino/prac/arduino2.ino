void setup(){

    pinMode(12, OUTPUT);
    pinMode(13, OUTPUT);

}

void loop(){
    digitalWirte(12, HIGH);
    delay(1000);
    digitalWrite(12, LOW);
    digitalWrite(13,HIGH);
    delay(1000);
    digitalWrtie(12, LOW);

}