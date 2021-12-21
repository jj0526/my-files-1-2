void setup(){

}

void loop(){
    tone(8, 523,500);
    delay(500);
    tone(8,587, 500);
    delay(500);
    notone(8);
    delay(1000);
}