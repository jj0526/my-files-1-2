void setup(){
    pinMode(A0, INPUT);
    pinMode(A1, INPUT);
    pinMode(A2, INPUT);

    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
}

int a, b, c;
void loop(){
    a = analogRead(A0);
    b = analogRead(A1);
    c = analogRead(A2);
    a = map(a, 0, 1023, 0, 255);
    b = map(b, 0, 1023, 0, 255);
    c = map(c, 0, 1023, 0, 255);

    analogWrite(9, a);
    analogWrite(10, b);
    analogWrite(11, c);
}

