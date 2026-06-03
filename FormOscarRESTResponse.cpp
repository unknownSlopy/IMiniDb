//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormOscarRESTResponse.h"
#include <System.JSON.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}

void TForm1::PrikaziRezultat(String jsonContent)
{
    TJSONArray *arr = dynamic_cast<TJSONArray*>(TJSONObject::ParseJSONValue(jsonContent));
    if (arr == NULL || arr->Count == 0)
    {
        ShowMessage("Nema podataka!");
        return;
    }

    // Postavi zaglavlja
	StringGridREST->ColCount = 5;
    StringGridREST->RowCount = arr->Count + 1;
    StringGridREST->Cells[0][0] = "Kategorija";
    StringGridREST->Cells[1][0] = "Godina";
    StringGridREST->Cells[2][0] = "Nominiran";
    StringGridREST->Cells[3][0] = "Film";
    StringGridREST->Cells[4][0] = "Pobjednik";

    int colWidth = StringGridREST->ClientWidth / 5;
    for (int i = 0; i < 5; i++)
        StringGridREST->ColWidths[i] = colWidth;

    // Popuni redove
	for (int i = 0; i < arr->Count; i++)
    {
        TJSONObject *item = dynamic_cast<TJSONObject*>(arr->Items[i]);
        if (item)
        {
            StringGridREST->Cells[0][i+1] = item->GetValue("category")->Value();
            StringGridREST->Cells[1][i+1] = item->GetValue("year")->Value();

            TJSONArray *nominees = dynamic_cast<TJSONArray*>(item->GetValue("nominees"));
            if (nominees && nominees->Count > 0)
                StringGridREST->Cells[2][i+1] = nominees->Items[0]->Value();

            TJSONArray *movies = dynamic_cast<TJSONArray*>(item->GetValue("movies"));
            if (movies && movies->Count > 0)
            {
                TJSONObject *movie = dynamic_cast<TJSONObject*>(movies->Items[0]);
                if (movie)
                    StringGridREST->Cells[3][i+1] = movie->GetValue("title")->Value();
            }

            StringGridREST->Cells[4][i+1] = item->GetValue("won")->Value();
        }
	}

    delete arr;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::StringGridRESTOnDrawCell(TObject *Sender, int ACol, int ARow,
      TRect &Rect, TGridDrawState State)
{
    if (ARow == 0) return; // preskoči zaglavlje

    if (StringGridREST->Cells[4][ARow] == "true")
    {
        StringGridREST->Canvas->Brush->Color = (TColor)RGB(212, 175, 55); // zlatna boja
    }
    else
    {
        StringGridREST->Canvas->Brush->Color = clWhite;
    }

    StringGridREST->Canvas->FillRect(Rect);
    StringGridREST->Canvas->TextOut(Rect.Left + 2, Rect.Top + 2,
        StringGridREST->Cells[ACol][ARow]);
}
