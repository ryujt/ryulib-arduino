#include <wifi_tools.h>
#include <http_tools.h>

#include "Options.h"
#include "ControlServer.h"
#include "PatternServer.h"
#include "ServoControl.h"
#include "SoundControl.h"
#include "LaserControl.h"

WiFiConnector connector;

Options options;
ControlServer controlServer;
PatternServer patternServer;
ServoControl servos(4, 5);
SoundControl sound(12);
LaserControl laser(16);

void setup() {
  Serial.begin(115200); 

  // 고정 IP를 사용하고 싶을 때 사용하세요.
//  IPAddress ip(192, 168, 1, 100); 
//  IPAddress dns(192, 168, 1, 1); 
//  IPAddress gateway(192, 168, 1, 1); 
//  WiFi.config(ip, dns, gateway);

  options.load_from_file();

  controlServer.begin();
  patternServer.begin();
}

// 웹 서비스로 Local IP를 저장해서 확인 할 수 있도록 한다.
void sendLocalIP()
{
  Serial.print("Local IP: ");
  Serial.println(WiFi.localIP());
  
  HttpGet http; 
  http.get("www.awesomeit.kr", 80, "/api/set_user_ip?rid=" + options.get_key() + "&local_ip=" + WiFi.localIP().toString()); 
  while (http.available()) {
    String line = http.readln();
    Serial.println(line);
  }

  sound.execute('1');
}

void loop() {
  if (connector.onConnected()) {
    sendLocalIP();
  }

  connector.connect(options.get_ssid(), options.get_password());

  char command = controlServer.getCommand();
  servos.execute(command);
  sound.execute(command);
  laser.execute(command);

  while (Serial.available()) {
    String line = Serial.readStringUntil('\n');
    if (line.substring(0, 1).equals("K")) options.set_key(line.substring(1, line.length()-1));
    if (line.substring(0, 1).equals("I")) options.set_ssid(line.substring(1, line.length()-1));
    if (line.substring(0, 1).equals("P")) options.set_password(line.substring(1, line.length()-1));
    if (line.substring(0, 1).equals("S")) options.save_to_file();
  }

  patternServer.execute();

  if (patternServer.get_position()) servos.gotoXY(patternServer.get_x(), patternServer.get_y());
}

