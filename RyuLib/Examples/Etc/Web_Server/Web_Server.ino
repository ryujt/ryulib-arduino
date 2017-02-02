#include <wifi_tools.h>


// 자신의 WIFI(공유기)의 SSID와 비번을 입력하세요
WiFiConnector connector("xxxx", "xxxx");
WiFiServer server(80);


void setup() {
  Serial.begin(9600); 
  
  connector.connect();
  server.begin();
}

void loop() {
  connector.connect();

  WiFiClient client = server.available();
  if (!client) return;
  
  Serial.println("new client");

  String line = client.readStringUntil('\n');
  Serial.println(line);
    
  // send a standard http response header
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("Connection: close"); 
  client.println();
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  
  // output the value of each analog input pin
  for (int analogChannel = 0; analogChannel < 6; analogChannel++) {
    int sensorReading = analogRead(analogChannel);
    client.print("analog input ");
    client.print(analogChannel);
    client.print(" is ");
    client.print(sensorReading);
    client.println("<br />");       
  }
  
  client.println("</html>");
      
  client.stop();
}

