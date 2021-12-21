/*#include <LiquidCrystal>
LiquidCrystal = ld(11,12,2,3,4,5);
*/
#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);


void setup(){
    /*ld.
    ld.cursor(0,0);
    ld.write("Hello World!");
    */
    lcd.begin(16,2);
    lcd.setCursor(0,0);
    lcd.print("hello, world!");
}

void loop(){
    
}