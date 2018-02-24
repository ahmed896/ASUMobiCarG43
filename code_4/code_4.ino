byte pot = A0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  short potReading = analogRead (pot);
  if (potReading <= 250)
  { digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  }
  else if (potReading <= 500 && potReading > 250)
  { digitalWrite(12, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(13, LOW);
    digitalWrite(10, LOW);
  }
  else  if (potReading <= 750 && potReading > 500)
  { digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(13, HIGH);
    digitalWrite(10, LOW);
  }
  else if (potReading >= 750)
  { digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(13, HIGH);
  }

  Serial.print(potReading);
  Serial.println();
  delay(20);

}
