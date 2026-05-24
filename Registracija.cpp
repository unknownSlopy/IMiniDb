//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Registracija.h"
#include "DataTypes.h"
#include "Stilovi.h"
#include "Jezik_INI.h"
//#include "StaticLib.h"

#include <System.IOUtils.hpp>
#include <registry.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormRegistracija *FormRegistracija;

//---------------------------------------------------------------------------
__fastcall TFormRegistracija::TFormRegistracija(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormRegistracija::ButtonRegistrirajClick(TObject *Sender)
{
    EditLozinka->PasswordChar = '*';
	Korisnik K_test;
    // validacija
    if (EditIme->Text.IsEmpty() || EditPrezime->Text.IsEmpty() ||
        EditKorIme->Text.IsEmpty() || EditEmail->Text.IsEmpty() ||
        EditLozinka->Text.IsEmpty())
    {
        ShowMessage("Molim popuni sva polja.");
        return;
	}

	K_test.setIme(EditIme->Text);
    K_test.setPrezime(EditPrezime->Text);
	K_test.setKorisnickoIme(EditKorIme->Text);
	K_test.setEmail(EditEmail->Text);
	K_test.setLozinka(EditLozinka->Text);


     TFDQuery *Query = new TFDQuery(NULL);
    try
    {
		Query->Connection = FDConnectionIMiniDB;
        Query->SQL->Text =
            "INSERT INTO korisnik (ime, prezime, korisnicko_ime, email, lozinka_hash) "
            "VALUES (:ime, :prezime, :kor_ime, :email, :lozinka_hash)";

        Query->ParamByName("ime")->AsString          = K_test.getIme();
        Query->ParamByName("prezime")->AsString      = K_test.getPrezime();
        Query->ParamByName("kor_ime")->AsString      = K_test.getKorIme();
        Query->ParamByName("email")->AsString        = K_test.getEmail();
        Query->ParamByName("lozinka_hash")->AsString = K_test.getLozinkaHash();

        try
        {
			if (!FDConnectionIMiniDB->Connected)
                FDConnectionIMiniDB->Connected = true;

            Query->ExecSQL();
            ShowMessage("Pozdrav, " + K_test.getKorIme() + "! Uspješno si registriran.");

            // Očisti polja nakon uspjeha
            EditIme->Clear();
            EditPrezime->Clear();
            EditKorIme->Clear();
            EditEmail->Clear();
			EditLozinka->Clear();
        }
        catch (EFDDBEngineException &e)
        {
            // Duplikat (UNIQUE constraint na korisnicko_ime ili email)
			if (e.Message.Pos("Duplicate") > 0 || e.Message.Pos("duplicate") > 0){
				ShowMessage("Korisnicko ime ili email vec postoji.");

				EditKorIme->Clear();
				EditEmail->Clear();
				EditLozinka->Clear();
			}
            else
                ShowMessage("Greška baze: " + e.Message);
        }
        catch (Exception &e)
        {
            ShowMessage("Greška: " + e.Message);
        }
    }
    __finally
    {
        delete Query;
    }

	//ShowMessage("Pozdrav, " + K_test.getKorIme() + "!");

}
//---------------------------------------------------------------------------



void __fastcall TFormRegistracija::FormCreate(TObject *Sender)
{
    //static lib -> ShowMessage(Radi());
	//String jsonPath = TPath::Combine(ExtractFilePath(Application->ExeName), "..\\..\\listZaGledanje.json");
	//String path = TPath::Combine(TPath::GetDocumentsPath(), "postavke.ini");
	String path = TPath::Combine(ExtractFilePath(Application->ExeName), "..\\..\\postavke.ini");
	TIniFile* ini = new TIniFile(path);

	ButtonKonf->StyleName = ini->ReadString("Stilovi", "stil2", "0");
	ButtonHRV->StyleName = ini->ReadString("Stilovi", "stil2", "0");
    ButtonENG->StyleName = ini->ReadString("Stilovi", "stil2", "0");

	ini->WriteString("HR", "label1", Label1->Caption);
	ini->WriteString("HR", "label2", Label2->Caption);
	ini->WriteString("HR", "label3", Label3->Caption);
	ini->WriteString("HR", "label4", Label4->Caption);
	ini->WriteString("HR", "label5", Label5->Caption);
	ini->WriteString("HR", "ButtonRegistriraj", ButtonRegistriraj->Caption);
	ini->WriteString("HR", "ButtonKonf", ButtonKonf->Caption);
	ini->WriteString("HR", "ButtonPrijava", "Prijavi se!");

	ini->WriteString("ENG", "label1", "Name:");
	ini->WriteString("ENG", "label2", "Surname:");
	ini->WriteString("ENG", "label3", "Username:");
	ini->WriteString("ENG", "label4", "e-mail:");
	ini->WriteString("ENG", "label5", "password:");
	ini->WriteString("ENG", "ButtonRegistriraj", "Register!");
	ini->WriteString("ENG", "ButtonKonf", "Save config");
	ini->WriteString("ENG", "ButtonPrijava", "Login!");

    delete ini;

	TRegistry* reg = new TRegistry;
	reg->RootKey = HKEY_LOCAL_MACHINE;
	reg->Access = KEY_READ | KEY_WRITE;


    if (reg->OpenKey("Software\\IMiniDB", true))
	{
		if (!reg->ValueExists("IMiniDB"))
			reg->WriteString("IMiniDB", FormatDateTime("dd.mm.yyyy", Now()));
		reg->CloseKey();
	}

	if (reg->OpenKey("Software\\IMiniDB\\Broj_otvaranja_apk", true))
	{
		if (!reg->ValueExists("IMiniDB_korisnika"))
			reg->WriteInteger("IMiniDB_korisnika", 0);
		reg->CloseKey();
	}

	try
	{
		if (reg->OpenKey("Software\\IMiniDB", true))
		{
			reg->WriteString("IMiniDB", FormatDateTime("dd.mm.yyyy hh:nn:ss", Now()));

			if (!reg->ValueExists("IMiniDB_br_otvaranja"))
				reg->WriteInteger("IMiniDB_br_otvaranja", 0);

			int trenutni = reg->ReadInteger("IMiniDB_br_otvaranja");
			reg->WriteInteger("IMiniDB_br_otvaranja", trenutni + 1);

			reg->CloseKey();
		}
	}
	__finally
	{
		reg->Free();
	}


	/*
    try {
	// Provjeri konekciju
	if (!FDConnectionIMiniDB->Connected) {
		ShowMessage("Konekcija NIJE spojena!");
		return;
    }
    ShowMessage("Konekcija OK");

	// Provjeri tablicu
    FDTable1->Close();
    FDTable1->Open();
    ShowMessage(
        "TableName: " + FDTable1->TableName + "\n" +
        "FieldCount: " + IntToStr(FDTable1->FieldCount) + "\n" +
		"RecordCount: " + IntToStr(FDTable1->RecordCount)
    );

	} catch (Exception &e) {
		ShowMessage("GREŠKA: " + e.Message);
	}

	*/

}
//---------------------------------------------------------------------------

void __fastcall TFormRegistracija::ButtonKonfClick(TObject *Sender)
{
	String path = TPath::Combine(TPath::GetDocumentsPath(), "postavke.ini");

	TIniFile* ini = new TIniFile(path);

	ini->WriteString("Stilovi", "stil1", FormRegistracija->StyleName);
	ini->WriteString("Stilovi", "stil2", GroupBoxRegistracija->StyleName);
	ini->WriteString("Stilovi", "boja1", FormRegistracija->Color);
	ini->WriteString("Stilovi", "zadnja-pohrana", FormatDateTime("dd.mm.yyyy hh:nn:ss", Now()));

	delete ini;
}
//---------------------------------------------------------------------------

void __fastcall TFormRegistracija::ButtonHRVClick(TObject *Sender)
{
	PostaviJezik(this, "HR");
}
//---------------------------------------------------------------------------


void __fastcall TFormRegistracija::ButtonENGClick(TObject *Sender)
{
    PostaviJezik(this, "ENG");
}
//---------------------------------------------------------------------------



