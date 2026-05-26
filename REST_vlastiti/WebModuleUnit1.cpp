 
//---------------------------------------------------------------------------
#include "WebModuleUnit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TComponentClass WebModuleClass = __classid(TWebModule1);
//---------------------------------------------------------------------------
__fastcall TWebModule1::TWebModule1(TComponent* Owner)
	: TWebModule(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TWebModule1::WebModule1DefaultHandlerAction(TObject *Sender, TWebRequest *Request,
          TWebResponse *Response, bool &Handled)
{
  Response->Content =
    "<html>"
	"<head><title>REST test	</title></head>"
    "<body>Web Server Application</body>"
    "</html>";
}
//---------------------------------------------------------------------------


void __fastcall TWebModule1::WebModule1sumaAction(TObject *Sender, TWebRequest *Request,
          TWebResponse *Response, bool &Handled)
{
		  //da
	if(Request->QueryFields->Count != 2)
		Response->Content = "!!!";
	else
        Response->Content = Request->QueryFields->Values["a"].ToDouble() + Request->QueryFields->Values["b"].ToDouble();
}
//---------------------------------------------------------------------------
