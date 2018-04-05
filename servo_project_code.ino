#include <Servo.h>
Servo myservo;
void setup() {
  // put your setup code here, to run once:
  myservo.attach(8);

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i =0;i<180;i+=10)
  {
    myservo.write(i);
    //here we will call fn of the ultrasonic sensor if returns low will avoiding the things , and turn to the empty area...  

   }
   myservo.write(90); //here it returns to the initial position .....
   

}
