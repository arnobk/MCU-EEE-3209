byte lupTable[]= {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};

void setup() {
  DDRB = 0xFF;
  DDRD = 0b11000000;
  DDRC = 0x0F;
  
}

void loop() {
  for (int i=0;i<16;i++){
    PORTB = lupTable[i];
    digitalWrite(6,bitRead(lupTable[i],6));
    digitalWrite(7,bitRead(lupTable[i],7));
    PORTC = 0b110000;
    //bitClear(PORTC,i);
    delay(1000);
  }

}
