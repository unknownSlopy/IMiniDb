 
//---------------------------------------------------------------------------
#ifndef WebModuleUnit1H
#define WebModuleUnit1H
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
	void __fastcall WebModule1sumaAction(TObject *Sender, TWebRequest *Request, TWebResponse *Response,
		  bool &Handled);

        // Oscar akcije
    void __fastcall GetNominationsByYearAction(TObject *Sender, TWebRequest *Request,
          TWebResponse *Response, bool &Handled);
    void __fastcall GetWinnersByYearAction(TObject *Sender, TWebRequest *Request,
		  TWebResponse *Response, bool &Handled);

private:	// User declarations
    TJSONArray *FOscarData;  // JSON podaci učitani u memoriju
	void LoadOscarData();    // metoda za učitavanje JSON-a

public:		// User declarations
	__fastcall TWebModule1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TWebModule1 *WebModule1;
//---------------------------------------------------------------------------
#endif


