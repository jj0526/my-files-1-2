#include <Servo.h>

Servo myservo;

void setup(){

    pinMode(A0, INPUT);
    myservo.attach(9);

}

int num;

void loop(){

    num = AnalogRead(A0);

    num = map(num,0,1023,0,180);

    for (int i = 0; i<num; i++){
        myservo.write(i);
        delay(10);
    }
}