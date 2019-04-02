/*  Author: Arnob Karmokar
 *  ID: 16-01-05-055
 *  Created on 02 April 2019
 */
#include<SoftwareSerial.h>
#include<Wire.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,16,2);
SoftwareSerial SUART(2,3);
float Temp;
void setup() {
  Serial.begin(9600);
  SUART.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop() {
  if(SUART.available())
  {
    lcd.clear();
    Serial.print("Received TempLM: ");
    Temp=SUART.read();
    Temp=Temp+SUART.read()/100.0;
    Serial.print(Temp);
    Serial.print("DegC");
    Serial.println("");
    lcd.setCursor(0,0);
    lcd.print("TempLM: ");
    lcd.print(Temp);
    lcd.print((char)223);
    lcd.print("C");
  }
}
