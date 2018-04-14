byte motor1 = 3, motor2 = 5, motor3 = 6, motor4 =9 , echo = 10 , trig = 11;
float take =0 ,give = 0 ;
char state; 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
pinMode(motor1,OUTPUT);
pinMode(motor2,OUTPUT);
pinMode(motor3,OUTPUT);
pinMode(motor4,OUTPUT);
pinMode(echo,INPUT);
pinMode(trig,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig, HIGH);
  delayMicroseconds(100);
  digitalWrite(trig, LOW);
  take = pulseIn(echo, HIGH);
  give = (take * .034) / 2;
  if(give<=20)
  {
    digitalWrite(motor1,LOW);
    digitalWrite(motor2,LOW);
    digitalWrite(motor3,LOW);
    digitalWrite(motor4,LOW); 
    delay(1000);
     digitalWrite(motor1,HIGH);
    digitalWrite(motor2,LOW);
    digitalWrite(motor3,LOW);
    digitalWrite(motor4,LOW);
    delay(1000);
    
  }
  else
  {
while(Serial.available())
{
  state = Serial.read();
  Serial.println(state);
  if (state == 'F')
  {
    digitalWrite(motor1,HIGH);
    digitalWrite(motor2,LOW);
    digitalWrite(motor3,HIGH);
    digitalWrite(motor4,LOW);
  }
  if (state == 'B')  // move back
  {
    digitalWrite(motor1,LOW);
    digitalWrite(motor2,HIGH);
    digitalWrite(motor3,LOW);
    digitalWrite(motor4,HIGH);
  }
  if (state == 'L') // move left
  {
    digitalWrite(motor1,HIGH);
    digitalWrite(motor2,LOW);
    digitalWrite(motor3,LOW);
    digitalWrite(motor4,LOW);
  }
  if (state == 'R') // move right
  {
    digitalWrite(motor1,LOW);
    digitalWrite(motor2,LOW);
    digitalWrite(motor3,HIGH);
    digitalWrite(motor4,LOW);
  }
}
}
}
else if(buttom==HIGH)
 {
   analogWrite(motor1r,0);analogWrite(motor1l,255);analogWrite(motor2r,0);analogWrite(motor2l,255);
 }
else if(right==HIGH)
{
   analogWrite(motor1r,0);analogWrite(motor1l,300);analogWrite(motor2r,300);analogWrite(motor2l,0);
 }
else if(left==HIGH)
 {
   analogWrite(motor1r,300);analogWrite(motor1l,0);analogWrite(motor2r,0);analogWrite(motor2l,100);
 }
 else 
  {
    analogWrite(motor1r,0);analogWrite(motor1l,0);analogWrite(motor2r,0);analogWrite(motor2l,0);
  }



  
  
  // put your main code here, to run repeatedly:

} 

