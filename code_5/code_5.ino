int motorPin1=10;
int motorPin2=9;
void setup() {
  // put your setup code here, to run once:
pinMode(motorPin1,OUTPUT);
pinMode(motorPin2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(motorPin1,HIGH);
digitalWrite(motorPin2,LOW);
}
