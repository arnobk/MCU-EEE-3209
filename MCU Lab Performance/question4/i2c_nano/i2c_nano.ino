/*  Author: Arnob Karmokar
 *  ID: 16-01-05-055
 *  Created on 02 April 2019
 */
#include<Wire.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,16,2);
#define slaveAddress 0x08
bool flag1 = false;
union
{
  float tempFloat;
  byte myArray[4];
} data;
void setup() {
  Serial.begin(9600);
  Wire.begin(slaveAddress);
  Wire.setClock(100000);
  Wire.beginTransmission(slaveAddress);
  Wire.onReceive(receiveEvent);
  lcd.init();
  lcd.backlight();
}

void loop() {
  if (flag1==true)
  {
    Serial.print("Received LM35's Temperature = ");
    Serial.print(data.tempFloat,2);
    //Serial.write(0xB0);
    Serial.print(" degC");
    Serial.println("");
    flag1 = false;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("TempLM35:");
    lcd.print(data.tempFloat);
    lcd.print((char)223);
    lcd.print("C");
  }
}

void receiveEvent(int howMany)
{
  for(int i = 0;i<howMany;i++){
    data.myArray[i] = Wire.read();
  }
  flag1 = true;
}
