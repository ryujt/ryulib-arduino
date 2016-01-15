#include "Nokia5110.h"

int RST = 12;
int CE  = 11;
int DC  = 10;
int DIN =  9;
int CLK =  8;

void LcdInit() 
{
  pinMode(RST, OUTPUT);
  pinMode(CE, OUTPUT);
  pinMode(DC, OUTPUT);
  pinMode(DIN, OUTPUT);
  pinMode(CLK, OUTPUT);

  digitalWrite(RST, LOW);
  digitalWrite(RST, HIGH);

  LcdWriteCmd(0x21);
  LcdWriteCmd(0xB1);  
  LcdWriteCmd(0x04);  
  LcdWriteCmd(0x14);  
  LcdWriteCmd(0x20);  
  LcdWriteCmd(0x0C);  
}

void LcdWriteString(char *characters)
{
  while(*characters) LcdWriteCharacter(*characters++);
}

void LcdWriteCharacter(char character)
{
  for(int i=0; i<5; i++) LcdWriteData(pgm_read_byte(&ASCII[character - 0x20][i]));
  LcdWriteData(0x00);
}

void LcdWriteData(byte dat)
{
  digitalWrite(DC, HIGH); 
  digitalWrite(CE, LOW);
  shiftOut(DIN, CLK, MSBFIRST, dat);
  digitalWrite(CE, HIGH);
}

void LcdXY(int x, int y)
{
  LcdWriteCmd(0x80 | x);  
  LcdWriteCmd(0x40 | y);  
}

void LcdWriteCmd(byte cmd)
{
  digitalWrite(DC, LOW); 
  digitalWrite(CE, LOW);
  shiftOut(DIN, CLK, MSBFIRST, cmd); 

  digitalWrite(CE, HIGH);
}