//connect the negative terminal to a GND pin of the development board, and
//the positive terminal to a digital pin (D6)
const int LED = D6;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  //PWM is generated using 10 bits, so it ranges between 0 and 1023 (2^10 = 1024)
  for(int fade=0; fade<1024; fade++){
    analogWrite(LED, fade);
    delay(2);
  }
  delay(500);

  for (int fade=1023; fade>=0; fade--){
    analogWrite(LED, fade);
    delay(2);
  }
  delay(500);
}
