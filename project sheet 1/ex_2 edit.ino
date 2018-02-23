int i;
void setup() {
pinMode (0,OUTPUT);
pinMode (1,OUTPUT);
pinMode (2,OUTPUT);
pinMode (3,OUTPUT);
}

void loop() {
for(i=0;i<=3;i++)
{
  digitalWrite(i,HIGH);
  delay(1000);
  digitalWrite(i,LOW);
}
for (i=2;i>=1;i--)
{
  digitalWrite(i,HIGH);
  delay(1000);
  digitalWrite(i,LOW);
}
}
