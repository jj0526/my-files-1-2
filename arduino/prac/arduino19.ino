void setup(){
    pinMode(2, INPUT);
    pinMode(3, INPUT);
    pinMode(4, INPUT);
    pinMode(8, OUTPUT);
}

void loop(){
    if (digitalRead(2)==HIGH){
        tone(8, 523);
    }
    else if (digitalRead(3)==HIGH){
        tone(8,554);
    }
    else if (digitalRead(4)==HIGH){
        tone(8, 659);
    }else{
        notone(8);
    }
}