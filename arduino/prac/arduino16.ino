#include <Servo.h> 

Servo Myservo;

void setup(){

    Myservo.attach(9);★★
}

int num = 0;
void loop(){

    for (int i = 0; i<181; i++){
        Servo.write(Myservo, i);
        delay(10);
    }

    for (int i = 0; i<181; i++){
        Servo.write(Myservo, 180-i);
    }

}