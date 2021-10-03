const int trigPin = D3;
const int echoPin = D5;
const int red = D6;
const int green = D7;
const int blue = D8;

long duration;
double distance;

void setup() {
  Serial.begin(115200);
  Serial.println("The board has started");

  pinMode(trigPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
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

  if(distance < 25){
    digitalWrite(red, HIGH);
    delay(35);
    digitalWrite(red, LOW);
    delay(35);
  }else{
    digitalWrite(green, HIGH);
    delay(300);
    digitalWrite(green, LOW);
    delay(200);
  }
}
