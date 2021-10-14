void setup(){
    pinMode(A0, INPUT);
}
int num1;
float num2;
void loop(){
    num1 = analogRead(A0);
    num2 = (5.0 * (float)num1 * 100.0)/1024;

    Serial.println(num2);
}