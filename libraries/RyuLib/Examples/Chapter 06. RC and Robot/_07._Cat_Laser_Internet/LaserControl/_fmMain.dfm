object fmMain: TfmMain
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = 'Laser Control'
  ClientHeight = 385
  ClientWidth = 501
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object imgMain: TImage
    Left = 8
    Top = 8
    Width = 360
    Height = 360
    OnMouseDown = imgMainMouseDown
    OnMouseMove = imgMainMouseMove
  end
  object btPattern1: TButton
    Left = 382
    Top = 64
    Width = 75
    Height = 25
    Caption = 'Start #1'
    TabOrder = 0
    OnClick = btPattern1Click
  end
  object cbHori: TCheckBox
    Left = 382
    Top = 8
    Width = 97
    Height = 17
    Caption = #51340#50864#48152#51204
    TabOrder = 1
  end
  object cbVert: TCheckBox
    Left = 382
    Top = 31
    Width = 97
    Height = 17
    Caption = #49345#54616#48152#51204
    TabOrder = 2
  end
  object btPattern2: TButton
    Left = 382
    Top = 95
    Width = 75
    Height = 25
    Caption = 'Start #2'
    TabOrder = 3
    OnClick = btPattern2Click
  end
  object btPattern3: TButton
    Left = 382
    Top = 126
    Width = 75
    Height = 25
    Caption = 'Start #3'
    TabOrder = 4
    OnClick = btPattern3Click
  end
  object moSrc: TMemo
    Left = 16
    Top = 20
    Width = 185
    Height = 89
    Lines.Strings = (
      '#ifndef SERVOCONTROL_H'
      '#define SERVOCONTROL_H'
      ''
      ''
      '#include <Arduino.h>'
      '#include <Servo.h>'
      ''
      ''
      '#define SPEED 20'
      ''
      ''
      'const unsigned char pattern_1[@Size1] PROGMEM = { @Pattern1 };'
      'const unsigned char pattern_2[@Size2] PROGMEM = { @Pattern2 };'
      'const unsigned char pattern_3[@Size3] PROGMEM = { @Pattern3 };'
      ''
      ''
      'class ServoControl'
      '{'
      'private:'
      '  int no_;'
      '  int index_;'
      '  bool is_attached_;'
      #9'bool is_started_;'
      #9'long old_tick_;'
      #9'int count_;'
      ''
      #9'int pin_x_;'
      #9'int pin_y_;'
      #9'Servo servo_x_;'
      #9'Servo servo_y_;'
      'public:'
      #9'ServoControl(int pin_x, int pin_y)'
      
        #9#9': no_(1), index_(0), is_attached_(false), is_started_(false), ' +
        'old_tick_(0), count_(0),'
      #9#9'  pin_x_(pin_x), pin_y_(pin_y), servo_x_(), servo_y_()'
      #9'{'
      #9'}'
      ''
      #9'void attach()'
      #9'{'
      '    if (is_attached_) return;'
      ''
      '    is_attached_ = true;'
      ''
      #9#9'servo_x_.attach(pin_x_);'
      #9#9'servo_y_.attach(pin_y_);'
      #9'}'
      ''
      #9'void detach()'
      #9'{'
      '    is_attached_ = false;'
      ''
      #9#9'servo_x_.detach();'
      #9#9'servo_y_.detach();'
      #9'}'
      ''
      #9'void start(int no)'
      #9'{'
      '    no_ = no;'
      #9#9'is_started_ = true;'
      #9#9'old_tick_ = 0;'
      ''
      '    attach();'
      #9'}'
      ''
      #9'void stop()'
      #9'{'
      #9#9'is_started_ = false;'
      '    detach();'
      #9'}'
      ''
      ' void gotoXY(int x, int y)'
      ' {'
      '    is_started_ = false;'
      '    attach();'
      '    servo_x_.write(x);'
      '    servo_y_.write(y);'
      ' }'
      ''
      #9'void execute()'
      #9'{'
      #9#9'if (is_started_ == false) return;'
      ''
      #9#9'long tick = millis();'
      #9#9'long term;'
      
        #9#9'if ((tick > old_tick_) && (old_tick_ != 0)) count_ = count_ + ' +
        '(tick - old_tick_);'
      #9#9'old_tick_ = tick;'
      ''
      #9#9'if (count_ < SPEED) return;'
      #9#9'count_ = 0;'
      ''
      '    int size;'
      '    switch (no_) {'
      '      case 1: size = sizeof(pattern_1) / 2; break;'
      '      case 2: size = sizeof(pattern_2) / 2; break;'
      '      case 3: size = sizeof(pattern_3) / 2; break;'
      '    }'
      ''
      '    if (index_ >= size) index_ = 0;'
      ''
      '    int x;'
      '    int y;'
      '    switch (no_) {'
      '      case 1: {'
      '        x = pgm_read_byte(&pattern_1[index_ * 2]);'
      '        y = pgm_read_byte(&pattern_1[(index_ * 2) + 1]);'
      '      } break;'
      ''
      '      case 2: {'
      '        x = pgm_read_byte(&pattern_2[index_ * 2]);'
      '        y = pgm_read_byte(&pattern_2[(index_ * 2) + 1]);'
      '      } break;'
      ''
      '      case 3: {'
      '        x = pgm_read_byte(&pattern_3[index_ * 2]);'
      '        y = pgm_read_byte(&pattern_3[(index_ * 2) + 1]);'
      '      } break;'
      '    }'
      ''
      '    servo_x_.write(x);'
      '    servo_y_.write(y);'
      ''
      '    index_++;'
      #9'}'
      '};'
      ''
      ''
      '#endif // SERVOCONTROL_H')
    ScrollBars = ssBoth
    TabOrder = 5
    Visible = False
    WordWrap = False
  end
  object btSave: TButton
    Left = 382
    Top = 343
    Width = 75
    Height = 25
    Caption = 'Save'
    TabOrder = 6
    OnClick = btSaveClick
  end
  object SaveDialog: TSaveDialog
    DefaultExt = '.h'
    Filter = 'Header file|*.h'
    Left = 28
    Top = 200
  end
end
