/* Question
The text "AUST" will move from Left-to-Right and Right-to-Left.
When char "A" is at an even position in Line-1: LED-1 will TURN ON, LED-2 will TURN OFF and "CONV" will display at line-2 on position-6. And,
when char "A" is at an odd position in Line-1: LED-1 will TURN OFF, LED-2 will TURN ON and "CONV" will not display.
*/

#include<Wire.h>
#include<LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2);

void setup() {
  pinMode(8,OUTPUT);  // Used as LED 1. Connect LED-1 with DPin 8.
  pinMode(9,OUTPUT);  // Used as LED 2. Connect LED-2 with DPin 9.
}

void loop() {
  // put your main code here, to run repeatedly:
  
  for (int i=0;i<12;i++)
  {
    AUST(i);  // Called the user defined function
  }
  for (int i=12;i>=0;i--)
  {
    AUST(i);
  }
}

/* An User Defined function to write TEXT on LCD and TURN ON and OFF the LED's simultaneously */

void AUST(int position)
{
    lcd.init();   // Initialize the LCD 
    lcd.backlight();    // Turn on Backlight of LCD Panel
    lcd.setCursor(position,0);   // Set cursor using loop on Line - 1
    lcd.print("AUST");
    if(position%2==0)    // Checking position (Even or Odd)
    {
      digitalWrite(8,HIGH);
      digitalWrite(9,LOW);  
      lcd.setCursor(6,1);
      lcd.print("CONV");
    } else {
      digitalWrite(8,LOW);
      digitalWrite(9,HIGH);  
    }
}
