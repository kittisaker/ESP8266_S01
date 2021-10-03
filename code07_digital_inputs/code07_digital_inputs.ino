const int buttonON = D1;
const int buttonOFF = D2;
const int led = D7;

void setup() {
  pinMode(buttonON, INPUT_PULLUP);
  pinMode(buttonOFF, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop() {
  
  if(digitalRead(buttonON) == 0){
    digitalWrite(led, HIGH);
  }
  
  if(digitalRead(buttonOFF) == 0){
    digitalWrite(led, LOW);
  }

  delay(100);
}
