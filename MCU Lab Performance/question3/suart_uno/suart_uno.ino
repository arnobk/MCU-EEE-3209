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
  pinMode(A0,INPUT);
}

void loop() {
  Temp = (500/1023.0)*analogRead(A0);
  byte intTemp= int(Temp);
  byte floatTemp=( Temp-intTemp)*100;
  Serial.println(Temp);
  SUART.write(intTemp);
  SUART.write(floatTemp);
  delay(1000);

}
