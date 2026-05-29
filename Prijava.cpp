//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Prijava.h"
#include "DataTypes.h"
#include "Jezik_INI.h"
#include <registry.hpp>
#include <System.IOUtils.hpp>
#include <windows.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "uTPLb_BaseNonVisualComponent"
#pragma link "uTPLb_Codec"
#pragma resource "*.dfm"
TFormPrijava *FormPrijava;
//---------------------------------------------------------------------------
__fastcall TFormPrijava::TFormPrijava(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
 /*
bool __fastcall TFormPrijava::JeKriptirano(const String& tekst)
{
    return tekst.SubString(1, 4) == "ENC:";
}


void __fastcall TFormPrijava::KriptirajEmailove()
{
    Codec1->StreamCipherId = "native.StreamToBlock";
	Codec1->BlockCipherId  = "native.AES-256";
	Codec1->ChainModeId    = "native.CBC";
	Codec1->Password = FLozinka;

    TFDQuery* qSelect = new TFDQuery(NULL);
    TFDQuery* qUpdate = new TFDQuery(NULL);
    int brojac = 0;

    try {
        qSelect->Connection = FDQueryPrijava->Connection;
        qSelect->SQL->Text = "SELECT korisnicko_ime, email FROM korisnik";
        qSelect->Open();

        qUpdate->Connection = FDQueryPrijava->Connection;
        qUpdate->SQL->Text = "UPDATE korisnik SET email = :enc WHERE korisnicko_ime = :kim";

        qSelect->Connection->StartTransaction();
        try {
            while (!qSelect->Eof) {
                String origEmail = qSelect->FieldByName("email")->AsString;
                String korIme = qSelect->FieldByName("korisnicko_ime")->AsString;

                if (!JeKriptirano(origEmail) && !origEmail.IsEmpty()) {
                    String encResult;
					Codec1->EncryptString(origEmail, encResult, TEncoding::UTF8);
					String enc = "ENC:" + encResult;

                    qUpdate->ParamByName("enc")->AsString = enc;
                    qUpdate->ParamByName("kim")->AsString = korIme;
                    qUpdate->ExecSQL();
                    brojac++;
                }
                qSelect->Next();
            }
            qSelect->Connection->Commit();
            FEmailoviKriptirani = true;
        } catch (...) {
            qSelect->Connection->Rollback();
            throw;
        }
    } __finally {
        delete qSelect;
        delete qUpdate;
    }

    // Demo poruka za profesora — možeš obrisati u finalnoj verziji
    // ShowMessage("Šifrirano emailova: " + IntToStr(brojac));
}

//---------------------------------------------------------------------------
// Vraća sve email-ove u originalni oblik
//---------------------------------------------------------------------------

/*
void __fastcall TFormPrijava::DekriptirajEmailove()
{

    Codec1->StreamCipherId = "native.StreamToBlock";
	Codec1->BlockCipherId  = "native.AES-256";
	Codec1->ChainModeId    = "native.CBC";
	Codec1->Password = FLozinka;


    TFDQuery* qSelect = new TFDQuery(NULL);
    TFDQuery* qUpdate = new TFDQuery(NULL);

    try {
        qSelect->Connection = FDQueryPrijava->Connection;
        qSelect->SQL->Text = "SELECT korisnicko_ime, email FROM korisnik";
        qSelect->Open();

        qUpdate->Connection = FDQueryPrijava->Connection;
        qUpdate->SQL->Text = "UPDATE korisnik SET email = :dec WHERE korisnicko_ime = :kim";

        qSelect->Connection->StartTransaction();
        try {
            while (!qSelect->Eof) {
                String encEmail = qSelect->FieldByName("email")->AsString;
                String korIme = qSelect->FieldByName("korisnicko_ime")->AsString;

                if (JeKriptirano(encEmail)) {
                    // Skini "ENC:" prefiks (5 znakova) i dešifriraj
                    String tekstZaDekript = encEmail.SubString(5, encEmail.Length() - 4);
                    String dec;
					Codec1->DecryptString(tekstZaDekript, dec, TEncoding::UTF8);

                    qUpdate->ParamByName("dec")->AsString = dec;
                    qUpdate->ParamByName("kim")->AsString = korIme;
                    qUpdate->ExecSQL();
                }
                qSelect->Next();
            }
            qSelect->Connection->Commit();
            FEmailoviKriptirani = false;
        } catch (...) {
            qSelect->Connection->Rollback();
            throw;
        }
    } __finally {
        delete qSelect;
        delete qUpdate;
    }
} */

void __fastcall TFormPrijava::ButtonPrijavaClick(TObject *Sender)
{
 	EditLozinkaPrijava->PasswordChar = '*';
	Korisnik K_prijava;

	AnsiString korisnickoIme = EditKorImePrijava->Text;
	AnsiString lozinka = EditLozinkaPrijava->Text;

	if (korisnickoIme.IsEmpty() || lozinka.IsEmpty()) {
        ShowMessage("Unesite korisničko ime i lozinku.");
        return;
    }

    try {
		FDQueryPrijava->Close();
		FDQueryPrijava->SQL->Clear();
		FDQueryPrijava->SQL->Add("SELECT COUNT(*) AS Broj FROM korisnik "
                          "WHERE korisnicko_ime = :korIme AND lozinka_hash = :loz");
		FDQueryPrijava->ParamByName("korIme")->AsString = korisnickoIme;
		FDQueryPrijava->ParamByName("loz")->AsString    = lozinka;
		FDQueryPrijava->Open();

		if (FDQueryPrijava->FieldByName("Broj")->AsInteger == 1) {
            ShowMessage("Uspješna prijava!\nPozdrav, " + korisnickoIme + "!");

            // ovdje otvori glavnu formu, sakrij prijavu itd.
        } else {
            ShowMessage("Neispravno korisničko ime ili lozinka.");
        }

		FDQueryPrijava->Close();
    }
    catch (Exception &e) {
        ShowMessage("Greška pri spajanju na bazu: " + e.Message);
    }

}
//---------------------------------------------------------------------------


void __fastcall TFormPrijava::FormCreate(TObject *Sender)
{

	String path = TPath::Combine(TPath::GetDocumentsPath(), "postavke.ini");
    TIniFile* ini = new TIniFile(path);
    FormPrijava->StyleName = ini->ReadString("Stilovi", "stil1", "Obsidian");
    GroupBoxPrijava->StyleName = ini->ReadString("Stilovi", "stil2", "Obsidian");
    delete ini;

    // Učitaj logo iz DLL-a
    String dllPath = TPath::Combine(
    ExtractFilePath(Application->ExeName), "dynamic.dll");

    HMODULE hDll = LoadLibrary(dllPath.c_str());
    if (hDll != NULL)
    {
        HBITMAP hBmp = (HBITMAP)LoadImage(
            hDll,
            MAKEINTRESOURCE(101),
            IMAGE_BITMAP,
            0, 0,
            LR_DEFAULTCOLOR
        );

        //test: ShowMessage("hBmp: " + IntToStr((int)hBmp));

        if (hBmp != NULL)
        {
            ImageLogo->Picture->Bitmap->Handle = hBmp;
        }
        FreeLibrary(hDll);
    }

}
//---------------------------------------------------------------------------

void __fastcall TFormPrijava::ButtonHRVClick(TObject *Sender) { PostaviJezik(this, "HR"); }
//---------------------------------------------------------------------------

void __fastcall TFormPrijava::ButtonENGClick(TObject *Sender){ PostaviJezik(this, "ENG"); }
//---------------------------------------------------------------------------

