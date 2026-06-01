//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <System.Net.URLClient.hpp>
#include <System.Net.HttpClient.hpp>
#include <System.Net.HttpClientComponent.hpp>

#include "PosterDretva.h"
#include "PregledFilmova.h"

#pragma package(smart_init)
//---------------------------------------------------------------------------

__fastcall TPosterDretva::TPosterDretva(TFormSviFilmovi *form, const String &id,
                                        const String &url, int ukupno)
    : TThread(false), FForm(form), FImdbID(id), FUrl(url),
      FUkupno(ukupno), FMS(NULL)
{
    FreeOnTerminate = true;
}

void __fastcall TPosterDretva::Execute()
{
    TNetHTTPClient *http = new TNetHTTPClient(NULL);
    TMemoryStream  *ms   = new TMemoryStream();
    try {
        http->UserAgent = "Mozilla/5.0";
        http->HandleRedirects = true;
        http->Accept = "image/*";

        _di_IHTTPResponse r = http->Get(FUrl, ms);
        if (r->StatusCode == 200 && ms->Size > 1000) {
            ms->Position = 0;
            FMS = ms;
            Synchronize(&SyncUpdateBaze);
            FMS = NULL;
        }
    }
    catch (...) { /* preskoci */ }

    delete ms;
    delete http;

    Queue(&QueueProgres);
}

void __fastcall TPosterDretva::SyncUpdateBaze()
{
    TFDQuery *uq = new TFDQuery(NULL);
    try {
        uq->Connection = FForm->FDTableFilm->Connection;
        uq->SQL->Text  = "UPDATE Filmovi SET poster=:b WHERE imdbID=:id";
        uq->ParamByName("b")->DataType = ftBlob;
        uq->ParamByName("b")->LoadFromStream(FMS, ftBlob);
        uq->ParamByName("id")->AsString = FImdbID;
        uq->ExecSQL();
    }
    __finally { delete uq; }
}

void __fastcall TPosterDretva::QueueProgres()
{
    FForm->FCS->Acquire();
    try { FForm->FBrojacPostera++; } __finally { FForm->FCS->Release(); }

    FForm->LabelUkupnoFilmova->Caption =
		"Posteri: " + IntToStr(FForm->FBrojacPostera) + "/" + IntToStr(FUkupno);

	// Ažuriraj progress bar
    int postotak = (FForm->FBrojacPostera * 100) / FUkupno;
    FForm->ProgressBar1->Position = postotak;
	FForm->LabelProgres->Caption = IntToStr(postotak) + "%";

    if (FForm->FBrojacPostera >= FUkupno) {
        FForm->ProgressBar1->Position = 100;
        FForm->LabelProgres->Caption = "100%";
        ShowMessage("Svi posteri skinuti!");
        FForm->OsvjeziTablicutomZapisu();
    }
}
