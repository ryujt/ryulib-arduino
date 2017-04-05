unit SerialSocket;

interface

uses
  CPort,
  SysUtils, Classes;

type
  TSerialSocket = class
  private
    FComPort : TComPort;
  public
    constructor Create;
    destructor Destroy; override;

    procedure Open(APort:string);
    procedure Close;
  end;

implementation

{ TSerialSocket }

procedure TSerialSocket.Close;
begin
  try
    FComPort.Close;
  except
    //
  end;
end;

constructor TSerialSocket.Create;
begin
  inherited;

  FComPort := TComPort.Create(nil);
  FComPort.BaudRate := br9600;
  FComPort.Port := 'COM1';
  FComPort.Buffer.InputSize := 2048;
  FComPort.Buffer.OutputSize := 2048;
  FComPort.FlowControl.ControlDTR := dtrEnable;
  FComPort.FlowControl.ControlRTS := rtsEnable;
end;

destructor TSerialSocket.Destroy;
begin

  inherited;
end;

procedure TSerialSocket.Open(APort: string);
begin
  Close;

  FComPort.Port := APort;

  try
    FComPort.Open;
  except
    Close;
  end;
end;

end.


object dmGlobal: TdmGlobal
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 336
  Width = 466
  object ComPort: TComPort
    Events = [evRxChar, evTxEmpty, evRxFlag, evRing, evBreak, evCTS, evDSR, evError, evRLSD, evRx80Full]
    FlowControl.OutCTSFlow = False
    FlowControl.OutDSRFlow = False
    FlowControl.XonXoffOut = False
    FlowControl.XonXoffIn = False
    StoredProps = [spBasic]
    TriggersOnRxChar = True
    OnAfterOpen = ComPortAfterOpen
    OnAfterClose = ComPortAfterClose
    OnRxChar = ComPortRxChar
    OnError = ComPortError
    Left = 24
    Top = 12
  end
end