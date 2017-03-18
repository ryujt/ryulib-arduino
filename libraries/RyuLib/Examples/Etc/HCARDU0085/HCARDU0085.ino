/*
  Link
     * http://forum.hobbycomponents.com/viewtopic.php?f=40&t=1618&hilit=hcardu0085
     * https://teknobolge.com/iot/arduino-multifunction-shield

  Bluethooth Header (위에서부터 아래 방향으로)
    1. 
    2. 
    3. D0
    4. D1
    5. 
    6. 5V
    7. Gnd
    
  
  Pin
    A0 potentiometer
    A1 button
    A2 button
    A3 button
    A4 LM35 temperature sensor
    A5 sensor header pins
    0 APC220 headers
    1 APC220 headers
    2 IR receiver (headers marked IR receiver but could be anything we want)
    3 piezo
    4 Latch (segment Shift Register)
    5 servo header pins
    6 servo header pins
    7 Clock (segment SR)
    8 Data (segment SR)
    9 servo header pins
    10 led 4
    11 led 3
    12 led 2
    13 led 1
 */

#define LATCH_DIO 4
#define CLK_DIO 7
#define DATA_DIO 8
 
const byte SEGMENT_MAP[] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0X80,0X90};
const byte SEGMENT_SELECT[] = {0xF1,0xF2,0xF4,0xF8};


unsigned long Cur_ms_Count; // Stores the current time in ms
unsigned long Last_ms_Count; // Stores the last time in ms the counter was last updated
int Count; // Stores the value that will be displayed

void setup ()
{
  pinMode(LATCH_DIO, OUTPUT);
  pinMode(CLK_DIO, OUTPUT);
  pinMode(DATA_DIO, OUTPUT); 
  
  Cur_ms_Count = millis();
  Last_ms_Count = 0;
  Count = 0;
}

void loop()
{
 
  Cur_ms_Count = millis();
  
  if (Cur_ms_Count - Last_ms_Count > 100) {
    Last_ms_Count = Cur_ms_Count;
    if(Count < 9999) {
      Count++;
    } else {
      Count = 0;
    }
  }
  
  WriteNumber(Count);
}


void WriteNumber(int Number)
{
  WriteNumberToSegment(0 , Number / 1000);
  WriteNumberToSegment(1 , (Number / 100) % 10);
  WriteNumberToSegment(2 , (Number / 10) % 10);
  WriteNumberToSegment(3 , Number % 10);
}

void WriteNumberToSegment(byte Segment, byte Value)
{
  digitalWrite(LATCH_DIO, LOW); 
  shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_MAP[Value]);
  shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_SELECT[Segment] );
  digitalWrite(LATCH_DIO, HIGH);    
}
