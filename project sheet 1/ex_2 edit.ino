void setup() {
pinMode (0,OUTPUT);
pinMode (1,OUTPUT);
pinMode (2,OUTPUT);
pinMode (3,OUTPUT);
}

void loop() {
for(int i=0;i<=3;i++)
{
  digitalWrite(i,HIGH);
  delay(1000);
  digitalWrite(i,LOW);
  if (i==3)
  {
    for (int i=2;i>=1;i--)
    {
      digitalWrite(i,HIGH);
      delay(1000);
      digitalWrite(i,LOW);
    }
  }
}
}
