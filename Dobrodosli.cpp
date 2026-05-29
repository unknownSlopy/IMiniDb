//---------------------------------------------------------------------------

#include <vcl.h>
#include <IniFiles.hpp>
#include <System.IniFiles.hpp>
#include <System.IOUtils.hpp>
#include <windows.h>
#pragma hdrstop

#include "Jezik_INI.h"
#include "Dobrodosli.h"
#include "DLL/dynamic.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormDobrodosli *FormDobrodosli;
//---------------------------------------------------------------------------
__fastcall TFormDobrodosli::TFormDobrodosli(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFormDobrodosli::ButtonHRVClick(TObject *Sender)
{
	String p = TPath::Combine(ExtractFilePath(Application->ExeName), "..\\..\\postavke.ini");
	TIniFile* ini = new TIniFile(p);

	ButtonRegistracijaForm->Caption = ini->ReadString("HR", "ButtonRegistriraj", "");
	ButtonPrijavaForm->Caption = ini->ReadString("HR", "ButtonPrijava", "");

	delete ini;
}
//---------------------------------------------------------------------------

void __fastcall TFormDobrodosli::ButtonENGClick(TObject *Sender)
{
    String p = TPath::Combine(ExtractFilePath(Application->ExeName), "..\\..\\postavke.ini");
	TIniFile* ini = new TIniFile(p);

	ButtonRegistracijaForm->Caption = ini->ReadString("ENG", "ButtonRegistriraj", "");
	ButtonPrijavaForm->Caption = ini->ReadString("ENG", "ButtonPrijava", "");

    delete ini;
}
//---------------------------------------------------------------------------

void __fastcall TFormDobrodosli::FormCreate(TObject *Sender)
{
    Width = 680;
    String p = TPath::Combine(ExtractFilePath(Application->ExeName), "..\\..\\postavke.ini");
	TIniFile* ini = new TIniFile(p);

	ButtonRegistracijaForm->StyleName = ini->ReadString("Stilovi", "stil2", "0");
	ButtonPrijavaForm->StyleName = ini->ReadString("Stilovi", "stil2", "0");
	ButtonHRV->StyleName = ini->ReadString("Stilovi", "stil2", "0");
    ButtonENG->StyleName = ini->ReadString("Stilovi", "stil2", "0");

	delete ini;

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



        if (hBmp != NULL)
        {
            //Dimenzije bitmap loga su 680 x 300 piksela.
            ImageLogo->Width = 680;
    		ImageLogo->Height = 300;
            ImageLogo->Picture->Bitmap->Handle = hBmp;
        }
        FreeLibrary(hDll);
    }
}
//---------------------------------------------------------------------------

