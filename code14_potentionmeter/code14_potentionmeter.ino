#inclued <Servo.h>
Servo servo;

void setup() {
  Serial.begin(115200);
  servo.attach(D1);
}

void loop() {
  int value = analogRead(A0);
  value = map(value, 0, 1024, 0, 180);
  servo.write(value);

  Serial.print("Angle : "); Serial.println(value);
  delay(50);
}
