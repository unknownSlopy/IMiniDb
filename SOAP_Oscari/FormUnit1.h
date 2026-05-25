 
//---------------------------------------------------------------------------

#ifndef FormUnit1H
#define FormUnit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.AppEvnts.hpp>
#include <IdHTTPWebBrokerBridge.hpp>
#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Phys.MySQL.hpp>
#include <FireDAC.Phys.MySQLDef.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <FireDAC.VCLUI.Wait.hpp>
#include <Soap.InvokeRegistry.hpp>
#include <Soap.Rio.hpp>
#include <Soap.SOAPHTTPClient.hpp>
#include <System.Net.URLClient.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *ButtonOpenBrowser;
	TApplicationEvents *ApplicationEvents1;
	TEdit *EditPort;
	TButton *ButtonStop;
	TButton *ButtonStart;
	TLabel *Label1;
	TFDConnection *FDConnection1;
	TFDQuery *FDQuery1;
	TFDPhysMySQLDriverLink *FDPhysMySQLDriverLink1;
	TFDTable *FDTable1;
	TButton *Button1;
	THTTPRIO *HTTPRIO1;
	void __fastcall ButtonStartClick(TObject *Sender);
	void __fastcall ButtonStopClick(TObject *Sender);
	void __fastcall ButtonOpenBrowserClick(TObject *Sender);
	void __fastcall ApplicationEvents1Idle(TObject *Sender, bool &Done);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
	TIdHTTPWebBrokerBridge *FServer;
    
	void __fastcall StartServer();
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif


