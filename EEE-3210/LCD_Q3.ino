/*Question
  Text will move from left to right and letter will come at first as soon as go out of screen.
*/
#include<Wire.h>
#include<LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2);
void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  char text[] = {'A','R','N','O','B'};
  for(int i=0;i<16;i++){
    for(int j = 0; j<sizeof(text);j++){
      lcd.setCursor((i+j)%16,0);
      lcd.print(text[j]);
    }
    delay(300); 
    lcd.clear();
  }
}
