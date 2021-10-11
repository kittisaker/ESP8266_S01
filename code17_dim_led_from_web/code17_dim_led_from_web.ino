#include <ESP8266WebServer.h>
const char* ssid = "DEVIL_KOPE";
const char* password = "0940799451";
ESP8266WebServer server(80);
const int LED = D6;
String page =
R"(
  <html lang="en">
    <head>
        <title>Dim an LED</title>
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <!-- <link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.1.0/css/all.css"> -->
        <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.1.2/css/bootstrap.min.css">
    </head>
    <body>
        <div class="container-fluid text-center">
            <div class="row">
                <div class="col-sm-12" style="color: red; font-size: 7vh;">
                    <p>Use the slider to control the brightness.</p>
                </div>
            </div>
            <br>
            <div class="col-sm-12">
                <input type="range" min="0" max="100" class="form-control-range" id="slider">
            </div>
            <br>
            <div class="row">
                <div class="col-sm-12">
                    <h3 id="status"></h3>
                </div>
            </div>
        </div>

        <script>
            $('#slider').on('change', function(){
                var state_slider = $('#slider').val();
                $('#status').html('Brightness: ' +state_slider + ' %');
                $.ajax({
                    url: '/',
                    type: 'POST',
                    data: {state: state_slider}
                });
            });
        </script>
    </body>
</html>
)";

void htmlIndex(){
  int value = server.arg("state").toInt();
  value = map(value, 0, 100, 0, 1023);

  if(value == 0){
    digitalWrite(LED, LOW);
  }else{
    analogWrite(LED, value);
  }
  
  String contentType = "text/html";
  String message = page;
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
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
  delay(1000);
  connectToWiFi();
  setupServer();
}

void loop() {
  server.handleClient();
}
