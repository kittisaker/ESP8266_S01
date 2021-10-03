const int motorspeed_pin = D5;
const int DIRA = 6;
const int DIRB = 7;

const int delayThreeseconds = 3000;
const int delayOnedotfiveseconds = 1500;

void setup() {
  pinMode(motorspeed_pin, OUTPUT);
  pinMode(DIRA, OUTPUT);
  pinMode(DIRB, OUTPUT);
}

void turnOff(){
  digitalWrite(motorspeed_pin, LOW);
  digitalWrite(DIRA, LOW);
  digitalWrite(DIRB, LOW);
  delay(delayOnedotfiveseconds);
}

void loop() {
  
  digitalWrite(motorspeed_pin, HIGH);
  digitalWrite(DIRA, HIGH);
  digitalWrite(DIRB, LOW);
  delay(delayThreeseconds);

  turnOff();

  digitalWrite(motorspeed_pin, HIGH);
  digitalWrite(DIRA, LOW);
  digitalWrite(DIRB, HIGH);
  delay(delayThreeseconds);

  turnOff();

  analogWrite(motorspeed_pin, 512);
  digitalWrite(DIRA, HIGH);
  digitalWrite(DIRB, LOW);
  delay(delayThreeseconds);

  turnOff();

  analogWrite(motorspeed_pin, 512);
  digitalWrite(DIRA, LOW);
  digitalWrite(DIRB, HIGH);
  delay(delayThreeseconds);

  turnOff();
}
