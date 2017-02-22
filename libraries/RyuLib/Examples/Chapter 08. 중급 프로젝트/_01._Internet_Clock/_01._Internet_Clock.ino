#include <wifi_tools.h>
#include <http_tools.h>
#include <TM1637Display.h>
#include <Clock.h>
#include <Interval.h>

// 자신의 WIFI(공유기)의 SSID와 비번을 입력하세요
WiFiConnector connector("xxxx", "xxxx");
HttpGet http; 
TM1637Display display(2, 4);
Clock clock(14, 12, 13);

// 하루 동안의 간격마다 실행
Interval interval(24 * 60 * 60 * 1000);

bool is_first_time = true;

void setup() {
  Serial.begin(9600);

  display.setBrightness(15);
}

void get_time_from_interner() {
  if (is_first_time || interval.onTime()) {
    is_first_time = false;
    http.get("www.ddottan.com", 80, "/api/time"); 
  }

  while (http.available()) {
    String line = http.readln();
    if (line.substring(0, 4) != "TIME") continue;

    Serial.println(line);
    
    String hour   = line.substring(5,  7);
    String minute = line.substring(8, 10);
    String second = line.substring(11,13);
    
    Serial.print(hour);  Serial.print(":");
    Serial.print(minute);  Serial.print(":");
    Serial.println(second);

    clock.set(hour.toInt(), minute.toInt(), second.toInt());
  }
}

void loop() {
  uint8_t data[] = { 0b00000000, 0b00000000, 0b00000000, 0b00000000 };
  clock.setSegments(data);
  display.setSegments(data);
  
  connector.connect();

  get_time_from_interner();
  
  delay(10);
}
