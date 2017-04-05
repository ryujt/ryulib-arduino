program SerialSocket_Test;

uses
  Vcl.Forms,
  _fmMain in '_fmMain.pas' {fmMain},
  SerialSocket in 'SerialSocket.pas';

{$R *.res}

begin
  Application.Initialize;
  Application.MainFormOnTaskbar := True;
  Application.CreateForm(TfmMain, fmMain);
  Application.Run;
end.
