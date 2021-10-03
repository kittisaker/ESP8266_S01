const int button_down = D1;
const int button_up = D2;
const int led = D7;
int container = 0;

void setup() {
  pinMode(button_down, INPUT_PULLUP);
  pinMode(button_up, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop() {
  
  while(digitalRead(button_down) == 0){
    if(container > 50){
      container = container - 50;
    }else{
      container = 0;
    }
    analogWrite(led, container);
    delay(50);
  }
  
  while(digitalRead(button_up) == 0){
    if(container < 972){
      container = container + 50;
    }else{
      container = 1023;
    }
    analogWrite(led, container);
    delay(50);
  }
}
