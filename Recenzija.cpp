//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Recenzija.h"
#include "DataTypes.h"
#include <registry.hpp>
#include <System.IOUtils.hpp>
#include <System.JSON.hpp>
#include <System.NetEncoding.hpp>

#include "IOscars.h"
#include <Soap.SOAPHTTPClient.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "frCoreClasses"
#pragma link "frxClass"
#pragma link "frxDBSet"
#pragma link "PdfDoc"
#pragma link "PReport"
#pragma link "frxExportBaseDialog"
#pragma link "frxExportPDF"
#pragma link "PdfDoc"
#pragma link "PReport"
#pragma link "PdfDoc"
#pragma link "PReport"
#pragma link "uTPLb_BaseNonVisualComponent"
#pragma link "uTPLb_Codec"
#pragma link "uTPLb_CryptographicLibrary"
#pragma resource "*.dfm"
TFormRecenzija *FormRecenzija;

static const int TRENUTNI_KORISNIK_ID = 8; // admin
//---------------------------------------------------------------------------
__fastcall TFormRecenzija::TFormRecenzija(TComponent* Owner)
    : TForm(Owner), editIndex(-1)
{
}
//---------------------------------------------------------------------------
static String PutanjaJSON()
{
    return TPath::Combine(ExtractFilePath(Application->ExeName), "..\\..\\recenzija.json");
}
//---------------------------------------------------------------------------
void __fastcall TFormRecenzija::FormCreate(TObject *Sender)
{
    String path = TPath::Combine(TPath::GetDocumentsPath(), "postavke.ini");

    TIniFile *ini = new TIniFile(path);
    FormRecenzija->StyleName     = ini->ReadString("Stilovi", "stil1", "Obsidian");
    StyleName                    = ini->ReadString("Stilovi", "stil1", "Obsidian");
	GroupBoxRecenzija->StyleName = ini->ReadString("Stilovi", "stil2", "Obsidian");
	delete ini;

    DohvatiRecenzijeIzBazeUJSON();
    UcitajRecenzijeUCombo();
    cmbFilm->ItemIndex = 0;
    editIndex = -1;
}

//---------------------------------------------------------------------------
void __fastcall TFormRecenzija::UcitajRecenzijeUCombo()
{
    cmbFilm->Items->BeginUpdate();
    try {
        cmbFilm->Items->Clear();
        cmbFilm->Items->AddObject("---- Nova recenzija ----", (TObject*)(NativeInt)(-1));

        String putanja = PutanjaJSON();
        if (!TFile::Exists(putanja)) return;

        TStringList *sl = new TStringList();
        sl->LoadFromFile(putanja, TEncoding::UTF8);
        String sadrzaj = sl->Text.Trim();
        delete sl;
        if (sadrzaj.IsEmpty()) return;

		TJSONValue *root = TJSONObject::ParseJSONValue(sadrzaj);
        if (root && root->ClassNameIs("TJSONArray")) {
            TJSONArray *arr = static_cast<TJSONArray*>(root);
            for (int i = 0; i < arr->Count; i++) {
                TJSONObject *obj = static_cast<TJSONObject*>(arr->Items[i]);

				String naslov;
				if (obj->GetValue("naslov")) naslov  = obj->GetValue("naslov")->Value();

                String stavka = "  |  " + naslov + "  |  ";
                cmbFilm->Items->AddObject(stavka, (TObject*)(NativeInt)i);
            }
        }
		if (root) delete root;

	} __finally {
		cmbFilm->Items->EndUpdate();
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormRecenzija::cmbFilmChange(TObject *Sender)
{
	if (cmbFilm->ItemIndex <= 0) {
        editIndex = -1;
        edtFilm->Clear();
        memTekst->Clear();
        TrackBarOcjena->Position = 5;
        dtpDatum->Date = Now();
        ButtonSpremiRecenziju->Caption = "Spremi recenziju";
        return;
    }
    editIndex = (int)(NativeInt)cmbFilm->Items->Objects[cmbFilm->ItemIndex];
    String putanja = PutanjaJSON();
    if (!TFile::Exists(putanja)) return;
    TStringList *sl = new TStringList();
    sl->LoadFromFile(putanja, TEncoding::UTF8);
    TJSONValue *root = TJSONObject::ParseJSONValue(sl->Text.Trim());
    delete sl;
    if (root && root->ClassNameIs("TJSONArray")) {
        TJSONArray  *arr = static_cast<TJSONArray*>(root);
        if (editIndex >= 0 && editIndex < arr->Count) {
            TJSONObject *obj = static_cast<TJSONObject*>(arr->Items[editIndex]);
            edtFilm->Text         = obj->GetValue("naslov")
                                    ? obj->GetValue("naslov")->Value() : String("");
            memTekst->Lines->Text = obj->GetValue("tekst")
                                    ? obj->GetValue("tekst")->Value() : String("");
            TrackBarOcjena->Position = StrToIntDef(
                obj->GetValue("ocjena") ? obj->GetValue("ocjena")->Value() : String("5"), 5);
            dtpDatum->Date        = StrToDateDef(
                obj->GetValue("datum") ? obj->GetValue("datum")->Value() : String(""), Now());
            ButtonSpremiRecenziju->Caption = "Izmijeni recenziju";
        }
        delete root;
    }
}
//---------------------------------------------------------------------------
void __fastcall TFormRecenzija::DohvatiRecenzijeIzBazeUJSON()
{
	try {
        FDQueryUnosRecenzije->Close();
        FDQueryUnosRecenzije->SQL->Text =
            "SELECT id, naslov, tekst, ocjena, datum "
            "FROM recenzija "
            "WHERE korisnik_id = :korisnik_id "
            "ORDER BY id";
        FDQueryUnosRecenzije->ParamByName("korisnik_id")->AsInteger = TRENUTNI_KORISNIK_ID;
        FDQueryUnosRecenzije->Open();

        TJSONArray *arr = new TJSONArray();
        try {
            while (!FDQueryUnosRecenzije->Eof) {
                TJSONObject *obj = new TJSONObject();
                obj->AddPair("id",
                    new TJSONNumber(FDQueryUnosRecenzije->FieldByName("id")->AsInteger));
                obj->AddPair("naslov",
                    FDQueryUnosRecenzije->FieldByName("naslov")->AsString);
                obj->AddPair("tekst",
                    FDQueryUnosRecenzije->FieldByName("tekst")->AsString);
                obj->AddPair("ocjena",
                    new TJSONNumber(FDQueryUnosRecenzije->FieldByName("ocjena")->AsInteger));
                obj->AddPair("datum",
                    FormatDateTime("yyyy-mm-dd",
                        FDQueryUnosRecenzije->FieldByName("datum")->AsDateTime));
                arr->AddElement(obj);
                FDQueryUnosRecenzije->Next();
            }
            FDQueryUnosRecenzije->Close();

            String putanja = PutanjaJSON();
            String jsonString = arr->ToString();

            TFileStream *fs = new TFileStream(putanja, fmCreate);
            try {
                System::Sysutils::TBytes bytes = TEncoding::UTF8->GetBytes(jsonString);
                if (bytes.Length > 0)
                    fs->WriteBuffer(&bytes[0], bytes.Length);
            } __finally {
                delete fs;
            }
        } __finally {
            delete arr;
        }
    } catch (Exception &e) {
        ShowMessage("Greska kod dohvata recenzija iz baze: " + e.Message);
    }
}
//---------------------------------------------------------------------------
void __fastcall TFormRecenzija::ButtonOdustaniClick(TObject *Sender)
{
	cmbFilm->ItemIndex = 0;
	cmbFilmChange(NULL);
}
//---------------------------------------------------------------------------
// Prolazi kroz JSON i za svaku stavku radi UPSERT u bazu
// (INSERT ako id ne postoji, UPDATE ako postoji - MySQL to rjesava sam)
void __fastcall TFormRecenzija::SinkronizirajJSONuBazu()
{
    String putanja = PutanjaJSON();
	if (!TFile::Exists(putanja)) return;

	TStringList *sl = new TStringList();
	sl->LoadFromFile(putanja, TEncoding::UTF8);
	TJSONValue *root = TJSONObject::ParseJSONValue(sl->Text.Trim());
	delete sl;

	if (!root || !root->ClassNameIs("TJSONArray")) {
        if (root) delete root;
        return;
    }

    TJSONArray *arr = static_cast<TJSONArray*>(root);

    for (int i = 0; i < arr->Count; i++) {
		TJSONObject *obj = static_cast<TJSONObject*>(arr->Items[i]);

        int    id     = StrToIntDef(obj->GetValue("id")->Value(), 0);
		String naslov = obj->GetValue("naslov") ? obj->GetValue("naslov")->Value() : String("");
		String tekst  = obj->GetValue("tekst")  ? obj->GetValue("tekst")->Value()  : String("");
		int    ocjena = StrToIntDef(
			obj->GetValue("ocjena") ? obj->GetValue("ocjena")->Value() : String("5"), 5);
		TDateTime datum = StrToDateDef(
			obj->GetValue("datum") ? obj->GetValue("datum")->Value() : String(""), Now());

		FDQueryUnosRecenzije->Close();
		FDQueryUnosRecenzije->Close();
		FDQueryUnosRecenzije->SQL->Text =
			"INSERT INTO recenzija (id, naslov, tekst, ocjena, datum, korisnik_id) "
			"VALUES (:id, :naslov, :tekst, :ocjena, :datum, :korisnik_id) "
			"ON DUPLICATE KEY UPDATE "
			"naslov = VALUES(naslov), tekst = VALUES(tekst), "
			"ocjena = VALUES(ocjena), datum = VALUES(datum)";
		FDQueryUnosRecenzije->ParamByName("id")->AsInteger          = id;
		FDQueryUnosRecenzije->ParamByName("naslov")->AsString       = naslov;
		FDQueryUnosRecenzije->ParamByName("tekst")->AsString        = tekst;
		FDQueryUnosRecenzije->ParamByName("ocjena")->AsInteger      = ocjena;
		FDQueryUnosRecenzije->ParamByName("datum")->AsDateTime      = datum;
		FDQueryUnosRecenzije->ParamByName("korisnik_id")->AsInteger = TRENUTNI_KORISNIK_ID;
		FDQueryUnosRecenzije->ExecSQL();
		}

	delete root;
}
//---------------------------------------------------------------------------
// Vraca najveci id iz JSON-a (0 ako je prazan)
static int MaxIdIzJSON(TJSONArray *arr)
{
    int maxId = 0;
    for (int i = 0; i < arr->Count; i++) {
        TJSONObject *obj = static_cast<TJSONObject*>(arr->Items[i]);
        TJSONValue *idVal = obj->GetValue("id");
        if (idVal) {
            int id = StrToIntDef(idVal->Value(), 0);
            if (id > maxId) maxId = id;
        }
    }
    return maxId;
}

int TFormRecenzija::MaxIdIzBaze()
{
    int maxId = 1;
    TFDQuery *q = new TFDQuery(NULL);
    try {
        q->Connection = FDQueryUnosRecenzije->Connection;
        q->SQL->Text = "SELECT COALESCE(MAX(id), 0) + 1 AS novi_id FROM recenzija";
        q->Open();
        maxId = q->FieldByName("novi_id")->AsInteger;
        q->Close();
    } __finally {
        delete q;
    }
    return maxId;
}
//---------------------------------------------------------------------------
void __fastcall TFormRecenzija::ButtonSpremiRecenzijuClick(TObject *Sender)
{
    if (edtFilm->Text.Trim().IsEmpty()) {
        ShowMessage("Naslov filma ne smije biti prazan!");
        return;
    }
    if (memTekst->Lines->Text.Trim().IsEmpty()) {
        ShowMessage("Tekst recenzije ne smije biti prazan!");
        return;
	}
    String putanja = PutanjaJSON();


    // ── MOD EDITIRANJA ────────────────────────────────────────────────────────
    if (editIndex >= 0) {
        if (MessageDlg("Sigurno zelis izmijeniti ovu recenziju?",
                mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) != mrYes)
            return;

        try {
            TStringList *sl = new TStringList();
            sl->LoadFromFile(putanja, TEncoding::UTF8);
            TJSONValue *root = TJSONObject::ParseJSONValue(sl->Text.Trim());
            delete sl;

            TJSONArray  *arr = static_cast<TJSONArray*>(root);
            TJSONObject *obj = static_cast<TJSONObject*>(arr->Items[editIndex]);

            // id ostaje isti, mijenjamo samo ostala polja
            obj->RemovePair("naslov"); obj->AddPair("naslov", edtFilm->Text.Trim());
            obj->RemovePair("ocjena"); obj->AddPair("ocjena", new TJSONNumber(TrackBarOcjena->Position));
            obj->RemovePair("tekst");  obj->AddPair("tekst",  memTekst->Lines->Text.Trim());
            obj->RemovePair("datum");  obj->AddPair("datum",  FormatDateTime("yyyy-mm-dd", dtpDatum->Date));

            TFileStream *fs = new TFileStream(putanja, fmCreate);
            System::Sysutils::TBytes bytes = TEncoding::UTF8->GetBytes(arr->ToString());
            fs->WriteBuffer(&bytes[0], bytes.Length);
            delete fs;
            delete root;

            // 2. korak: sinkroniziraj JSON -> baza
            SinkronizirajJSONuBazu();

            ShowMessage("Recenzija spremljena u JSON i sinkronizirana s bazom!");
            UcitajRecenzijeUCombo();
            cmbFilm->ItemIndex = 0;
            cmbFilmChange(NULL);
            ModalResult = mrOk;

        } catch (Exception &e) {
            ShowMessage(e.Message);
        }
        return;
    }

    // ── MOD NOVOG UNOSA ───────────────────────────────────────────────────────
    try {
        TJSONArray *jsonArray = new TJSONArray();

        if (TFile::Exists(putanja)) {
            TStringList *sl = new TStringList();
            sl->LoadFromFile(putanja, TEncoding::UTF8);
            String sadrzaj = sl->Text.Trim();
            delete sl;

            if (!sadrzaj.IsEmpty()) {
                TJSONValue *parsiran = TJSONObject::ParseJSONValue(sadrzaj);
                if (parsiran && parsiran->ClassNameIs("TJSONArray")) {
                    delete jsonArray;
                    jsonArray = static_cast<TJSONArray*>(parsiran);
                } else if (parsiran) {
                    delete parsiran;
                }
            }
        }

        // Generiraj novi id = max(id) + 1
        int noviId = MaxIdIzBaze();

        TJSONObject *rec = new TJSONObject();
        rec->AddPair("id",     new TJSONNumber(noviId));
        rec->AddPair("naslov", edtFilm->Text.Trim());
        rec->AddPair("tekst",  memTekst->Lines->Text.Trim());
        rec->AddPair("ocjena", new TJSONNumber(TrackBarOcjena->Position));
        rec->AddPair("datum",  FormatDateTime("yyyy-mm-dd", dtpDatum->Date));

        jsonArray->AddElement(rec);

        String jsonString = jsonArray->ToString();
		TFileStream *fs = new TFileStream(putanja, fmCreate);
        System::Sysutils::TBytes bytes = TEncoding::UTF8->GetBytes(jsonString);
        fs->WriteBuffer(&bytes[0], bytes.Length);
        delete fs;
        delete jsonArray;

        // 2. korak: sinkroniziraj JSON -> baza
        SinkronizirajJSONuBazu();

        ShowMessage("Recenzija spremljena u JSON i upisana u bazu!");
        UcitajRecenzijeUCombo();
        cmbFilm->ItemIndex = 0;
		cmbFilmChange(NULL);
        ModalResult = mrOk;

    } catch (Exception &e) {
        ShowMessage(e.Message);
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormRecenzija::ButtonPDFClick(TObject *Sender)
{
    String originalniEmail = "";
	bool biljeKriptiran = false;
	try {
		TFDQuery *qEmail = new TFDQuery(NULL);
		try {
			qEmail->Connection = FDQueryUnosRecenzije->Connection;
			qEmail->SQL->Text = "SELECT korisnicko_ime, email FROM korisnik WHERE id = :id";
			qEmail->ParamByName("id")->AsInteger = TRENUTNI_KORISNIK_ID;
			qEmail->Open();
			if (!qEmail->Eof) {
				String korIme = qEmail->FieldByName("korisnicko_ime")->AsString;
				String email = qEmail->FieldByName("email")->AsString;
				if (email.SubString(1, 4) == "ENC:") {
					biljeKriptiran = true;
					originalniEmail = email;
					String tekstZaDekript = email.SubString(5, email.Length() - 4);
					String dec;
					Codec2->StreamCipherId = "native.StreamToBlock";
					Codec2->BlockCipherId  = "native.AES-256";
					Codec2->ChainModeId    = "native.CBC";
					Codec2->Password       = korIme; // korisničko ime kao ključ
					Codec2->DecryptString(tekstZaDekript, dec, TEncoding::UTF8);
					TFDQuery *qUpdate = new TFDQuery(NULL);
					try {
						qUpdate->Connection = FDQueryUnosRecenzije->Connection;
						qUpdate->SQL->Text = "UPDATE korisnik SET email = :email WHERE id = :id";
						qUpdate->ParamByName("email")->AsString = dec;
						qUpdate->ParamByName("id")->AsInteger = TRENUTNI_KORISNIK_ID;
						qUpdate->ExecSQL();
					} __finally {
						delete qUpdate;
					}
				}
			}
			qEmail->Close();
		} __finally {
			delete qEmail;
		}
	}
	catch (Exception &e) {
		ShowMessage("Greška dekriptiranja emaila: " + e.Message);
		return;
	}

    FDQueryUnosRecenzije->Close();
	FDQueryUnosRecenzije->SQL->Text =
		"SELECT * FROM recenzija "
		"INNER JOIN korisnik ON korisnik.id = recenzija.korisnik_id "
		"WHERE recenzija.korisnik_id = :kid";
	FDQueryUnosRecenzije->ParamByName("kid")->AsInteger = TRENUTNI_KORISNIK_ID;
	FDQueryUnosRecenzije->Open();

    // Filter za korisnika
	FDTableKorisnik->Close();
	FDTableKorisnik->Filter = "id = " + IntToStr(TRENUTNI_KORISNIK_ID);
	FDTableKorisnik->Filtered = true;
	FDTableKorisnik->Open();

	// Filter za recenzije
	FDTableRecenzije->Close();
	FDTableRecenzije->Filter = "korisnik_id = " + IntToStr(TRENUTNI_KORISNIK_ID);
	FDTableRecenzije->Filtered = true;
	FDTableRecenzije->Open();

	frxReport1->LoadFromFile(
		ExtractFilePath(Application->ExeName) + "..\\..\\Izvjestaj2.fr3"
	);
	AnsiString put = ExtractFilePath(Application->ExeName) + "..\\..\\izvjestaj.pdf";
	frxPDFExport1->FileName = put;
	frxPDFExport1->ShowProgress = false;
	frxPDFExport1->ShowDialog   = false;


	frxReport1->PrepareReport(true);
	frxReport1->Export(frxPDFExport1);
	if (biljeKriptiran) {
		try {
			TFDQuery *qRestore = new TFDQuery(NULL);
			try {
				qRestore->Connection = FDQueryUnosRecenzije->Connection;
				qRestore->SQL->Text = "UPDATE korisnik SET email = :email WHERE id = :id";
				qRestore->ParamByName("email")->AsString = originalniEmail;
				qRestore->ParamByName("id")->AsInteger = TRENUTNI_KORISNIK_ID;
				qRestore->ExecSQL();
			} __finally {
				delete qRestore;
			}
		}
		catch (Exception &e) {
			ShowMessage("Greška ponovnog kriptiranja emaila: " + e.Message);
		}
	}

}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------

void __fastcall TFormRecenzija::ButtonOscarClick(TObject *Sender)
{
	// soap response
	try
    {
        // Koristi generirani helper - on sam postavi HTTPRIO ispravno
        _di_IOscars svc = NS_IOscars::GetIOscars(
			false,
			"http://localhost:4125/wsdl/IOscars"
		);

        UnicodeString rezultat = svc->GetWinnerByYear(2024);
        ShowMessage(rezultat);
    }
    catch (Exception &e)
    {
        ShowMessage("Greška: " + e.Message);
    }
}
//---------------------------------------------------------------------------

/*
Testiranje Static Library-ja

double Radi();
void __fastcall TFormRecenzija::Button_SLibClick(TObject *Sender)
{
    //testiranje SLib
    ShowMessage(Radi());
}*/
//---------------------------------------------------------------------------

