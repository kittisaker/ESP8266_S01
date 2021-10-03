//connect the negative terminal to a GND pin of the development board, and
//the positive terminal to a digital pin (D6)
const int LED = D6;
const int delayOneSecond = 1000;
void setup() {
  pinMode(LED, OUTPUT);  
}

void loop() {
//  turn off-on the LED and wait for 1 second
  digitalWrite(LED, LOW);
  delay(delayOneSecond);
  digitalWrite(LED, HIGH);
  delay(delayOneSecond);
}
