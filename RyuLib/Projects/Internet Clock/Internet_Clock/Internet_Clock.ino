#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <TM1637Display.h>
#include <DS1302.h>

const int MAX_CONNECT_TIME = 300;
const int QUERY_INTERVAL = 3000;

// TODO: change xxxx with your AP information
const char* ssid = "xxxx";
const char* password = "xxxx";

const char* host = "www.timeapi.org";
const int httpsPort = 80;
const String url = "/utc/now";

// TM1637 LED tube pin
const int led_clk_pin = 2;
const int led_io_pin  = 4;

// Realtime Clock pin
const int rt_ce_pin  = 14; 
const int rt_io_pin  = 12; 
const int rt_clk_pin = 13; 

TM1637Display display(led_clk_pin, led_io_pin);
DS1302 rtc(rt_ce_pin, rt_io_pin, rt_clk_pin);

void setup() {
  Serial.begin(9600);

  display.setBrightness(0x0f);

  rtc.writeProtect(false);
  rtc.halt(false);

  Serial.print("connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
}

int tick_count = 0;
bool display_dots = false;
void displayTime() 
{
  uint8_t data[] = { 0b00000000, 0b00000000, 0b00000000, 0b00000000 };

  Time t = rtc.time();

  int hr_lo = t.hr % 10;
  int hr_hi = (t.hr - hr_lo) / 10;

  if (hr_hi < 1) data[0] = display.encodeDigit(0);
  else data[0] = display.encodeDigit(hr_hi);

  if (hr_lo < 1) data[1] = display.encodeDigit(0);
  else data[1] = display.encodeDigit(hr_lo);
  
  int min_lo = t.min % 10;
  int min_hi = (t.min - min_lo) / 10;

  if (min_hi < 1) data[2] = display.encodeDigit(0);
  else data[2] = display.encodeDigit(min_hi);

  if (min_lo < 1) data[3] = display.encodeDigit(0);
  else data[3] = display.encodeDigit(min_lo);

  tick_count++;
  if (tick_count >= 5) {
      tick_count = 0;
      display_dots = ! display_dots;
      if (display_dots) data[1] = data[1] | 0b10000000;
  }
  
  display.setSegments(data);
}

int time_out = 0;
int query_count = 9999;

void loop() {
  displayTime();
  
  time_out++;
  if (WiFi.status() != WL_CONNECTED) {
    if (time_out > MAX_CONNECT_TIME) {
      time_out = 0;
      
//      Serial.print("connecting to ");
//      Serial.println(ssid);
//      WiFi.begin(ssid, password);
    }
    
    Serial.println("WiFi is not ready.");
    delay(100);
    return;
  }

  time_out = 0;

  query_count++;
  delay(100);

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
  if (client.connected()) {
    String line = client.readStringUntil('\n');

    // Korean local time need to add 9 hours.
    String hour = line.substring(11,13);
    String minute = line.substring(14,16);
    String second = line.substring(17,19);
    
    Time t(2016, 1, 1, (hour.toInt() + 9) % 24, minute.toInt(), second.toInt(), Time::kSunday);
    rtc.time(t);
  }
}
