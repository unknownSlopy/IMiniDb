//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

// VCL / system / ostalo
#include <memory>
#include <registry.hpp>
#include <System.IOUtils.hpp>
#include <System.JSON.hpp>
#include <System.Net.HttpClient.hpp>
#include <System.Net.HttpClientComponent.hpp>
#include <REST.Types.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <System.Threading.hpp>
#include <System.SyncObjs.hpp>

// Projektni headeri
#include "PregledFilmova.h"
#include "DataTypes.h"
#include "Jezik_INI.h"
#include "omiljeniFilmovi.h"
#include "Funk.h"
#include "PosterDretva.h"
#include "PostaviJezikGrida.h"
#include "Slib/SLib.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "uTPLb_BaseNonVisualComponent"
#pragma link "uTPLb_Codec"
#pragma resource "*.dfm"
TFormSviFilmovi* FormSviFilmovi;

//---------------------------------------------------------------------------
__fastcall TFormSviFilmovi::TFormSviFilmovi(TComponent* Owner) : TForm(Owner) {}

void __fastcall TFormSviFilmovi::OsvjeziListu()
{
    _di_IXMLfilmoviType OFilmovi = Getfilmovi(XMLDocumentOmiljeniFilmovi);
    listViewOFilmovi->Items->Clear();

    for (int i = 0; i < OFilmovi->Count; i++) {
        TListItem* item = listViewOFilmovi->Items->Add();
        item->Caption = OFilmovi->film[i]->naslov;
        item->SubItems->Add(IntToStr(OFilmovi->film[i]->godina));
        item->SubItems->Add(IntToStr(OFilmovi->film[i]->trajanje));
        item->SubItems->Add(OFilmovi->film[i]->opis);
    }
}


void __fastcall TFormSviFilmovi::OcistiPolja()
{
    EditNoviNaziv->Text = "";
    EditNovaGodina->Text = "";
    EditNovoTrajanje->Text = "";
    MemoOpisNovogFilma->Text = "";
}

void __fastcall TFormSviFilmovi::SirinaDBGrida()
{
    int sirine[] = { 200, 60, 80, 150, 150, 250, 80, 80, 100 };
    int brojSirina = sizeof(sirine) / sizeof(sirine[0]);

	int maxCols = DBGridFilmoviBaza->Columns->Count;
    if (maxCols > brojSirina)
        maxCols = brojSirina;

    for (int i = 0; i < maxCols; i++)
        DBGridFilmoviBaza->Columns->Items[i]->Width = sirine[i];
}

void __fastcall TFormSviFilmovi::StilizirajLabele(TLabel* lbl)
{
    lbl->Font->Size = 16;
    lbl->Font->Style = TFontStyles() << fsBold;
    lbl->Font->Color = (TColor)0x00FFD700;
    lbl->Alignment = taCenter;
    lbl->Transparent = true;
}

void __fastcall TFormSviFilmovi::OsvjeziBrojFilmova()
{
    FDQueryBrojFilmova->Open();
    LabelUkupnoFilmova->Caption = FDQueryBrojFilmova->Fields->Fields[0]->AsString;
    FDQueryBrojFilmova->Close();
}

//---------------------------------------------------------------------------
void __fastcall TFormSviFilmovi::FormCreate(TObject* Sender)
{
    LabelOmiljeniFilmoviNaslov->Visible = false;
    LabelListaZaGledanje->Visible = false;

    String path = TPath::Combine(
        ExtractFilePath(Application->ExeName), "..\\..\\postavke.ini");
    TIniFile* ini = new TIniFile(path);

    FormSviFilmovi->StyleName = ini->ReadString("Stilovi", "stil1", "Obsidian");

    ini->WriteString(
        "HR", "ButtonDodajNoviOFilm", ButtonDodajNoviOFilm->Caption);
    ini->WriteString("HR", "ButtonUkloni", ButtonUkloni->Caption);
    ini->WriteString(
        "HR", "ButtonDodajWatchlistu", ButtonDodajWatchlistu->Caption);
    ini->WriteString(
        "HR", "ButtonOmiljeniFilmovi", ButtonOmiljeniFilmovi->Caption);

    ini->WriteString("ENG", "label6", "Movie name");
    ini->WriteString("ENG", "label7", "Year");
    ini->WriteString("ENG", "label8", "Duration");
    ini->WriteString("ENG", "label9", "Plot");
    ini->WriteString("ENG", "ButtonDodajNoviOFilm", "Add to Favourites");
    ini->WriteString("ENG", "ButtonUkloni", "Remove from Favourites");
    ini->WriteString("ENG", "ButtonDodajWatchlistu", "Add to Watchlist");
    ini->WriteString("ENG", "ButtonOmiljeniFilmovi", "Favourite movies");
    //GroupBoxRecenzija->StyleName = ini->ReadString("Stilovi", "stil2", "Obsidian");

    ButtonDodajNoviOFilm->StyleName = ini->ReadString("Stilovi", "stil2", "0");
    ButtonDodajWatchlistu->StyleName = ini->ReadString("Stilovi", "stil2", "0");
    ButtonOmiljeniFilmovi->StyleName = ini->ReadString("Stilovi", "stil2", "0");
    ButtonPregledajListu->StyleName = ini->ReadString("Stilovi", "stil2", "0");
    ButtonUkloni->StyleName = ini->ReadString("Stilovi", "stil2", "0");
    ButtonHRV->StyleName = ini->ReadString("Stilovi", "stil2", "0");
	ButtonENG->StyleName = ini->ReadString("Stilovi", "stil2", "0");
	ButtonRecenzije->StyleName = ini->ReadString("Stilovi", "stil2", "0");
	ButtonRESTBaza->StyleName = ini->ReadString("Stilovi", "stil2", "0");
	ToolButtonSQLSort->StyleName = ini->ReadString("Stilovi", "stil2", "0");
	ToolButtonSQLFilter->StyleName = ini->ReadString("Stilovi", "stil2", "0");
	ToolButtonSviPosteri->StyleName = ini->ReadString("Stilovi", "stil2", "0");

    ini->WriteString("HR", "LabelOmiljeniFilmoviNaslov", "Omiljeni Filmovi");
    ini->WriteString("HR", "LabelListaZaGledanje", "Lista za gledanje");
    ini->WriteString("ENG", "LabelOmiljeniFilmoviNaslov", "Favourite Movies");
	ini->WriteString("ENG", "LabelListaZaGledanje", "Watchlist");

    delete ini;

    int w = listViewOFilmovi->Width;
    listViewOFilmovi->Columns->Items[0]->Width = w * 2 / 16; // naslov
    listViewOFilmovi->Columns->Items[1]->Width = w * 1.5 / 16; // godina
    listViewOFilmovi->Columns->Items[2]->Width = w * 1.5 / 16; // trajanje
    listViewOFilmovi->Columns->Items[3]->Width = w * 11 / 16; // opis

    StilizirajLabele(LabelOmiljeniFilmoviNaslov);
    StilizirajLabele(LabelListaZaGledanje);
    StilizirajLabele(LabelPoster);
    StilizirajLabele(LabelUkupnoFilmova);
    StilizirajLabele(LabelFilm);

    SirinaDBGrida();

    //sql izracun
    OsvjeziBrojFilmova();

    FCS = new TCriticalSection();
	FBrojacPostera = 0;


    DBGridFilmoviBaza->Color = (TColor)0x1E1E1E;
    DBGridFilmoviBaza->Font->Name = "Segoe UI";
    DBGridFilmoviBaza->Font->Size = 9;
    DBGridFilmoviBaza->Font->Color = clWhite;
    DBGridFilmoviBaza->FixedColor = (TColor)0x2D2D2D;
    DBGridFilmoviBaza->TitleFont->Name = "Segoe UI Semibold";
    DBGridFilmoviBaza->TitleFont->Size = 9;
    DBGridFilmoviBaza->TitleFont->Color = (TColor)0xE74C3C;  // crveni headeri

    DBGridFilmoviBaza->Options = DBGridFilmoviBaza->Options
        << dgRowLines
		<< dgColLines
		<< dgEditing
		<< dgRowSelect;           // selektira cijeli red, ljepše izgleda

	DBGridFilmoviBaza->DrawingStyle = gdsClassic;  // da OnDrawColumnCell radi


    listViewOFilmovi->Color = (TColor)0x1E1E1E;
    listViewOFilmovi->Font->Name = "Segoe UI";
    listViewOFilmovi->Font->Size = 9;
    listViewOFilmovi->Font->Color = clWhite;
	listViewOFilmovi->ViewStyle = vsReport;    // da se vide kolone
    listViewOFilmovi->GridLines = true;
    listViewOFilmovi->RowSelect = true;
    listViewOFilmovi->ReadOnly = true;
	listViewOFilmovi->OwnerDraw = false;       // koristimo CustomDraw event


}
//---------------------------------------------------------------------------

void __fastcall TFormSviFilmovi::ButtonOmiljeniFilmoviClick(TObject* Sender)
{
    LabelOmiljeniFilmoviNaslov->Visible = true;
    LabelListaZaGledanje->Visible = false;
    OsvjeziListu();
}
//---------------------------------------------------------------------------

void __fastcall TFormSviFilmovi::ButtonHRVClick(TObject* Sender)
{
    PostaviJezik(this, "HR");
    String path = TPath::Combine(
        ExtractFilePath(Application->ExeName), "..\\..\\postavke.ini");
    TIniFile* ini = new TIniFile(path);

    LabelOmiljeniFilmoviNaslov->Caption =
        ini->ReadString("HR", "LabelOmiljeniFilmoviNaslov", "Omiljeni Filmovi");
    (*listViewOFilmovi->Columns)[0]->Caption =
        ini->ReadString("HR", "label6", "");
    (*listViewOFilmovi->Columns)[1]->Caption =
        ini->ReadString("HR", "label7", "");
    (*listViewOFilmovi->Columns)[2]->Caption =
        ini->ReadString("HR", "label8", "");
    (*listViewOFilmovi->Columns)[3]->Caption =
		ini->ReadString("HR", "label9", "");

	PostaviJezikGrida("HR");

    delete ini;
}
//---------------------------------------------------------------------------

void __fastcall TFormSviFilmovi::ButtonENGClick(TObject* Sender)
{
	PostaviJezik(this, "ENG");
    PostaviJezikGrida("ENG");
    String path = TPath::Combine(
        ExtractFilePath(Application->ExeName), "..\\..\\postavke.ini");
    TIniFile* ini = new TIniFile(path);

    (*listViewOFilmovi->Columns)[0]->Caption =
        ini->ReadString("ENG", "label6", "");
    (*listViewOFilmovi->Columns)[1]->Caption =
        ini->ReadString("ENG", "label7", "");
    (*listViewOFilmovi->Columns)[2]->Caption =
        ini->ReadString("ENG", "label8", "");
    (*listViewOFilmovi->Columns)[3]->Caption =
        ini->ReadString("ENG", "label9", "");

    delete ini;
}
//---------------------------------------------------------------------------

void __fastcall TFormSviFilmovi::ButtonDodajNoviOFilmClick(TObject* Sender)
{
    _di_IXMLfilmoviType OFilm = Getfilmovi(XMLDocumentOmiljeniFilmovi);
    int noviId = OFilm->Count > 0 ? OFilm->film[OFilm->Count - 1]->id + 1 : 1;
    _di_IXMLfilmType NoviOFilm = OFilm->Add();

    Film* noviFilm =
        new Film(noviId, EditNoviNaziv->Text, StrToInt(EditNovaGodina->Text),
            StrToInt(EditNovoTrajanje->Text), MemoOpisNovogFilma->Text);

    NoviOFilm->id = noviId;
    NoviOFilm->naslov = noviFilm->GetNaslov();
    NoviOFilm->godina = noviFilm->GetGodina();
    NoviOFilm->trajanje = noviFilm->GetTrajanje();
    NoviOFilm->opis = noviFilm->GetOpis();

    delete noviFilm;
    XMLDocumentOmiljeniFilmovi->SaveToFile(
        XMLDocumentOmiljeniFilmovi->FileName);
    OcistiPolja();
    OsvjeziListu();
}
//---------------------------------------------------------------------------

void __fastcall TFormSviFilmovi::ButtonUkloniClick(TObject* Sender)
{
    String PorukaUpozorenja = "Odaberi film za uklanjanje!";
    if (listViewOFilmovi->Selected == NULL) {
        ShowMessage(PorukaUpozorenja);
        return;
    }

    _di_IXMLfilmoviType OFilm = Getfilmovi(XMLDocumentOmiljeniFilmovi);
    OFilm->Delete(listViewOFilmovi->ItemIndex);
    XMLDocumentOmiljeniFilmovi->SaveToFile(
        XMLDocumentOmiljeniFilmovi->FileName);

    //listViewOFilmovi->Items->Delete(listViewOFilmovi->ItemIndex);
    OsvjeziListu();
    OcistiPolja();
}
//---------------------------------------------------------------------------

void __fastcall TFormSviFilmovi::ButtonDodajWatchlistuClick(TObject* Sender)
{
    if (listViewOFilmovi->Selected == NULL) {
        ShowMessage(
            "Odaberi film za dodavanje na listu!\nSelect a movie to add to the watchlist!");
        return;
    }

    TListItem* selektiraniItem = listViewOFilmovi->Selected;
    String naslov = selektiraniItem->Caption;
    String godina = selektiraniItem->SubItems->Strings[0];
    String trajanje = selektiraniItem->SubItems->Strings[1];
    String opis = selektiraniItem->SubItems->Strings[2];

    String jsonPath = TPath::Combine(
        ExtractFilePath(Application->ExeName), "..\\..\\listZaGledanje.json");

    // DEBUG -  path
    //ShowMessage("Path: " + jsonPath);

    try {
        TJSONArray* jsonArray = new TJSONArray();

        if (TFile::Exists(jsonPath)) {
            TStringList* sl = new TStringList();
            sl->LoadFromFile(jsonPath, TEncoding::UTF8);
            String sadrzaj = sl->Text.Trim();
            delete sl;

            //ShowMessage("Sadrzaj filea: " + sadrzaj); // DEBUG

            if (!sadrzaj.IsEmpty()) {
                TJSONValue* parsiran = TJSONObject::ParseJSONValue(sadrzaj);
                if (parsiran && parsiran->ClassNameIs("TJSONArray")) {
                    TJSONArray* postojeciArray =
                        static_cast<TJSONArray*>(parsiran);
                    for (int i = 0; i < postojeciArray->Count; i++) {
                        TJSONObject* obj =
                            static_cast<TJSONObject*>(postojeciArray->Items[i]);
                        if (obj->GetValue("naslov")->Value() == naslov) {
                            ShowMessage(
                                "Film je već na listi!\nMovie is already on the watchlist!");
                            delete jsonArray;
                            delete parsiran;
                            return;
                        }
                    }
                    delete jsonArray;
                    jsonArray = postojeciArray;
                } else {
                    delete parsiran;
                }
            }
        }

        TJSONObject* noviFilm = new TJSONObject();
        noviFilm->AddPair("naslov", naslov);
        noviFilm->AddPair("godina", godina);
        noviFilm->AddPair("trajanje", trajanje);
        noviFilm->AddPair("opis", opis);
        jsonArray->AddElement(noviFilm);

        String jsonString = jsonArray->ToString();
        //ShowMessage("Zapisujem: " + jsonString); // DEBUG - vidi sto zapisuje

        TFileStream* fs = new TFileStream(jsonPath, fmCreate);
        TEncoding* enc = TEncoding::UTF8;
        TBytes bytes = enc->GetBytes(jsonString);
        fs->WriteBuffer(&bytes[0], bytes.Length);
        delete fs;

        delete jsonArray;

        ShowMessage("Uspješno dodano!\nSuccessfully added!");

    } catch (Exception &e) {
        ShowMessage(e.Message);
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormSviFilmovi::ButtonPregledajListuClick(TObject* Sender)
{
    LabelOmiljeniFilmoviNaslov->Visible = false;
    LabelListaZaGledanje->Visible = true;

    String jsonPath = TPath::Combine(
        ExtractFilePath(Application->ExeName), "..\\..\\listZaGledanje.json");

    if (!TFile::Exists(jsonPath)) {
        ShowMessage("Lista je prazna!\nList is empty!");
        return;
    }

    try {
        TStringList* sl = new TStringList();
        sl->LoadFromFile(jsonPath, TEncoding::UTF8);
        String sadrzaj = sl->Text.Trim();
        delete sl;

        if (sadrzaj.IsEmpty()) {
            ShowMessage("Lista je prazna!\nList is empty!");
            return;
        }

        TJSONValue* parsiran = TJSONObject::ParseJSONValue(sadrzaj);
        if (!parsiran || !parsiran->ClassNameIs("TJSONArray")) {
            ShowMessage(
                "Greška pri čitanju watchliste!\nError reading watchlist!");
            delete parsiran;
            return;
        }

        TJSONArray* jsonArray = static_cast<TJSONArray*>(parsiran);

        listViewOFilmovi->Items->Clear();

        for (int i = 0; i < jsonArray->Count; i++) {
            TJSONObject* obj = static_cast<TJSONObject*>(jsonArray->Items[i]);

            TListItem* item = listViewOFilmovi->Items->Add();
            item->Caption = obj->GetValue("naslov")->Value();
            item->SubItems->Add(obj->GetValue("godina")->Value());
            item->SubItems->Add(obj->GetValue("trajanje")->Value());
            item->SubItems->Add(obj->GetValue("opis")->Value());
        }

        delete parsiran;

    } catch (Exception &e) {
        ShowMessage(e.Message);
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormSviFilmovi::listViewOFilmoviSelectItem(
    TObject* Sender, TListItem* Item, bool Selected)
{
    if (!Selected || Item == NULL)
        return;

    int idx = listViewOFilmovi->ItemIndex;
    if (idx < 0)
        return;

    _di_IXMLfilmoviType OFilmovi = Getfilmovi(XMLDocumentOmiljeniFilmovi);

    if (idx >= OFilmovi->Count)
        return;

    EditNoviNaziv->Text = OFilmovi->film[idx]->naslov;
    EditNovaGodina->Text = IntToStr(OFilmovi->film[idx]->godina);
    EditNovoTrajanje->Text = IntToStr(OFilmovi->film[idx]->trajanje);
    MemoOpisNovogFilma->Text = OFilmovi->film[idx]->opis;
}
//---------------------------------------------------------------------------


void __fastcall TFormSviFilmovi::ButtonRESTBazaClick(TObject* Sender)
{

    TOmdbParser *parser = new TOmdbParser();
    //taSourceFilm->DataSet = FDQuerySelect;
    AnsiString pojam = Trim(editFilmRESTBaza->Text);
    if (pojam.IsEmpty()) {
        ShowMessage("Upisi pojam.");
        return;
    }

    // === SEARCH ===
    RESTClient1->BaseURL = "http://www.omdbapi.com/";
    RESTRequest1->Method = TRESTRequestMethod::rmGET;
    RESTRequest1->Resource = "";
    RESTRequest1->Params->Clear();
    RESTRequest1->AddParameter("apikey", "8723c07c");
    RESTRequest1->AddParameter("s", pojam);
    RESTRequest1->AddParameter("page", "1");

    try {
        RESTRequest1->Execute();
    } catch (Exception &e) {
        ShowMessage("Greska: " + e.Message);
        return;
    }

    TJSONObject* jo =
        (TJSONObject*)TJSONObject::ParseJSONValue(RESTResponse1->Content);
    if (!jo) {
        ShowMessage("Neispravan JSON");
        return;
    }

    if (jo->GetValue("Response")->Value() == "False") {
        ShowMessage("OMDb: " + jo->GetValue("Error")->Value());
        FDTableFilm->Close();
        FDTableFilm->Open();
        delete jo;
        return;
    }

    TJSONArray* arr = (TJSONArray*)jo->GetValue("Search");
    int upisano = 0;

    // === LOOP: za svaki rezultat dohvati pune podatke i upisi ===
    for (int i = 0; i < arr->Count; i++) {
        TJSONObject* item = (TJSONObject*)arr->Items[i];
        AnsiString imdbID = item->GetValue("imdbID")->Value();

        // --- Dohvat punih podataka ---
        RESTRequest1->Params->Clear();
        RESTRequest1->AddParameter("apikey", "8723c07c");
        RESTRequest1->AddParameter("i", imdbID);
        RESTRequest1->AddParameter("plot", "full");

        try {
            RESTRequest1->Execute();
        } catch (...) {
            continue;
        }

        TJSONObject* jf =
            (TJSONObject*)TJSONObject::ParseJSONValue(RESTResponse1->Content);
        if (!jf)
            continue;
        if (jf->GetValue("Response")->Value() == "False") {
            delete jf;
            continue;
        }

// Helper za sigurno citanje stringa
#define GET(k)                                                     \
    (jf->GetValue(k) && !dynamic_cast<TJSONNull*>(jf->GetValue(k)) \
            ? AnsiString(jf->GetValue(k)->Value())                 \
            : AnsiString("N/A"))

        AnsiString s_imdbID = GET("imdbID");
        AnsiString s_naslov = GET("Title");
        AnsiString s_godina = GET("Year");
        AnsiString s_runtime = GET("Runtime");
        AnsiString s_opis = GET("Plot");
        AnsiString s_zanr = GET("Genre");
        AnsiString s_redat = GET("Director");
        AnsiString s_scen = GET("Writer");
        AnsiString s_glumci = GET("Actors");
        AnsiString s_jezik = GET("Language");
        AnsiString s_drzava = GET("Country");
        AnsiString s_nagrade = GET("Awards");
        AnsiString s_poster = GET("Poster");
        AnsiString s_rated = GET("Rated");
        AnsiString s_rel = GET("Released");
        AnsiString s_tip = GET("Type");
        AnsiString s_box = GET("BoxOffice");
        AnsiString s_iRate = GET("imdbRating");
        AnsiString s_iVotes = GET("imdbVotes");
        AnsiString s_meta = GET("Metascore");

        // parsiranja
        int godina = StrToIntDef(s_godina, 0);
        /*
        int trajanje = 0;
        int p = s_runtime.Pos(" ");
        if (p > 0)
            trajanje = StrToIntDef(s_runtime.SubString(1, p - 1), 0);

        double imdbRating = 0.0;
        TryStrToFloat(
            StringReplace(s_iRate, ".", FormatSettings.DecimalSeparator,
                TReplaceFlags() << rfReplaceAll),
            imdbRating);*/

        //int trajanje = ParseTrajanje(s_runtime);
        //double imdbRating = ParseImdbRating(s_iRate);


        int trajanje      = parser->ParseTrajanje(s_runtime);
        double imdbRating = parser->ParseImdbRating(s_iRate);


        int imdbVotes = StrToIntDef(
            StringReplace(s_iVotes, ",", "", TReplaceFlags() << rfReplaceAll),
            0);

        int metascore = StrToIntDef(s_meta, 0);

        double ratingRT = 0.0;
        TJSONArray* ratings =
            dynamic_cast<TJSONArray*>(jf->GetValue("Ratings"));
        if (ratings) {
            for (int k = 0; k < ratings->Count; k++) {
                TJSONObject* r = (TJSONObject*)ratings->Items[k];
                if (r->GetValue("Source")->Value() == "Rotten Tomatoes") {
                    AnsiString v = StringReplace(r->GetValue("Value")->Value(),
                        "%", "", TReplaceFlags() << rfReplaceAll);
                    TryStrToFloat(v, ratingRT);
                }
            }
        }

        // === INSERT ===
        FDQueryInsert->SQL->Text =
            "INSERT INTO Filmovi (imdbID, naslov, godina, trajanje, opis, zanr, "
            "redatelj, scenarist, glumci, jezik, drzava, nagrade, posterUrl, "
            "rated, released, tip, boxOffice, imdbRating, imdbVotes, metascore, ratingRT) "
            "VALUES (:imdbID, :naslov, :godina, :trajanje, :opis, :zanr, "
            ":redatelj, :scenarist, :glumci, :jezik, :drzava, :nagrade, :posterUrl, "
            ":rated, :released, :tip, :boxOffice, :imdbRating, :imdbVotes, :metascore, :ratingRT)";

        FDQueryInsert->ParamByName("imdbID")->AsString = s_imdbID;
        FDQueryInsert->ParamByName("naslov")->AsString = s_naslov;
        FDQueryInsert->ParamByName("godina")->AsInteger = godina;
        FDQueryInsert->ParamByName("trajanje")->AsInteger = trajanje;
        FDQueryInsert->ParamByName("opis")->AsString = s_opis;
        FDQueryInsert->ParamByName("zanr")->AsString = s_zanr;
        FDQueryInsert->ParamByName("redatelj")->AsString = s_redat;
        FDQueryInsert->ParamByName("scenarist")->AsString = s_scen;
        FDQueryInsert->ParamByName("glumci")->AsString = s_glumci;
        FDQueryInsert->ParamByName("jezik")->AsString = s_jezik;
        FDQueryInsert->ParamByName("drzava")->AsString = s_drzava;
        FDQueryInsert->ParamByName("nagrade")->AsString = s_nagrade;
        FDQueryInsert->ParamByName("posterUrl")->AsString = s_poster;
        FDQueryInsert->ParamByName("rated")->AsString = s_rated;
        FDQueryInsert->ParamByName("released")->AsString = s_rel;
        FDQueryInsert->ParamByName("tip")->AsString = s_tip;
        FDQueryInsert->ParamByName("boxOffice")->AsString = s_box;
        FDQueryInsert->ParamByName("imdbRating")->AsFloat = imdbRating;
        FDQueryInsert->ParamByName("imdbVotes")->AsInteger = imdbVotes;
        FDQueryInsert->ParamByName("metascore")->AsInteger = metascore;
        FDQueryInsert->ParamByName("ratingRT")->AsFloat = ratingRT;

        try {
            FDQueryInsert->ExecSQL();
            upisano++;

            FDQuerySelect->Close();
            FDQuerySelect->Open();
            Application->ProcessMessages();

        } catch (Exception &e) {
            ShowMessage("INSERT greska: " + e.Message);
            delete jf;
            break;
        }

        delete jf;
#undef GET

        Application->ProcessMessages();
        Sleep(100);
    }

    delete jo;

    FDTableFilm->Close();
    FDTableFilm->Open();
    SirinaDBGrida();
    //ShowMessage("Upisano: " + IntToStr(upisano));
    ShowUpisano(upisano);
    OsvjeziBrojFilmova();
    delete parser;
}

//---------------------------------------------------------------------------
// Pomoćna funkcija: provjerava je li poster već spremljen u bazu
bool __fastcall TFormSviFilmovi::PosterPostojiUBazi(const String &imdbID)
{
    bool postoji = false;
    TFDQuery* q = new TFDQuery(NULL);
    try {
        q->Connection = FDTableFilm->Connection;
        q->SQL->Text =
            "SELECT LENGTH(poster) AS vel FROM Filmovi WHERE imdbID = :id";
        q->ParamByName("id")->AsString = imdbID;
        q->Open();

        if (!q->IsEmpty() && !q->FieldByName("vel")->IsNull)
            postoji = q->FieldByName("vel")->AsInteger > 1000;
    } __finally
    {
        delete q;
    }
    return postoji;
}

// Pomoćna funkcija: refresh tablice uz zadržavanje trenutnog zapisa
void __fastcall TFormSviFilmovi::OsvjeziTablicutomZapisu()
{
    TBookmark bm = FDTableFilm->GetBookmark();
    FDTableFilm->DisableControls();
    try {
        FDTableFilm->Close();
        FDTableFilm->Open();
        FDTableFilm->GotoBookmark(bm);
    } __finally
    {
        FDTableFilm->FreeBookmark(bm);
        FDTableFilm->EnableControls();
    }
}

// Preuzima poster s URL-a i sprema u bazu kao blob
void __fastcall TFormSviFilmovi::SpremiPosterUBazu()
{
    String url = FDTableFilm->FieldByName("posterUrl")->AsString.Trim();
    if (url.IsEmpty() || url == "N/A") {
        String path = TPath::Combine(ExtractFilePath(Application->ExeName),
            "..\\..\\no-poster-available.jpg");

        if (!FileExists(path)) {
            ShowMessage("Nema slike na: " + path);
            return;
        }

        DBImage1->Picture->LoadFromFile(path);
        return;
    }

    String imdbID = FDTableFilm->FieldByName("imdbID")->AsString;

    std::unique_ptr<TNetHTTPClient> http(new TNetHTTPClient(NULL));
    std::unique_ptr<TMemoryStream> ms(new TMemoryStream());

    try {
        http->UserAgent = "Mozilla/5.0";
        http->HandleRedirects = true;
        http->Accept = "image/*";

        _di_IHTTPResponse response = http->Get(url, ms.get());

        if (response->StatusCode != 200 || ms->Size < 1000) {
            // ShowMessage("Greška pri dohvatu slike.");
            return;
        }

        ms->Position = 0;

        // UPDATE preko zasebnog querya - pouzdanije od FDTable->Edit/Post za blobove
        TFDQuery* q = new TFDQuery(NULL);
        try {
            q->Connection = FDTableFilm->Connection;
            q->SQL->Text =
                "UPDATE Filmovi SET poster = :blob WHERE imdbID = :id";
            q->ParamByName("blob")->DataType = ftBlob;
            q->ParamByName("blob")->LoadFromStream(ms.get(), ftBlob);
            q->ParamByName("id")->AsString = imdbID;
            q->ExecSQL();
        } __finally
        {
            delete q;
        }
    } catch (Exception &e) {
        ShowMessage("Greška: " + e.Message);
    }
}

// Prikazuje poster za trenutni film u DBImage1
void __fastcall TFormSviFilmovi::PrikaziPoster()
{
    DBImage1->Picture->Assign(NULL);
    if (FDTableFilm->IsEmpty()) {
        return;
    }
    String imdbID = FDTableFilm->FieldByName("imdbID")->AsString;
    TFDQuery* q = new TFDQuery(NULL);
    try {
        q->Connection = FDTableFilm->Connection;
        q->SQL->Text = "SELECT poster FROM Filmovi WHERE imdbID = :id";
        q->ParamByName("id")->AsString = imdbID;
        q->Open();
        if (q->IsEmpty())
            return;
        TBlobField* blob = (TBlobField*)q->FieldByName("poster");
        if (blob->IsNull || blob->DataSize == 0)
            return;
        std::unique_ptr<TMemoryStream> ms(new TMemoryStream());
        blob->SaveToStream(ms.get());
        ms->Position = 0;
        std::unique_ptr<TWICImage> img(new TWICImage());
        img->LoadFromStream(ms.get());
        DBImage1->Picture->Assign(img.get());
    } __finally
    {
        delete q;
    }
}

//---------------------------------------------------------------------------
// DBGrid event
//---------------------------------------------------------------------------

void __fastcall TFormSviFilmovi::DBGridFilmoviBazaCellClick(TColumn* Column)
{
    if (FDTableFilm->IsEmpty())
        return;

    String imdbID = FDTableFilm->FieldByName("imdbID")->AsString;

	if (!PosterPostojiUBazi(imdbID)) {
        SpremiPosterUBazu();
        OsvjeziTablicutomZapisu();
    }
}

//---------------------------------------------------------------------------

void __fastcall TFormSviFilmovi::ToolButtonSQLSortClick(TObject* Sender)
{
    FDQuerySortGodina->Close();
    FDQuerySortGodina->Open();

    DataSourceFilm->DataSet = FDQuerySortGodina;
    SirinaDBGrida();
}
//---------------------------------------------------------------------------

void __fastcall TFormSviFilmovi::ToolButtonSQLFilterClick(TObject* Sender)
{
    FDQueryFilterOcjena->Close();
    FDQueryFilterOcjena->Open();

    DataSourceFilm->DataSet = FDQueryFilterOcjena;
	SirinaDBGrida();
}

void __fastcall TFormSviFilmovi::ToolButtonSviPosteriClick(TObject* Sender)
{
    //thread
    // Skupi sve imdbID-eve koji jos nemaju poster
    TStringList* lista = new TStringList();
    TFDQuery* q = new TFDQuery(NULL);
    try {
        q->Connection = FDTableFilm->Connection;
        q->SQL->Text = "SELECT imdbID, posterUrl FROM Filmovi "
                       "WHERE (poster IS NULL OR LENGTH(poster) < 1000) "
                       "  AND posterUrl IS NOT NULL AND posterUrl <> 'N/A'";
        q->Open();
        while (!q->Eof) {
            lista->AddPair(q->FieldByName("imdbID")->AsString,
                q->FieldByName("posterUrl")->AsString);
            q->Next();
        }
    } __finally
    {
        delete q;
    }

    // za filmove BEZ posterUrl-a stavi lokalnu sliku iz mape projekta
    String lokalniPath = TPath::Combine(ExtractFilePath(Application->ExeName),
        "..\\..\\no-poster-available.jpg");

    if (FileExists(lokalniPath)) {
        TFDQuery* qBezUrl = new TFDQuery(NULL);
        TFDQuery* qUpdate = new TFDQuery(NULL);
        try {
            qBezUrl->Connection = FDTableFilm->Connection;
            qBezUrl->SQL->Text =
                "SELECT imdbID FROM Filmovi "
                "WHERE (poster IS NULL OR LENGTH(poster) < 1000) "
                "  AND (posterUrl IS NULL OR posterUrl = 'N/A' OR posterUrl = '' OR poster IS NULL OR poster = '')";
            qBezUrl->Open();

            if (!qBezUrl->IsEmpty()) {
                std::unique_ptr<TMemoryStream> ms(new TMemoryStream());
                ms->LoadFromFile(lokalniPath);

                qUpdate->Connection = FDTableFilm->Connection;
                qUpdate->SQL->Text =
                    "UPDATE Filmovi SET poster = :blob WHERE imdbID = :id";

                while (!qBezUrl->Eof) {
                    ms->Position = 0;
                    qUpdate->ParamByName("blob")->DataType = ftBlob;
                    qUpdate->ParamByName("blob")->LoadFromStream(
                        ms.get(), ftBlob);
                    qUpdate->ParamByName("id")->AsString =
                        qBezUrl->FieldByName("imdbID")->AsString;
                    qUpdate->ExecSQL();
                    qBezUrl->Next();
                }
            }
        } __finally
        {
            delete qBezUrl;
            delete qUpdate;
        }
    }

    if (lista->Count == 0) {
        ShowMessage("Svi posteri su vec skinuti.");
        delete lista;
        return;
    }

    FBrojacPostera = 0;
    int ukupno = lista->Count;

    // 2) Pokreni N paralelnih dretvi
    for (int i = 0; i < ukupno; i++) {
        new TPosterDretva(
            this, lista->Names[i], lista->ValueFromIndex[i], ukupno);
    }
    delete lista;
}
//---------------------------------------------------------------------------


