#inclued <SimpleDHT.h>
const int dht_pin = D7;
SimpleDHT11 dht11;

void setup() {
  Serial.begin(115200);
}

void loop() {
  byte temperature = 0;
  byte humidity = 0;

  dht11.read(dht_pin, &temerature, &humidity, NULL);

  Serial.print("Temperature : "); Serial.print(temerature); Serial.println(" *C");
  Serial.print("Humidity : ");    Serial.print(humidity);   Serial.println(" H");
  Serial.println();

  delay(2000);
}
