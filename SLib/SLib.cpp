#include <vcl.h>
#pragma hdrstop
#include "SLib.h"

double Radi()
{
    return 1.00;
}

int TOmdbParser::ParseTrajanje(AnsiString runtime)
{
    int p = runtime.Pos(" ");
    if (p > 0)
        return StrToIntDef(runtime.SubString(1, p - 1), 0);
    return 0;
}

double TOmdbParser::ParseImdbRating(AnsiString rating)
{
    double result = 0.0;
    TryStrToFloat(
        StringReplace(rating, ".", FormatSettings.DecimalSeparator,
            TReplaceFlags() << rfReplaceAll),
        result);
    return result;
}

void ShowUpisano(int upisano)
{
    TForm *dlg = new TForm((TComponent*)NULL);
    dlg->Width       = 340;
    dlg->Height      = 220;
    dlg->Position    = poScreenCenter;
    dlg->BorderStyle = bsDialog;
    dlg->Caption     = "Uvoz završen";
    dlg->Color       = TColor(0x000A0F08);

    TLabel *icon = new TLabel(dlg);
    icon->Parent      = dlg;
    icon->Caption     = "OK!";
    icon->Left        = 20;
    icon->Top         = 30;
    icon->Font->Size  = 20;
    icon->Font->Color = TColor(0x0052B869);
    icon->Font->Style = TFontStyles() << fsBold;

    TLabel *lbl = new TLabel(dlg);
    lbl->Parent      = dlg;
    lbl->Caption     = "Uspješno upisano filmova:";
    lbl->Left        = 20;
    lbl->Top         = 30;
    lbl->Font->Size  = 11;
    lbl->Font->Color = clWhite;

    TLabel *broj = new TLabel(dlg);
    broj->Parent      = dlg;
    broj->Caption     = IntToStr(upisano);
    broj->Left        = 20;
    broj->Top         = 60;
    broj->Font->Size  = 36;
    broj->Font->Style = TFontStyles() << fsBold;
    broj->Font->Color = TColor(0x0052B869);

    TButton *btn = new TButton(dlg);
    btn->Parent      = dlg;
    btn->Caption     = "OK";
    btn->Left        = 120;
    btn->Top         = 155;
    btn->Width       = 100;
    btn->Height      = 30;
    btn->ModalResult = mrOk;

    dlg->ShowModal();
    delete dlg;
}

#pragma package(smart_init)
