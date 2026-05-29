//---------------------------------------------------------------------------

#ifndef PregledFilmovaH
#define PregledFilmovaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Xml.XMLDoc.hpp>
#include <Xml.xmldom.hpp>
#include <Xml.XMLIntf.hpp>
#include <Xml.XMLDoc.hpp>
#include <Xml.XMLIntf.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <FireDAC.VCLUI.Wait.hpp>
#include <FireDAC.Phys.MySQL.hpp>
#include <FireDAC.Phys.MySQLDef.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <Data.Bind.Components.hpp>
#include <Data.Bind.ObjectScope.hpp>
#include <REST.Client.hpp>
#include <REST.Types.hpp>
#include <Data.FMTBcd.hpp>
#include <Data.SqlExpr.hpp>
#include <Vcl.ActnCtrls.hpp>
#include <Vcl.ActnMan.hpp>
#include <Vcl.ToolWin.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.DBCtrls.hpp>
#include "uTPLb_BaseNonVisualComponent.hpp"
#include "uTPLb_Codec.hpp"
#include <System.SysUtils.hpp>
//---------------------------------------------------------------------------
class TFormSviFilmovi : public TForm
{
__published:	// IDE-managed Components
	TButton *ButtonDodajWatchlistu;
	TEdit *EditNoviNaziv;
	TEdit *EditNovaGodina;
	TLabel *Label6;
	TLabel *Label7;
	TButton *ButtonOmiljeniFilmovi;
	TListView *listViewOFilmovi;
	TButton *ButtonHRV;
	TButton *ButtonENG;
	TXMLDocument *XMLDocumentOmiljeniFilmovi;
	TButton *ButtonDodajNoviOFilm;
	TButton *ButtonUkloni;
	TEdit *EditNovoTrajanje;
	TLabel *Label8;
	TMemo *MemoOpisNovogFilma;
	TLabel *Label9;
	TButton *ButtonPregledajListu;
	TLabel *Label1;
	TLabel *LabelOmiljeniFilmoviNaslov;
	TLabel *LabelListaZaGledanje;
	TButton *ButtonRecenzije;
	TButton *ButtonRESTBaza;
	TDBGrid *DBGridFilmoviBaza;
	TFDConnection *FDConnectionZaFilmove;
	TFDPhysMySQLDriverLink *FDPhysMySQLDriverLink1;
	TFDTable *FDTableFilm;
	TDataSource *DataSourceFilm;
	TFDQuery *FDQuerySelect;
	TFDQuery *FDQueryInsert;
	TRESTClient *RESTClient1;
	TRESTRequest *RESTRequest1;
	TRESTResponse *RESTResponse1;
	TLabel *LabelFilm;
	TEdit *editFilmRESTBaza;
	TFDQuery *FDQuerySortGodina;
	TFDQuery *FDQueryFilterOcjena;
	TToolBar *ToolBar1;
	TToolButton *ToolButtonSQLSort;
	TToolButton *ToolButtonSQLFilter;
	TDBImage *DBImage1;
	TLabel *LabelPoster;
	TFDQuery *FDQueryBrojFilmova;
	TLabel *LabelUkupnoFilmova;
	TToolButton *ToolButtonSviPosteri;
	TCodec *SymetricCodec;
	TButton *Button1;
	TComboBox *ComboBoxFilmovi;
	TGroupBox *GroupBoxOmiljeni;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ButtonOmiljeniFilmoviClick(TObject *Sender);
	void __fastcall ButtonHRVClick(TObject *Sender);
	void __fastcall ButtonENGClick(TObject *Sender);
	void __fastcall ButtonDodajNoviOFilmClick(TObject *Sender);
	void __fastcall ButtonUkloniClick(TObject *Sender);
	void __fastcall OsvjeziListu();
	void __fastcall OcistiPolja();
	void __fastcall ButtonDodajWatchlistuClick(TObject *Sender);
	void __fastcall ButtonPregledajListuClick(TObject *Sender);
	void __fastcall listViewOFilmoviSelectItem(TObject *Sender, TListItem *Item, bool Selected);
	void __fastcall ButtonRESTBazaClick(TObject *Sender);
	void __fastcall SirinaDBGrida();
	void __fastcall ToolButtonSQLSortClick(TObject *Sender);
	void __fastcall ToolButtonSQLFilterClick(TObject *Sender);
	void __fastcall PrikaziPoster();
	void __fastcall SpremiPosterUBazu();
	void __fastcall DBGridFilmoviBazaCellClick(TColumn *Column);
	bool __fastcall PosterPostojiUBazi(const String &imdbID);
	void __fastcall OsvjeziTablicutomZapisu();
	void __fastcall StilizirajLabele(TLabel *lbl);
    void __fastcall OsvjeziBrojFilmova();
	void __fastcall ToolButtonSviPosteriClick(TObject *Sender);
    void __fastcall PostaviJezikGrida(String jezik);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall ComboBoxFilmoviChange(TObject *Sender);

	private:	// User declarations
    bool FIDjeviKriptirani;
    String FLozinka;

	void __fastcall PostaviOnGetText(TDataSet* ds);
    void __fastcall KriptiraniGetText(TField* Sender, String& Text, bool DisplayText);

	public:		// User declarations

	__fastcall TFormSviFilmovi(TComponent* Owner);
    TCriticalSection *FCS;   // inicijaliziraj u FormCreate, delete u FormDestroy
	int FBrojacPostera;

};

//---------------------------------------------------------------------------

extern PACKAGE TFormSviFilmovi *FormSviFilmovi;

//---------------------------------------------------------------------------

#endif
