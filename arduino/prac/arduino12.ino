void setup(){
    pinMode(10, INPUT);
    pinMode(A1, INPUT);
    pinMode(9, OUTPUT);

}
int num;
void loop(){
    num = analogRead(A1);
    num = map(num,0,1023,0,255);
    analogWrite(9, num);
    if (digitalRead(10)==LOW){
        digitalWrite(9,0);
    }
}