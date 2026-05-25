//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
#include "DataTypes.h"
#include "Registracija.h"
#include "Prijava.h"
#include "Recenzija.h"
#include "PregledFilmova.h"
#include "Dobrodosli.h"
#include "IOscars.h"
#include <Vcl.Styles.hpp>
#include <Vcl.Themes.hpp>

int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		TStyleManager::TrySetStyle("Obsidian");
		//Application->CreateForm(__classid(TFormRecenzija), &FormRecenzija);
		//Application->CreateForm(__classid(TFormSviFilmovi), &FormSviFilmovi);
		Application->CreateForm(__classid(TFormRecenzija), &FormRecenzija);
		Application->CreateForm(__classid(TFormPrijava), &FormPrijava);
		Application->CreateForm(__classid(TFormRegistracija), &FormRegistracija);
		Application->CreateForm(__classid(TFormDobrodosli), &FormDobrodosli);
		//Application->CreateForm(__classid(TOSCARI), &OSCARI);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
