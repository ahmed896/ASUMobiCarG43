void setup() {
  byte motor1 = 3, motor2 = 5, motor3 = 6, motor4 =9;
pinMode(motor1,OUTPUT);
pinMode(motor2,OUTPUT);
pinMode(motor3,OUTPUT);
pinMode(motor4,OUTPUT);
}
void circle(motor1,motor2,motor3,motor4){
  analogWrite(motor1,150);
  analogWrite(motor2,150);
  analogWrite(motor3,100);
  analogWrite(motor4,100);
  //this values change to get the redious required which is equal to 1 m 
  }

void loop() {
  circle(motor1,motor2,motor3,motor4);
 
}
