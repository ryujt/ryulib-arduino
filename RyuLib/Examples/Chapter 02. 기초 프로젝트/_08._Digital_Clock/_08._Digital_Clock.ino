#include <TM1637Display.h>
#include <DS1302.h>

// TM1637 LED tube pin
const int pin_led_clk = 2;
const int pin_led_io  = 3;

// Realtime Clock pin
const int pin_rt_ce  = 5; 
const int pin_rt_io  = 6; 
const int pin_rt_clk = 7; 

const int pin_hr = 10;
const int pin_min = 9;

TM1637Display display(pin_led_clk, pin_led_io);
DS1302 rtc(pin_rt_ce, pin_rt_io, pin_rt_clk);

int tick_count = 0;
bool display_dots = false;
Time time(0, 0, 0, 0, 0, 0, 0);

void displayTime() 
{
  uint8_t data[] = { 0b00000000, 0b00000000, 0b00000000, 0b00000000 };

  Serial.print(time.hr);
  Serial.print(":");
  Serial.println(time.min);
  
  time = rtc.time();

  int hr_lo = time.hr % 10;
  int hr_hi = (time.hr - hr_lo) / 10;

  if (hr_hi < 1) data[0] = display.encodeDigit(0);
  else data[0] = display.encodeDigit(hr_hi);

  if (hr_lo < 1) data[1] = display.encodeDigit(0);
  else data[1] = display.encodeDigit(hr_lo);
  
  int min_lo = time.min % 10;
  int min_hi = (time.min - min_lo) / 10;

  if (min_hi < 1) data[2] = display.encodeDigit(0);
  else data[2] = display.encodeDigit(min_hi);

  if (min_lo < 1) data[3] = display.encodeDigit(0);
  else data[3] = display.encodeDigit(min_lo);

  tick_count++;
  if (tick_count >= 4) {
      tick_count = 0;
      display_dots = ! display_dots;
      if (display_dots) data[1] = data[1] | 0b10000000;
  }
  
  display.setSegments(data);
}

void setup() 
{
  Serial.begin(9600);

  pinMode(pin_hr, INPUT_PULLUP);
  pinMode(pin_min, INPUT_PULLUP);

  display.setBrightness(0x0f);

  rtc.writeProtect(false);
  rtc.halt(false);

  displayTime();
}

void loop() 
{
  if (digitalRead(pin_hr) == LOW) {
    time.hr++;  
    if (time.hr > 11) time.hr = 0;
    rtc.time(time);
  }

  if (digitalRead(pin_min) == LOW) {
    time.min++;
    if (time.min > 59) time.min = 0;
    rtc.time(time);
  }
  
  displayTime();
  delay(100);  
}
