void setup()
{
    pinMode(8,OUTPUT);
    int i = 0;
    while(i<3)
    {
        digitalWrite(8,HIGH);
        delay(2000);
        digitalWrite(8,LOW);
        delay(2000);
        i++;
    }
    
}

void loop()
{
    
}