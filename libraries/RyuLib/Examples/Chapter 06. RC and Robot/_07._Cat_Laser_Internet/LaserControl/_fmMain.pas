unit _fmMain;

interface

uses
  SimpleThread, UDPSocket, Strg, Disk,
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls, Vcl.ExtCtrls;

type
  TfmMain = class(TForm)
    imgMain: TImage;
    btPattern1: TButton;
    cbHori: TCheckBox;
    cbVert: TCheckBox;
    btPattern2: TButton;
    btPattern3: TButton;
    moSrc: TMemo;
    btSave: TButton;
    SaveDialog: TSaveDialog;
    procedure imgMainMouseDown(Sender: TObject; Button: TMouseButton;
      Shift: TShiftState; X, Y: Integer);
    procedure imgMainMouseMove(Sender: TObject; Shift: TShiftState; X,
      Y: Integer);
    procedure FormCreate(Sender: TObject);
    procedure FormDestroy(Sender: TObject);
    procedure btPattern1Click(Sender: TObject);
    procedure btPattern2Click(Sender: TObject);
    procedure btPattern3Click(Sender: TObject);
    procedure btSaveClick(Sender: TObject);
  private
    FSimpleThread : TSimpleThread;
  private
    FUDPSocket : TUDPSocket;
    procedure on_FUDPSocket_Received(const APeerIP:string; APeerPort:integer; AData:pointer; ASize:integer);
  private
    FIP : string;
    FX, FY, FOldX, FOldY : integer;
    FIndex : integer;
    FSizes : array [1..3] of integer;
    FPatterns : array [1..3] of PByteArray;
    procedure do_Clear;
    procedure do_Save(AFilename:string);
  public
  end;

var
  fmMain: TfmMain;

implementation

{$R *.dfm}

procedure TfmMain.btPattern1Click(Sender: TObject);
begin
  FIndex := 1;
  do_Clear;
end;

procedure TfmMain.btPattern2Click(Sender: TObject);
begin
  FIndex := 2;
  do_Clear;
end;

procedure TfmMain.btPattern3Click(Sender: TObject);
begin
  FIndex := 3;
  do_Clear;
end;

procedure TfmMain.btSaveClick(Sender: TObject);
begin
  if SaveDialog.Execute then do_Save(SaveDialog.FileName);
end;

procedure TfmMain.do_Clear;
begin
  FSizes[FIndex] := 0;

  FillChar(FPatterns[FIndex]^, 8 * 1024, 0);

  imgMain.Picture.Bitmap.Canvas.FillRect( Rect(0, 0, 360, 360) );

  imgMain.Picture.Bitmap.Canvas.Pen.Color := clBlack;
  imgMain.Picture.Bitmap.Canvas.Pen.Width := 1;

  imgMain.Picture.Bitmap.Canvas.MoveTo(180,   0);
  imgMain.Picture.Bitmap.Canvas.LineTo(180, 360);
  imgMain.Picture.Bitmap.Canvas.MoveTo(  0, 180);
  imgMain.Picture.Bitmap.Canvas.LineTo(360, 180);

  imgMain.Picture.Bitmap.Canvas.Pen.Color := clRed;
  imgMain.Picture.Bitmap.Canvas.Pen.Width := 2;
end;

procedure TfmMain.do_Save(AFilename:string);
var
  sLine, sResult : string;
  Pattern : PByteArray;
  LoopIndex, LoopSize, iSize: Integer;
begin
  sResult := moSrc.Text;

  for LoopIndex := 1 to 3 do begin
    sLine := '';

    Pattern := FPatterns[LoopIndex];

    iSize := FSizes[LoopIndex];
    if iSize = 0 then iSize := 8;

    for LoopSize := 0 to iSize-1 do begin
      sLine := sLine + '0x' + IntToHex(Pattern^[LoopSize], 2) + ', ';
    end;
    SetLength(sLine, Length(sLine)-2);

    sResult := StringReplace(sResult, '@Size'+IntToStr(LoopIndex), IntToStr(iSize), []);
    sResult := StringReplace(sResult, '@Pattern'+IntToStr(LoopIndex), sLine, []);
  end;

  SaveTextToFile(AFilename, sResult);
end;

procedure TfmMain.FormCreate(Sender: TObject);
var
  Loop: Integer;
begin
  FIP := ParamStr(1);

  FX := 0;
  FY := 0;
  FOldX := 0;
  FOldY := 0;

  FIndex := 1;

  for Loop := Low(FSizes) to High(FSizes) do begin
    FSizes[Loop] := 0;

    GetMem(FPatterns[Loop], 8 * 1024);
    FillChar(FPatterns[Loop]^, 8 * 1024, 0);
  end;

  imgMain.Picture.Bitmap.Width  := imgMain.Width;
  imgMain.Picture.Bitmap.Height := imgMain.Height;

  do_Clear;

  FUDPSocket := TUDPSocket.Create(Self);
  FUDPSocket.OnReceived := on_FUDPSocket_Received;

  FUDPSocket.Port := 2244;
  FUDPSocket.Start(false);

  FSimpleThread := TSimpleThread.Create(
    '',
    procedure (ASimpleThread:TSimpleThread)
    begin
      while ASimpleThread.Terminated = false do begin
        if (FX <> FOldX) or (FY <> FOldY) then begin
          FOldX := FX;
          FOldY := FY;

          FUDPSocket.SendTo(FIP, 1122, Format('%3d %3d', [FX, FY]));
        end;

        ASimpleThread.Sleep(10);
      end;
    end
  );
end;

procedure TfmMain.FormDestroy(Sender: TObject);
var
  Loop: Integer;
begin
  FSimpleThread.TerminateNow;

  for Loop := Low(FSizes) to High(FSizes) do begin
    FreeMem(FPatterns[Loop]);
  end;

//  FreeAndNil(FUDPSocket);
//  FreeAndNil(FSimpleThread);
end;

procedure TfmMain.imgMainMouseDown(Sender: TObject; Button: TMouseButton;
  Shift: TShiftState; X, Y: Integer);
var
  Pattern : PByteArray;
begin
  imgMain.Picture.Bitmap.Canvas.MoveTo(X, Y);

  FX := X div 2;
  FY := Y div 2;

  if cbHori.Checked then FX := 180 - FX;
  if cbVert.Checked then FY := 180 - FY;

  Pattern := FPatterns[FIndex];
  Pattern^[FSizes[FIndex]] := FX;
  Pattern^[FSizes[FIndex] + 1] := FY;
  FSizes[FIndex] := FSizes[FIndex] + 2;
end;

procedure TfmMain.imgMainMouseMove(Sender: TObject; Shift: TShiftState; X,
  Y: Integer);
var
  Pattern : PByteArray;
begin
  if Shift = [ssLeft] then begin
    imgMain.Picture.Bitmap.Canvas.LineTo(X, Y);

    FX := X div 2;
    FY := Y div 2;

    if cbHori.Checked then FX := 180 - FX;
    if cbVert.Checked then FY := 180 - FY;

    Pattern := FPatterns[FIndex];
    Pattern^[FSizes[FIndex]] := FX;
    Pattern^[FSizes[FIndex] + 1] := FY;
    FSizes[FIndex] := FSizes[FIndex] + 2;
  end;
end;

procedure TfmMain.on_FUDPSocket_Received(const APeerIP: string;
  APeerPort: integer; AData: pointer; ASize: integer);
begin
  Caption := Format('APeerIP: %s, APeerPort: %d', [APeerIP, APeerPort]) + DataToText(AData, ASize);
end;

end.
