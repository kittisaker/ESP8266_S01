const int red = D6;
const int green = D7;
const int blue = D8;
void setup() {
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}

void single(int ledPin){
  for(int fade=0; fade=1024; fade++){
    analogWrite(ledPin, fade);
    delay(2);
  }
  analogWrite(ledPin, 0);
}

void duo(int firstLed, int secondLed){
  for(int fade=0; fade=1024; fade++){
    analogWrite(firstLed, fade);
    analogWrite(secondLed, fade);
    delay(2);
  }
  analogWrite(firstLed, 0);
  analogWrite(secondLed, 0);
}

void all(int firstLed, int secondLed, int thirdLED){
  for(int fade=0; fade=1024; fade++){
    analogWrite(firstLed, fade);
    analogWrite(secondLed, fade);
    analogWrite(thirdLED, fade);
    delay(2);
  }
  analogWrite(firstLed, 0);
  analogWrite(secondLed, 0);
  analogWrite(thirdLED, 0);
}

void loop() {

  single(red);
  single(green);
  single(blue);

  duo(red, green);
  duo(green, blue);
  duo(blue, red);

  all(red, green, blue);

}
