//This is the complete code of the project. Here I used 3 LEDS and microcontroller board NodeMCU esp8266 with pin no. 5, 6, and 7
//Created by Prince Kumar Kushwaha
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>

#define LED1 6
#define LED2 7
#define LED3 8

char webpage[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<body>
    <center>
        <h1> <u>Home Automation using NodeMCU </u></h1>
        <br>
        <h2> <u> Design by Prince Kumar Kushwaha </u></h2>
        <h3>LED 1</h3>
        <b>
            <button onclick="window.location = 'http://'+location.hostname+'/led1/on'">ON</button>
            <button onclick="window.location = 'http://'+location.hostname+'/led1/off'">OFF</button>
        </b>

        <h3>LED 2</h3>
        <b>
            <button onclick="window.location = 'http://'+location.hostname+'/led2/on'">ON</button>
            <button onclick="window.location = 'http://'+location.hostname+'/led2/off'">OFF</button>
        </b>

        <h3>LED 3</h3>
        <b>
            <button onclick="window.location = 'http://'+location.hostname+'/led3/on'">ON</button>
            <button onclick="window.location = 'http://'+location.hostname+'/led3/off'">OFF</button>
        </b>
    </center>
</body>
</html>
)=====";

#include <ESPAsyncWebServer.h>

AsyncWebServer server(80); // server port 80

void notFound(AsyncWebServerRequest *request)
{
  request->send(404, "text/plain", "Page Not found");
}

void setup(void)
{
  
  Serial.begin(115200);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  
  WiFi.softAP("KEC", "kec@12345");
  Serial.println("softap");
  Serial.println("");
  Serial.println(WiFi.softAPIP());


  if (MDNS.begin("ESP")) { //esp.local/
    Serial.println("MDNS responder started");
  }



  server.on("/", [](AsyncWebServerRequest * request)
  { 
   
  request->send_P(200, "text/html", webpage);
  });

//to trun on the LED1
   server.on("/led1/on", HTTP_GET, [](AsyncWebServerRequest * request)
  { 
    digitalWrite(LED1,HIGH);
  request->send_P(200, "text/html", webpage);
  });
//to turn of the LED1
  server.on("/led1/on", HTTP_GET, [](AsyncWebServerRequest * request)
  { 
    digitalWrite(LED1,LOW);
  request->send_P(200, "text/html", webpage);
  });


//to trun on the LED2
   server.on("/led1/on", HTTP_GET, [](AsyncWebServerRequest * request)
  { 
    digitalWrite(LED2,HIGH);
  request->send_P(200, "text/html", webpage);
  });
//to turn of the LED2
  server.on("/led2/on", HTTP_GET, [](AsyncWebServerRequest * request)
  { 
    digitalWrite(LED2,LOW);
  request->send_P(200, "text/html", webpage);
  });

  //to trun on the LED3
   server.on("/led3/on", HTTP_GET, [](AsyncWebServerRequest * request)
  { 
    digitalWrite(LED3,HIGH);
  request->send_P(200, "text/html", webpage);
  });
//to turn of the LED3
  server.on("/led3/on", HTTP_GET, [](AsyncWebServerRequest * request)
  { 
    digitalWrite(LED3,LOW);
  request->send_P(200, "text/html", webpage);
  });

  server.onNotFound(notFound);

  server.begin();  // it will start webserver
}


void loop(void)
{
}
