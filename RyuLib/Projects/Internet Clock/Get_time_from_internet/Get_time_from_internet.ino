#include <ESP8266WiFi.h>
#include <WiFiClient.h>

const int MAX_CONNECT_TIME = 30;
const int QUERY_INTERVAL = 30;

// TODO: change xxxx with your AP information
const char* ssid = "xxxx";
const char* password = "xxxx";

const char* host = "www.timeapi.org";
const int httpsPort = 80;
const String url = "/utc/now";

void setup() {
  Serial.begin(9600);

  Serial.print("connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
}

int time_out = 0;
int query_count = 9999;

void loop() {
  time_out++;
  if (WiFi.status() != WL_CONNECTED) {
    if (time_out > MAX_CONNECT_TIME) {
      time_out = 0;
      
//      Serial.print("connecting to ");
//      Serial.println(ssid);
//      WiFi.begin(ssid, password);
    }
    
    Serial.println("WiFi is not ready.");
    delay(1000);
    return;
  }

  time_out = 0;

  query_count++;
  delay(1000);
  
  if (query_count < QUERY_INTERVAL) return;

  query_count = 0;

//  Serial.println("");
//  Serial.println("WiFi connected.");
//  Serial.println("IP address: ");
//  Serial.println(WiFi.localIP());

  WiFiClient client;
//  Serial.print("connecting to ");
  Serial.println(host);
  if (!client.connect(host, httpsPort)) {
    Serial.println("connection failed.");
    delay(1000);
    return;
  }

  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "User-Agent: BuildFailureDetectorESP8266\r\n" +
               "Connection: close\r\n\r\n");

  // Read Header
  while (client.connected()) {
    String line = client.readStringUntil('\n');
    if (line == "\r") break;
  }
  
  // Read Body
  while (client.connected()) {
    String line = client.readStringUntil('\n');
    Serial.println(line);
    
    // Korean local time need to add 9 hours.
    String hour = line.substring(11,13);
    Serial.println((hour.toInt() + 9) % 24);
    
    String minute = line.substring(14,16);
    Serial.println(minute);
    
    String second = line.substring(17,19);
    Serial.println(second);
  }
}
