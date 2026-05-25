//---------------------------------------------------------------------------

#ifndef SOAP_OscarH
#define SOAP_OscarH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TOSCARI : public TForm
{
__published:	// IDE-managed Components
	TDBGrid *DBGridOscari;
private:	// User declarations
public:		// User declarations
	__fastcall TOSCARI(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TOSCARI *OSCARI;
//---------------------------------------------------------------------------
#endif
