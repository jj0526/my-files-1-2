void setup(){

    pinMode(9, OUTPUT);
    Serial.begin(9600);
}

int n;
void loop(){
    digitalRead(n);

    for (int i = 0; i<n; i++){
        digitalWrite(9, HIGH);
        delay(100);
        digitalWrite(9,LOW);
        delay(100);
    }
}