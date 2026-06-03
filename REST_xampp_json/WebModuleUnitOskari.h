
//---------------------------------------------------------------------------
#ifndef WebModuleUnitOskariH
#define WebModuleUnitOskariH
//---------------------------------------------------------------------------
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <Web.HTTPApp.hpp>
#include <System.JSON.hpp>
//---------------------------------------------------------------------------
class TWebModule1 : public TWebModule
{
__published:	// IDE-managed Components
	void __fastcall WebModule1DefaultHandlerAction(TObject *Sender, TWebRequest *Request,
		  TWebResponse *Response, bool &Handled);
	void __fastcall GetNominationsByYearAction(TObject *Sender, TWebRequest *Request,
          TWebResponse *Response, bool &Handled);
    void __fastcall GetWinnersByYearAction(TObject *Sender, TWebRequest *Request,
          TWebResponse *Response, bool &Handled);

private:	// User declarations
    TJSONArray *FOscarData;
    void LoadOscarData();
public:		// User declarations
	__fastcall TWebModule1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TWebModule1 *WebModule1;
//---------------------------------------------------------------------------
#endif


