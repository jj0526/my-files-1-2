void setup(){

    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);

    pinMode(2, INPUT);
    pinMode(3, INPUT);
    pinMode(4, INPUT);
}

void loop(){
    if (digitalRead(2)==HIGH){
        digitalWrite(9, HIGH);
    }
    else{
        digitalWrite(9, LOW);
    }
    if (digitalRead(3)==HIGH){
        digitalWrite(10, HIGH);
    }
    else{
        digitalWrite(10, LOW);
    }
    if (digitalRead(4)==HIGH){
        digitalWrite(11, HIGH);
    }
    else{
        digitalWrite(11, LOW);
    }
}