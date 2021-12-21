void setup(){
    pinMode(8, INPUT);
}

int count = 0;

void loop(){
    if (digitalRead(8)==LOW){
        count = 0;
    }
    Serial.println(count);
    count++;
}