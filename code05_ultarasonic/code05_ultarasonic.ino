const int trigPin = D3;
const int echoPin = D5;

long duration;
double distance;

void setup() {
  Serial.begin(115200);
  Serial.println("The board has started");

  pinMode(trigPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;

  Serial.print("Distance : ");  Serial.print(distance);  Serial.print(" cm");  
}
