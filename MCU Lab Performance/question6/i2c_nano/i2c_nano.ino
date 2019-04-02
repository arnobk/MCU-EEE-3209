/*  Author: Arnob Karmokar
 *  ID: 16-01-05-055
 *  Created on 02 April 2019
 */
#include<Wire.h>
#define slaveAddress 0x08
float wiperVoltage;
union
{
  float voltageFloat;
  byte myVoltageArray[4];
} arnob;

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
  wiperVoltage = (5/1023.0)*analogRead(A0);
  Serial.print("Wiper Voltage = ");
  Serial.print(wiperVoltage,2);
  Serial.print("V");
  Serial.println("");

  arnob.voltageFloat = wiperVoltage;

  //I2C Transmission

  Wire.beginTransmission(slaveAddress);
  Wire.write(arnob.myVoltageArray[0]);
  Wire.write(arnob.myVoltageArray[1]);
  Wire.write(arnob.myVoltageArray[2]);
  Wire.write(arnob.myVoltageArray[3]);
  Wire.endTransmission();
  delay(1000);
  
}
