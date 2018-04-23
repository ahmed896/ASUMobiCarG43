byte motor1 = 3, motor2 = 5, motor3 = 6, motor4 =9 , echo = 10 , trig = 11 ,x=0,RS=7, LS=2, MS =4, left = 0, right = 0 , med = 0,pr=1,pl=1,pm=1;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(motor1,OUTPUT);
pinMode(motor2,OUTPUT);
pinMode(motor3,OUTPUT);
pinMode(motor4,OUTPUT);
pinMode(RS,INPUT) ;
pinMode(LS,INPUT) ;
pinMode(MS,INPUT) ;
}
void forward ()
{
    digitalWrite(motor1,LOW);
    analogWrite(motor2,100);
    digitalWrite(motor3,LOW);
    analogWrite(motor4,100);
}
void turnLeft ()
{
    digitalWrite(motor1,LOW);
    analogWrite(motor2,200);
    digitalWrite(motor3,LOW);
    digitalWrite(motor4,LOW);
}
void turnRight ()
{
    digitalWrite(motor1,LOW);
    digitalWrite(motor2,LOW);
    digitalWrite(motor3,LOW);
    analogWrite(motor4,200);
}
void turnLeftSmooth ()
{
    digitalWrite(motor1,LOW);
    analogWrite(motor2,75);
    analogWrite(motor3,0);
    analogWrite(motor4,150);
}
void turnRightSmooth ()
{
    analogWrite(motor1,0);
    analogWrite(motor2,150);
    analogWrite(motor3,0);
    analogWrite(motor4,75);
}
void Stop ()
{
    digitalWrite(motor1,LOW);
    analogWrite(motor2,0);
    digitalWrite(motor3,LOW);
    analogWrite(motor4,0);
}
void wait()
{
  turnRight();
}
void loop() {
  // put your main code here, to run repeatedly:
  left = digitalRead(LS);
  right = digitalRead(RS);
  med = digitalRead(MS);
  if ( (med == 0 ) && (left == 1) && (right == 1))
  forward();
  if ( (med == 0) && (left == 0) && (right == 1))
  turnLeftSmooth();
  if ( (med == 0 ) && (left == 1) && (right == 0))
  turnRightSmooth();
  if ( (med == 1) && (right == 1) && (left == 0))
  turnRight();
  if ( (med == 1) && (right == 0) && (left == 1))
  turnLeft();
  if ( (med == 1) && ( right == 1) && (left == 1))
  {
    // wait();
    Stop(); 
  }
}
