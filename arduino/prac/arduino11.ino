void setup(){
    pinMode(A0, INPUT);
    pinMode (9, OUTPUT);
}

int num;
void loop(){
    num = analogRead(A0);
    num = map(num, 0,1023,0,255);
    analogWrite(9, num);
}