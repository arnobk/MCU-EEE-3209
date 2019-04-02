/*  Author: Arnob Karmokar
 *  ID: 16-01-05-055
 *  Created on 02 April 2019
 */
#include<Wire.h>
#define slaveAddress 0x08
bool flag1 = false;
union
{
  float voltageFloat;
  byte myVoltageArray[4];
} arnob;
void setup() {
  Serial.begin(9600);
  Wire.begin(slaveAddress);
  Wire.setClock(100000);
  Wire.beginTransmission(slaveAddress);
  Wire.onReceive(receiveEvent);
}

void loop() {
  if (flag1==true)
  {
    Serial.print("Received wiper voltage of Pot: ");
    Serial.print(arnob.voltageFloat,2);
    Serial.print("V");
    Serial.println("");
    flag1 = false;
    
  }
}

void receiveEvent(int howMany)
{
  for(int i = 0;i<howMany;i++){
    arnob.myVoltageArray[i] = Wire.read();
  }
  flag1 = true;
}
