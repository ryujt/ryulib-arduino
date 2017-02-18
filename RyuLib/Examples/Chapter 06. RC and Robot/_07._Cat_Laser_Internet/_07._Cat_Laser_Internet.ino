#include <wifi_tools.h>
#include <http_tools.h>
#include <sound_effect.h>
#include "ServoControl.h"

#define pin_buzzer 12
#define pin_laser  16

WiFiConnector connector("xxxx", "xxxx");
WiFiServer server(80);
ServoControl servos(4, 5);
HttpGet http; 

void setup() {
  Serial.begin(9600); 

  // 고정 IP를 사용하고 싶을 때 사용하세요.
//  IPAddress ip(192, 168, 1, 100); 
//  IPAddress dns(192, 168, 1, 1); 
//  IPAddress gateway(192, 168, 1, 1); 
//  WiFi.config(ip, dns, gateway);
  
  pinMode(pin_buzzer, OUTPUT);
  pinMode(pin_laser , OUTPUT);
  
  connector.connect();
  server.begin();

  servos.setRangeY(0, 50);
}

char getCommand()
{
  WiFiClient client = server.available();
  if (!client) return 0x00;
  
  Serial.println("new client");

  String line = client.readStringUntil('\n');
  Serial.println(line);
  Serial.println(line.substring(5,  6).c_str()[0]);
    
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("Connection: close"); 
  client.println();
  client.println("Ok!");
  
  client.stop();  

  return line.substring(5,  6).c_str()[0];
}

// 웹 서비스로 Local IP를 저장해서 확인 할 수 있도록 한다.
void sendLocalIP()
{
  Serial.print("Local IP: ");
  Serial.println(WiFi.localIP());

  // your_email 부분에 다른 사람과 겹치지 않을 문자열을 넣으시면 됩니다.
  // http://www.awesomeit.kr/memo/get?user_id=your_email 을 하시면 
  // 저장 된 Local IP를 확인 하실 수 있습니다.
  http.get("www.awesomeit.kr", 80, "/memo/add?user_id=your_email&memo=" + WiFi.localIP().toString()); 

  while (http.available()) {
    String line = http.readln();
    Serial.println(line);
  }

  seR2D2(pin_buzzer);
}

void loop() {
  if (connector.onConnected()) sendLocalIP();

  connector.connect();

  switch (getCommand()) {
    case '1': seR2D2(pin_buzzer); break;
    case '2': seLaugh(pin_buzzer); break;
    case '3': seSqueak(pin_buzzer); break;
    case '4': seWaka(pin_buzzer); break;
    case '5': seCatcall(pin_buzzer); break;
    case '6': seChang(pin_buzzer); break;
    case '7': seCoo(pin_buzzer); break;
    case '8': seOh(pin_buzzer); break;
    case '9': seSiren(pin_buzzer); break;
    case '0': seTonarkade(pin_buzzer); break;
    
    case 'B': {
      servos.start();
      digitalWrite(pin_laser, HIGH);
    } break;
    
    case 'S': {
      servos.stop();
      digitalWrite(pin_laser, LOW);
    } break;
  }

  servos.execute();
}

