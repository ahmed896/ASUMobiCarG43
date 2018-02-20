int led1 =4,led2 =5,led3 =6,led4 =7;
void setup () {
  pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(led4,OUTPUT);}
  void loop () {
    for (int i=4;i<8;i++){
   digitalWrite(i, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(i, LOW);    // turn the LED off by making the voltage LOW
      delay(1000);             }          // wait for a second
}
