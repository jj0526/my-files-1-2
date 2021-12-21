#include <LiquidCrystal.h>
  LiquidCrystal lcd(12,11,5,4,3,2);
  
  
  int sensor1=6;
  int sensor2=7;

  int cnt=0;
  
  int ir_1=0;
  int ir_2=0;

  int light1=8;
  int light2=9;
  int light3=10;

  int buttonState = 0;
  int previousbuttonState=0;

  int olds1Count, olds2Count;

  int s1Count = 0;
  int s2Count = 0;
  long t1, t2;

void setup() {
  Serial.begin (9600);
  pinMode(light1,OUTPUT);
  pinMode(light2,OUTPUT);
  pinMode(light3,OUTPUT);
  pinMode(sensor1,INPUT);
  pinMode(sensor2,INPUT);
  analogWrite(A0,1023);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  pinMode(13,INPUT);
}

void loop(){

  if (cnt>0){
    digitalWrite(light1, HIGH);
    digitalWrite(light2, LOW);
    digitalWrite(light3, LOW);
  }
  else{
    digitalWrite(light1, LOW);
    digitalWrite(light2, LOW);
    digitalWrite(light3, HIGH);
  }
  ir_1=digitalRead(sensor1);
  ir_2=digitalRead(sensor2);
  olds1Count = s1Count;
  olds2Count = s2Count;

  if(ir_1 == HIGH){
    t1 = millis();
  }

  if(t1 + 3000 > millis() && ir_2 == HIGH){
      cnt++; //들어오는거
    }
  
  if(ir_2 == HIGH){
    t2 = millis();
  }

  if(t2 + 3000 > millis() && ir_1 == HIGH){
      cnt--; //나가는거
  }

  lcd.clear();
  lcd.setCursor(0,0);

  previousbuttonState=buttonState;
  buttonState = digitalRead(8);
  if(buttonState==HIGH&&previousbuttonState==LOW){
    lcd.print("People : ");
    lcd.println(cnt);
    delay(2000);
    lcd.clear();
  }
}