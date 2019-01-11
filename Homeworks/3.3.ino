void setup()
{
    pinMode(8,OUTPUT);
    for(int i=0;i<3;i++)
    {
        digitalWrite(8,HIGH);
        delay(2000);
        digitalWrite(8,LOW);
        delay(2000);
    }
    
}

void loop()
{
    
}