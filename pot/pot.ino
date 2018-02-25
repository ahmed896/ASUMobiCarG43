void setup()
{  
  pinMode(13,OUTPUT);
}
void loop()
{   
  int ledDelay = analogRead(A0);
    digitalWrite(13,HIGH);
    delay(ledDelay);
    digitalWrite(13,LOW);
    delay(ledDelay);  
}

