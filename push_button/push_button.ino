void setup() {
  // put your setup code here, to run once:
pinMode(12,INPUT);
pinMode(9,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int value = digitalRead(12);
digitalWrite(9,value);
}
