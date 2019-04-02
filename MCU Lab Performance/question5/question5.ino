/*  Author: Arnob Karmokar
 *  ID: 16-01-05-055
 *  Created on 02 April 2019
 */
#include <OneWire.h> 
#include <DallasTemperature.h>
#include<Wire.h>
#include<LiquidCrystal_I2C.h>

#define ONE_WIRE_BUS 2 

OneWire oneWire(ONE_WIRE_BUS); 
DallasTemperature sensors(&oneWire);
LiquidCrystal_I2C lcd(0x3F,16,2);
void setup(void) 
{ 
 Serial.begin(9600); 
 sensors.begin(); 
 lcd.init();
 lcd.backlight();
} 
void loop(void) 
{  
 
 sensors.requestTemperatures();
 lcd.clear();
 Serial.print("Temperature is: "); 
 lcd.setCursor(0,0);
 lcd.print("TempDS: ");
 lcd.print(sensors.getTempCByIndex(0));
 lcd.print((char)223);
 lcd.print("C");
 lcd.setCursor(0,1);
 lcd.print("TempDS: ");
 lcd.print(sensors.getTempFByIndex(0));
 lcd.print((char)223);
 lcd.print("F");
 delay(1000); 
} 
