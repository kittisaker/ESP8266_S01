const int buzzer = D6;

void setup() {
  pinMode(buzzer, OUTPUT);
}

void loop() {
  tone(buzzer, 1000);
  delay(1000);

  noTone(buzzer);
  delay(1000);

  tone(buzzer, 50);
  delay(1000);

  noTone(buzzer);
  delay(1000);
}
