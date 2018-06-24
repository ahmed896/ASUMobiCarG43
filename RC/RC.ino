byte motor1 = 3, motor2 = 5, motor3 = 6, motor4 =9 , echo = 10 , trig = 11 ,x=0,RS=7, LS=2, MS =4, left = 0, right = 0 , med = 0,pr=1,pl=1,pm=1;
float take =0 ,give = 0 ;
char state , current ; 
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(motor1,OUTPUT);
pinMode(motor2,OUTPUT);
pinMode(motor3,OUTPUT);
pinMode(motor4,OUTPUT);
pinMode(echo,INPUT);
pinMode(RS,INPUT) ;
pinMode(LS,INPUT) ;
pinMode(MS,INPUT) ;
pinMode(trig,OUTPUT);
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
    analogWrite(motor1,0);
    analogWrite(motor2,200);
    analogWrite(motor3,200);
    digitalWrite(motor4,0);
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
    analogWrite(motor1,150);
    analogWrite(motor2,0);
    analogWrite(motor3,75);
    analogWrite(motor4,0);
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
void back()
{
  digitalWrite(motor2,LOW);
    analogWrite(motor1,100);
    digitalWrite(motor4,LOW);
    analogWrite(motor3,100);
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
    digitalWrite(motor1,LOW);
    digitalWrite(motor2,HIGH);
    digitalWrite(motor3,LOW);
    digitalWrite(motor4,HIGH);
    delay(200);
    digitalWrite(motor1,HIGH);
    digitalWrite(motor2,LOW);
    digitalWrite(motor3,LOW);
    digitalWrite(motor4,HIGH);
    delay(500);
    x=1;
  }
  else
  {
    if(x==1)
    {
    digitalWrite(motor1,HIGH);
    digitalWrite(motor2,LOW);
    digitalWrite(motor3,HIGH);
    digitalWrite(motor4,LOW);
   }
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
  if (state == 'W')
  goto  AA;
}
  if (state == 'Z') // dh character morsy w islam hy3mloh 34an a5o4 f l accurate mode
  goto BB;
}
AA :
 left = digitalRead(LS);
  right = digitalRead(RS);
  med = digitalRead(MS);
  if ( (med == 0 ) && (left == 1) && (right == 1))
  forward();
  if ( (med == 0) && (left == 0) && (right == 1))
  turnRightSmooth();
  if ( (med == 0 ) && (left == 1) && (right == 0))
  turnLeftSmooth();
  if ( (med == 1) && (right == 1) && (left == 0))
  {
    while (1)
    {
  turnLeft();
  if ( (digitalRead(MS) == 0) || (digitalRead(RS) == 0 ))
  break;
    }
  }
  if ( (med == 1) && (right == 0) && (left == 1))
  {
    while (1)
    {
  turnRight();
  if ( (digitalRead(MS) == 0) || (digitalRead(LS) == 0))
  break;
  }
  }
  if ( (med == 1) && ( right == 1) && (left == 1))
  {
    wait();
   // Stop(); 
  }
  //       here will be the features of accurate movement code
  BB :
  while (Serial.available())
  {
    float timer = 0;
    current = Serial.read();
    int distance = Serial.read(); // hena h5zn l distance 
    if (current == 'z') // dh l character ly hygyly wly 
    {
      while (1)
      {
      timer = millis();
      forward();
       if (( 100 * timer ) <= 550 ) // l mfrod a3ml relation ben l sor3a wl time 34an azbt l distance
     {  Stop(); break;}
      }
   }
  else if (current == 'y') // dh l char ly morsy we eslam hyb3toh
   {
    while (1)
    {
    timer = millis();
    back();
    if ((100 * timer ) <= 550 ) // l mfrod a3ml relation ben l sor3a wl time 34an azbt l distance
    {
    Stop();break;
    }
    }
   }
  }
} 
