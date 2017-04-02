#include <wifi_tools.h>
#include <http_tools.h>
#include <sound_effect.h>
#include "ServoControl.h"

#define pin_buzzer 12
#define pin_laser  16

// Key는 http://www.awesomeit.kr/cat_laser 에서 생성하시면 됩니다.
String key = "GewvSx6z78nNbABVqkPLXom9rfMdgJji";

// 공유기의 id와 암호를 입력하시기 바랍니다.
char *ssid = "xxxx";
char *password = "xxxx";

WiFiConnector connector(ssid, password);
WiFiServer server(80);
ServoControl servos(4, 5);
HttpGet http; 
SocketUDP udp;

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
  udp.begin(1122);
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

  http.get("www.awesomeit.kr", 80, "/api/set_user_ip?rid=" + key + "&local_ip=" + WiFi.localIP().toString()); 
  while (http.available()) {
    String line = http.readln();
    Serial.println(line);
  }

  seR2D2(pin_buzzer);
}

// UDP 소켓으로 들어온 좌표로 레이저를 이동
void getPosition()
{
  String line = udp.readString();
  if (line.length() > 0) {
    digitalWrite(pin_laser, HIGH);
  
    String pos_x = line.substring(0, 3);
    String pos_y = line.substring(4, 7);
    servos.gotoXY(pos_x.toInt(), pos_y.toInt());
    
//    Serial.println(line);  
//    Serial.print("pos_x: ");  Serial.println(pos_x);
//    Serial.print("pos_y: ");  Serial.println(pos_y);  
  }
}

void loop() {
  if (connector.onConnected()) {
    sendLocalIP();
  }

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
    
    case 'A': {
      servos.start(1);
      digitalWrite(pin_laser, HIGH);
    } break;
    
    case 'B': {
      servos.start(2);
      digitalWrite(pin_laser, HIGH);
    } break;
    
    case 'C': {
      servos.start(3);
      digitalWrite(pin_laser, HIGH);
    } break;
    
    case 'S': {
      servos.stop();
      digitalWrite(pin_laser, LOW);
    } break;
  }

  getPosition();

  servos.execute();
}

