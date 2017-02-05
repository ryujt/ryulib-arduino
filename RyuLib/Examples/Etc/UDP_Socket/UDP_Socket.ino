#include <wifi_tools.h>


WiFiConnector connector("xxxx", "xxxx");
SocketUDP udp;


void setup() {
  Serial.begin(9600);

  connector.connect();
  udp.begin(1122);

  udp.send(IPAddress(52, 91, 211, 194), 2244, "your_email");
}

void loop() {
  if (connector.onConnected()) 

  connector.connect();
  
  String line = udp.readString();
  if (line.length() > 0) Serial.println(line);  
}
