#include <ESP8266WebServer.h>
const char* ssid = "DEVIL_KOPE";
const char* password = "0940799451";
ESP8266WebServer server(80);
const int LED = D6;
String storage = "";
String page =
R"(
  <html lang='en'>
    <head>
        <title>Play with an LED</title>
        <meta name='viewport' content='width=device-width, initial-scale=1'>
        <link rel='stylesheet' href='https://use.fontawesome.com/releases/v5.1.0/css/all.css'/>
        <link rel='stylesheet' href='https://stackpath.bootstrapcdn.com/bootstrap/4.1.2/css/bootstrap.min.css'/>
        <script src='https://code.jquery.com/jquery-3.3.1.min.js'></script>
        <style>
            .css_on 
            {
                color: orange;
            }
            .css_off 
            {
                color: black;
            }
        </style>
    </head>
    <body>
    <div class='container-fluid text-center'>
        <div class='row text-center'>
            <div class='col-sm-12' style='color:red;font-size:7vh'>
                <p>Let's play with a bulb.</p>
            </div>
        </div>
        
        <div class='row'>
            <div  class='col-sm-12'>
                <i id='id_bulb' class='fas fa-lightbulb css_off' style='font-size:25vh'></i>
            </div>
        </div>
            <br>
        <div class='row'>
            <div  class='col-sm-12' style='font-size:7vh'>
                <p>Click the button:</p>
            </div>
        </div>
        
        <div class='row'>
            <div  class='col-sm-12'>
                <input type='button' class='btn btn-primary' id='id_button' value='Off'  style='font-size:7vh'>
            </div>
        </div>
    </div>
    
    <script>
    $(document).ready(function(){
        $('#id_button').click(function(){
            var current_state = $("#id_bulb").hasClass("css_off");
                
            if(current_state == true)
            {
                $.ajax({
                  url:'/led',
                  type: 'POST',
                  data: {state: "On"},
                });
                $("#id_button").val("On");
                $("#id_bulb").removeClass("css_off").addClass("css_on");
            }
            else
            {
                $.ajax({
                  url:'/led',
                  type: 'POST',
                  data: {state: "Off"},
                });
                $("#id_button").val("Off");
                $("#id_bulb").removeClass("css_on").addClass("css_off");
            }
        });
    });
    </script>
    </body>
</html>
)";

void led(){
  storage = server.arg("state");
  if(storage == "On"){
    digitalWrite(LED, HIGH);  
  }else{
    digitalWrite(LED, LOW);
  }
  server.send(200, "text/html", "ok");
}

void htmlIndex(){
  int replyCode = 200;
  String contentType = "text/html";
  String message = page;
  server.send(replyCode, contentType, message);
}

void setupServer(){
  server.on("/", htmlIndex);
  server.on("/led", led);
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
  delay(4000);
}

void loop() {
  server.handleClient();
}
