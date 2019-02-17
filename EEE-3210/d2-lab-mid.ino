#include<Wire.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,16,2);
byte lupTable[]= {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};
void setup() {
  DDRB = 0xFF;
  DDRD = 0b11000000;
  DDRC = 0x0F;

  lcd.init();
  lcd.backlight();

}

void loop() {
  for(int i = 6;i<=9;i++){
    /* 7-seg */
    PORTB = lupTable[10];
    digitalWrite(6,bitRead(lupTable[10],6));
    digitalWrite(7,bitRead(lupTable[10],7));
    PORTC = 0b111111;
    bitClear(PORTC,9-i);

    // LCD
    lcd.setCursor(i,0);
    lcd.print("A");
    
    delay(1000);
    lcd.clear();
  }

    for(int i = 8;i>=7;i--){
    /* 7-seg */
    PORTB = lupTable[10];
    digitalWrite(6,bitRead(lupTable[10],6));
    digitalWrite(7,bitRead(lupTable[10],7));
    PORTC = 0b111111;
    bitClear(PORTC,9-i);

    // LCD
    lcd.setCursor(i,0);
    lcd.print("A");
    
    delay(1000);
    lcd.clear();
  }

}
