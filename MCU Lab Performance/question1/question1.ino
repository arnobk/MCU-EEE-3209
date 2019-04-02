/*  Author: Arnob Karmokar
 *  ID: 16-01-05-055
 *  Created on 02 April 2019
 */
float Temp;
void setup() {
  pinMode(A0,INPUT);
  Serial.begin(9600);
}

void loop() {
  Temp = (500/1023.0)*analogRead(A0);
  Serial.print("TempLM: ");
  Serial.print(Temp,2);
  Serial.print(" degC b");
  Serial.println("");
  delay(1000);
}
