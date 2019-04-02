/*  Author: Arnob Karmokar
 *  ID: 16-01-05-055
 *  Created on 02 April 2019
 */
#include<DS3231.h>
#include<Wire.h>
#include<LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2);
DS3231  rtc(SDA, SCL);

void setup()
{
  Serial.begin(9600);
  rtc.begin();
  /* Next 3 Lines are used to set Sensor Time for the 1st time. It will save time on it's own memory*/
  //rtc.setDOW(TUESDAY);
  //rtc.setTime(22, 17, 20);
  //rtc.setDate(2, 4, 2019);

  lcd.init();
  lcd.backlight();
}

void loop()
{
  lcd.clear();
  lcd.setCursor(0,0);
  
  // Send Day-of-Week
  lcd.print(rtc.getDOWStr(FORMAT_SHORT));
  lcd.print(": ");
  
  // Send date
  lcd.print(rtc.getDateStr(FORMAT_LONG,FORMAT_LITTLEENDIAN,'/'));
  lcd.setCursor(0,1);
  lcd.print("Time: ");

  // Send time
  lcd.print(rtc.getTimeStr());
  
  delay (1000);
}
