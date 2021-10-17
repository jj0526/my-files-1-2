void setup(){
    pinMode(2, OUTPUT);
    pinMode(3, INPUT);
    pinMode(8, OUTPUT);
}

float num;

void loop(){
    !
    digitalWrite(Trig,HIGH);
    delayMicroseconds(10);
    digitalWrite(Trig,LOW);
  
    float dist = pulseIn(Echo, HIGH);
    !
    num = (float)(analogRead(3))/58.2;

    if (num<10){
        tone(8, 523);
    }
    else if (num<20){
        tone(8, 587);
    }
    else if (num<30){
        tone(8, 659);
    }
    else{
        noTone(8);
    }

}