void setup(){
    pinMode(A0, INPUT);
    pinMode(13, OUTPUT);
}
int num;
void loop(){
    num = analogRead(A0);
    if (num>511){
        digitalWrite(13, HIGH);
    }
    else{
        digitalWrite(13, LOW);
    }
}