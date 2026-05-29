//---------------------------------------------------------------------------

#ifndef O_aplikacijiH
#define O_aplikacijiH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormOAplikaciji : public TForm
{
__published:	// IDE-managed Components
	TImage *ImageLogo;
	TLabel *LabelInfo;
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormOAplikaciji(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormOAplikaciji *FormOAplikaciji;
//---------------------------------------------------------------------------
#endif
