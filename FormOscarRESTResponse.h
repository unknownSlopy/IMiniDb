//---------------------------------------------------------------------------

#ifndef FormOscarRESTResponseH
#define FormOscarRESTResponseH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TStringGrid *StringGridREST;
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
	void PrikaziRezultat(String jsonContent);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
