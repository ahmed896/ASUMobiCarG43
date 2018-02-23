int x=5;
void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("your number is : ");
  Serial.println(x);
  x++;
 delay(500);
}
