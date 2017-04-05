unit SerialSocket;

interface

uses
  SysUtils, Classes;

type
  TSerialSocket = class
  private
  public
    constructor Create;
    destructor Destroy; override;
  end;

implementation

{ TSerialSocket }

constructor TSerialSocket.Create;
begin
  inherited;

end;

destructor TSerialSocket.Destroy;
begin

  inherited;
end;

end.
