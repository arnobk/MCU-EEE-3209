/*  Author: Arnob Karmokar
 *  ID: 16-01-05-055
 *  Created on 13 April 2019
 */
#include<OneWire.h>
#include<Wire.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C arnobLCD(0x3F,16,2);
#define DS_PIN 2
OneWire ds(DS_PIN);
float tempDS;
byte myData[9];
byte addr[8];

void setup() 
{
 Serial.begin(9600);
 initArnobLCD();
}

void loop() 
{
  collectTempDS();
  computeTempDS();
  Serial.print(tempDS,2);
  showOnArnobLCD();
  delay(1000);
}

void collectTempDS()
{
  ds.reset(); //reset the DS
  ds.search(addr); //search address of sensor
  /* code for printing DS sensor's unique 64-bit address
    for(int i=0;i<8;i++){
      if(addr[i]<0x10){
        Serial.print('0');
      }
      Serial.print(addr[i],HEX);
    } 
  */
  Serial.println("");
  ds.select(addr); //select sensor
  ds.write(0x44); //start conversion
  delay(1000);
  
  ds.reset(); //reset the DS
  ds.select(addr); //select sensor
  ds.write(0xBE);
  ds.read_bytes(myData,9); //read data
}

void computeTempDS()
{
  byte tempLByte = myData[0];
  byte tempHByte = myData[1];
  float fractionPart = (float) bitRead(tempLByte,3)*0.5 + bitRead(tempLByte,2)*0.25 + bitRead(tempLByte,1)*0.125 + bitRead(tempLByte,0)*0.0625;
  int integerPart = (tempHByte<<8) | tempLByte;
  integerPart = integerPart>>4;
  float intPart = (float) integerPart;
  tempDS = integerPart + fractionPart;
}

void initArnobLCD()
{
  arnobLCD.init();
  arnobLCD.backlight();
}

void showOnArnobLCD()
{
   arnobLCD.setCursor(0,0);
   arnobLCD.print("TempDS: ");
   arnobLCD.print(tempDS);
   arnobLCD.print((char)223);
   arnobLCD.print("C");
   arnobLCD.setCursor(0,1);
   arnobLCD.print("TempDS: ");
   arnobLCD.print((9*tempDS/5)+32);
   arnobLCD.print((char)223);
   arnobLCD.print("F");
}
