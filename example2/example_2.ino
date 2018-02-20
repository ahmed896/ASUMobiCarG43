int led1 =4,led2 =5,led3 =6,led4 =7;
void setup () {
  pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(led4,OUTPUT);}
  void loop () {
    for (int i=4;i<8;i++){
   digitalWrite(i, HIGH);  
  delay(1000);                      
  digitalWrite(i, LOW);      

      delay(1000);             }      
  }
