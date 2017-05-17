#include <wifi_tools.h>
#include <http_tools.h>
#include "Database.h"
#include "ControlServer.h"
#include "ServoControl.h"
#include "SoundControl.h"
#include "LaserControl.h"

// Key는 http://www.awesomeit.kr/cat_laser 에서 생성하시면 됩니다.
String key = "GewvSx6z78nNbABVqkPLXom9rfMdgJji";

// 공유기의 id와 암호를 입력하시기 바랍니다.
char *ssid = "U+NetA108";
char *password = "DD6E018473";

Database database;
WiFiConnector connector(ssid, password);
ControlServer controlServer;
ServoControl servos(4, 5);
SoundControl sound(12);
LaserControl laser(16);

void setup() {
  Serial.begin(115200); 

  connector.connect();
  controlServer.begin();
}

// 웹 서비스로 Local IP를 저장해서 확인 할 수 있도록 한다.
void sendLocalIP()
{
  Serial.print("Local IP: ");
  Serial.println(WiFi.localIP());

  HttpGet http; 
  http.get("www.awesomeit.kr", 80, "/api/set_user_ip?rid=" + key + "&local_ip=" + WiFi.localIP().toString()); 
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

  connector.connect();

  database.execute();

  char command = controlServer.getCommand();

  while (Serial.available()) {
    String line = Serial.readStringUntil('\n');  
    servos.execute(line);
  }

  servos.execute(command);
  sound.execute(command);
  laser.execute(command);
}

