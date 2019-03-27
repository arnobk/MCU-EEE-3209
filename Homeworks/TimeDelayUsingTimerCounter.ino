/* Problem: Generate time delay using Internal Timer/Counter of ATMega328P in Arduino
 *  Author: Arnob Karmokar
 *  ID: 16-01-05-055
 *  Created on 27 March 2019 
 *  For Reference, read Chapter 18 on GM Sir's Book 
 */
void setup() {
  pinMode(13,OUTPUT);
  TCCR1A = 0x00;  //normal mode of operation for Divider-1
  TCCR1B = 0x00;  //normal mode of operation for Divider-2
  TCCR1B = 0x02;  //Timer1 is ON clock = CLK/8 = 16/8 MHz = 2MHz = .5 mircosecond
}

void loop() {
  digitalWrite(13,HIGH);
  timeDelay();
  digitalWrite(13,LOW);
  timeDelay();
}
void timeDelay()
{
  for(int i = 0;i<100;i++)
  {
    timeTick10ms();
  }
}

void timeTick10ms()
{
 TCNT1 = 45536; //Set preset value (65536-20000) = 45536
 while(bitRead(TIFR1,0)!=HIGH) //Check TOV1
 {
  ;
 }
 TIFR1 = 0x01; //Reset TOV1
 TCNT1 = 45536; //Reset Preset Value
}
