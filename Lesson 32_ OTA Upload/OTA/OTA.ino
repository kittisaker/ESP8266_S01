
#include <ArduinoOTA.h>

const char* ssid = "..............";
const char* password = "..........";

void setup() 
{
  //start the serial communication with the computer at 115200 bits/s
  Serial.begin(115200);

  //print a message into the Serial Monitor
  Serial.println("Booting");
  
  //set the WiFi mode to WiFi_STA.
  //the WiFi_STA means that the board will act as a station,
  //similar to a smartphone or laptop
  WiFi.mode(WIFI_STA);

  //connect to the WiFi network using the ssid and password strings
  WiFi.begin(ssid, password);

  //check if the esp is connected to the network
  //otherwise, restart the board until it finally connects 
  //to the network
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("Connection Failed! Rebooting...");
    delay(5000);
    ESP.restart();
  }

  //initialise the OTA
  ArduinoOTA.begin();

  //display the IP of the board in Serial Monitor
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() 
{
  //listen if there is any available request to upload the code OTA
  ArduinoOTA.handle();
}
