//---------------------------------------------------------------------------

#ifndef RecenzijaH
#define RecenzijaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Samples.Spin.hpp>
#include <Vcl.ComCtrls.hpp>
#include "frCoreClasses.hpp"
#include "frxClass.hpp"
#include <Data.DB.hpp>
#include <Data.SqlExpr.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Phys.MySQL.hpp>
#include <FireDAC.Phys.MySQLDef.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <FireDAC.VCLUI.Wait.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Stan.Param.hpp>
#include "frxDBSet.hpp"
//#include "PdfDoc.hpp"
//#include "PReport.hpp"
#include "frxExportBaseDialog.hpp"
#include "frxExportPDF.hpp"
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include "PdfDoc.hpp"
#include "PReport.hpp"
#include "uTPLb_BaseNonVisualComponent.hpp"
#include "uTPLb_Codec.hpp"
#include <System.SysUtils.hpp>

//---------------------------------------------------------------------------
class TFormRecenzija : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBoxRecenzija;
	TButton *ButtonSpremiRecenziju;
	TButton *ButtonOdustani;
	TMemo *memTekst;
	TDateTimePicker *dtpDatum;
	TLabel *Label1;
	TEdit *edtFilm;
	TLabel *Label2;
	TTrackBar *TrackBarOcjena;
	TLabel *Label4;
	TLabel *LabelOcjena;
	TLabel *LabelOcjena2;
	TLabel *LabelOcjena3;
	TLabel *LabelOcjena4;
	TLabel *LabelOcjena5;
	TLabel *LabelOcjena6;
	TLabel *LabelOcjena7;
	TLabel *LabelOcjena8;
	TLabel *LabelOcjena9;
	TLabel *LabelOcjena10;
	TComboBox *cmbFilm;
	TButton *ButtonPDF;
	TFDConnection *FDConnectionIMiniDB;
	TFDQuery *FDQueryUnosRecenzije;
	TFDPhysMySQLDriverLink *FDPhysMySQLDriverLink1;
	TFDTable *FDTableRecenzije;
	TFDTable *FDTableKorisnik;
	TDBGrid *DBGridLookUpRecenzije;
	TDataSource *DataSourceRecenzije;
	TDataSource *DataSourceKorisnik;
	TFDAutoIncField *FDTableRecenzijeid;
	TStringField *FDTableRecenzijenaslov;
	TMemoField *FDTableRecenzijetekst;
	TIntegerField *FDTableRecenzijeocjena;
	TDateTimeField *FDTableRecenzijedatum;
	TIntegerField *FDTableRecenzijekorisnik_id;
	TStringField *FDTableRecenzijeStudentIme;
	TStringField *FDTableRecenzijeRecenzirao;
	TfrxReport *frxReport1;
	TPReport *PReport1;
	TfrxDBDataset *frxDBDatasetRecenzije;
	TfrxDBDataset *frxDBDatasetKorisnik;
	TCodec *Codec1;
	TfrxPDFExport *frxPDFExport1;
	void __fastcall ButtonSpremiRecenzijuClick(TObject *Sender);
	void __fastcall ButtonOdustaniClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall cmbFilmChange(TObject *Sender);
	void __fastcall UcitajRecenzijeUCombo();
	void __fastcall SinkronizirajJSONuBazu();
    void __fastcall DohvatiRecenzijeIzBazeUJSON();
	void __fastcall ButtonPDFClick(TObject *Sender);
	void __fastcall frxReport1BeforePrint(TfrxReportComponent *Sender);
private:	// User declarations
    int editIndex;
	void UcitajFilmoveUCombo();

    String FLozinka;
	bool   FFileKriptiran;

	void __fastcall KriptirajFile(const String& path);
    void __fastcall DekriptirajFile(const String& path);
public:		// User declarations
	__fastcall TFormRecenzija(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormRecenzija *FormRecenzija;
//---------------------------------------------------------------------------
#endif
