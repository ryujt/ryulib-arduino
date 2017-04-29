#include <Compass.h>
#include <TM1637Display.h>

Compass compass;
TM1637Display display(2, 3);

void setup() {
  Serial.begin(9600);

  // 테스트 한 센서가 347(13)도 기울져 있다.
  compass.set_angle_offset(347);
  compass.begin();

  display.setBrightness(15);
}

void loop() {
//  Serial.println( compass.get_angle() );
//  delay(1000);

  display.showNumberDec( compass.get_angle() );    
  delay(10);
}
