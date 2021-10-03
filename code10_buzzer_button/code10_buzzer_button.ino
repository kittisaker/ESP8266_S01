const int button = D1;
const int buzzer = D6;

void setup() {
  pinMode(button, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  if(digitalRead(button) == 0){
    tone(buzzer, 1000)
  }

  while(digitalRead(button) == 0){
    yield();
  }

  noTone(buzzer);
  delay(100);
}
