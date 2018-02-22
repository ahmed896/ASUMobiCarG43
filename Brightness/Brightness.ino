const int led=6;
const int potmeter=2;
int pot;
void setup() {
pinMode(led,OUTPUT);
}

void loop() {
 pot=analogRead(potmeter);
 pot=map(pot,0,1023,0,255);
 analogWrite(led,pot);
}
