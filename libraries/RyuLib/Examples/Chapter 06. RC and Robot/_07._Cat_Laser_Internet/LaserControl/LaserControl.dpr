program LaserControl;

uses
  Vcl.Forms,
  _fmMain in '_fmMain.pas' {fmMain},
  Vcl.Themes,
  Vcl.Styles;

{$R *.res}

begin
  Application.Initialize;
  Application.MainFormOnTaskbar := True;
  Application.Title := 'Laser Control';
  TStyleManager.TrySetStyle('Ruby Graphite');
  Application.CreateForm(TfmMain, fmMain);
  Application.Run;
end.
