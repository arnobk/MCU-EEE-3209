/*  Author: Arnob Karmokar
 *  ID: 16-01-05-055
 *  Created on 02 April 2019
 */
#include<SoftwareSerial.h>
SoftwareSerial SUART(2,3);
float Temp;
void setup() {
  Serial.begin(9600);
  SUART.begin(9600);
}

void loop() {
  if(SUART.available())
  {
    Serial.print("Received TempLM: ");
    Temp=SUART.read();
    Temp=Temp+SUART.read()/100.0;
    Serial.print(Temp);
    Serial.print("DegC");
    Serial.println("");
  }
}
