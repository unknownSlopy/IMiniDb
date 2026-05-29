//---------------------------------------------------------------------------

#ifndef DobrodosliH
#define DobrodosliH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormDobrodosli : public TForm
{
__published:	// IDE-managed Components
	TButton *ButtonRegistracijaForm;
	TButton *ButtonPrijavaForm;
	TButton *ButtonHRV;
	TButton *ButtonENG;
	TLabel *Label1;
	TImage *ImageLogo;
	void __fastcall ButtonHRVClick(TObject *Sender);
	void __fastcall ButtonENGClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormDobrodosli(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormDobrodosli *FormDobrodosli;
//---------------------------------------------------------------------------
#endif
