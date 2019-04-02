/*  Author: Arnob Karmokar
 *  ID: 16-01-05-055
 *  Created on 02 April 2019
 */
#include<Wire.h>
#define slaveAddress 0x08
float T;
union
{
  float tempFloat;
  byte myArray[4];
} data;

void setup() {
 pinMode(A0,INPUT); 
 Serial.begin(9600);
 //Initialization of I2C
 Wire.begin();
 Wire.setClock(100000);
 Wire.beginTransmission(slaveAddress);
 byte busStatus = Wire.endTransmission();
 if(busStatus!=0x00)
 {
  Serial.println("Slave is not present!");
  while(1);
 }
 Serial.println("Slave is Present");
}

void loop() {
  T = (500/1023.0)*analogRead(A0);
  Serial.print("LM35's Temperature = ");
  Serial.print(T,2);
  //Serial.write(0xB0);
  Serial.print(" degC");
  Serial.println("");

  data.tempFloat = T;

  //I2C Transmission

  Wire.beginTransmission(slaveAddress);
  Wire.write(data.myArray[0]);
  Wire.write(data.myArray[1]);
  Wire.write(data.myArray[2]);
  Wire.write(data.myArray[3]);
  Wire.endTransmission();
  delay(1000);
  
}
