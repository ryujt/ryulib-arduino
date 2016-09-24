#include <TM1637Display.h>
#include <DS1302.h>

// TM1637 LED tube pin
const int led_clk_pin = 2;
const int led_io_pin  = 4;

// Realtime Clock pin
const int rt_ce_pin  = 14; 
const int rt_io_pin  = 12; 
const int rt_clk_pin = 13; 

TM1637Display display(led_clk_pin, led_io_pin);
DS1302 rtc(rt_ce_pin, rt_io_pin, rt_clk_pin);

void setup() 
{
  Serial.begin(9600);

  display.setBrightness(0x0f);

  rtc.writeProtect(false);
  rtc.halt(false);
}

int tick_count = 0;
bool display_dots = false;

void displayTime() 
{
  uint8_t data[] = { 0b00000000, 0b00000000, 0b00000000, 0b00000000 };

  Time t = rtc.time();

  Serial.print(t.hr);
  Serial.print(":");
  Serial.println(t.min);
  
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
  if (tick_count >= 2) {
      tick_count = 0;
      display_dots = ! display_dots;
      if (display_dots) data[1] = data[1] | 0b10000000;
  }
  
  display.setSegments(data);
}

void loop() 
{
  displayTime();
  delay(200);  
}
