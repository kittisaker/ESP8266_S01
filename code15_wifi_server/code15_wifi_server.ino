#include <ESP8266WebServer.h>
const char* ssid = "DEVIL_KOPE";
const char* password = "0940799451";
ESP8266WebServer server(80);

void htmlIndex(){
  int replyCode = 200;
  String contentType = "text/plain";
  String message = "Hello word!";
  server.send(replyCode, contentType, message);
}

void setupServer(){
  server.on("/", htmlIndex);
  server.begin();
  Serial.println("HTTP server started");
}

void connectToWiFi(){
  Serial.println("Connecting to the WiFi");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("Waiting for connection");
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");  Serial.println(ssid);
  Serial.print("IP address : ");  Serial.println(WiFi.localIP());
}

void setup() {
  Serial.begin(115200);
  delay(1000);
  connectToWiFi();
  setupServer();
}

void loop() {
  server.handleClient();
}
