/* Question
  TEXT will move like a snake on 16x2 LCD Display.
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
    for(int pos=0;pos<sizeof(text);pos++){
        if((i+pos)%2==0)
        {   
          lcd.setCursor(i+pos,1); 
          lcd.print(text[pos]); 
        } else {
          lcd.setCursor(i+pos,0);
          lcd.print(text[pos]);  
        }
    }  
  delay(1000);
  lcd.clear();
  }  
}
