const int trigPin = D5;
const int echoPin = D6;
const int buzzer = D2;

long duration;
double distance;

void setup() {
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;

  if(distance < 25){
    tone(buzzer, 1000);
    delay(50);

    noTone(buzzer);
    delay(50);
  }else{
    noTone(buzzer);
  }

  delay(100);
}
