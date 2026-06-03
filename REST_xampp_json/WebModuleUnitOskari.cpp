
//---------------------------------------------------------------------------
#include "WebModuleUnitOskari.h"

#include <System.IOUtils.hpp>
#include <System.JSON.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TComponentClass WebModuleClass = __classid(TWebModule1);
//---------------------------------------------------------------------------
__fastcall TWebModule1::TWebModule1(TComponent* Owner)
	: TWebModule(Owner)
{
	FOscarData = nullptr;
	LoadOscarData();
}
//---------------------------------------------------------------------------

void __fastcall TWebModule1::WebModule1DefaultHandlerAction(TObject *Sender, TWebRequest *Request,
          TWebResponse *Response, bool &Handled)
{
  Response->Content =
    "<html>"
	"<head><title>REST Oskari</title></head>"
    "<body>REST Oskari - json</body>"
    "</html>";
}
//---------------------------------------------------------------------------

/*
void __fastcall TWebModule1::WebModule1sumaAction(TObject *Sender, TWebRequest *Request,
          TWebResponse *Response, bool &Handled)
{
		  //da
	if(Request->QueryFields->Count != 2)
		Response->Content = "!!!";
	else
        Response->Content = Request->QueryFields->Values["a"].ToDouble() + Request->QueryFields->Values["b"].ToDouble();
} */
//---------------------------------------------------------------------------
void TWebModule1::LoadOscarData()
{
    String jsonPath = "C:\\xampp\\htdocs\\oscar-nominations.json";
    if (TFile::Exists(jsonPath))
    {
        String jsonContent = TFile::ReadAllText(jsonPath);
        FOscarData = dynamic_cast<TJSONArray*>(TJSONObject::ParseJSONValue(jsonContent));
    }
}
//---------------------------------------------------------------------------
void __fastcall TWebModule1::GetNominationsByYearAction(TObject *Sender, TWebRequest *Request,
          TWebResponse *Response, bool &Handled)
{
    Response->ContentType = "application/json";
    if (FOscarData == nullptr)
    {
        Response->Content = "{\"error\": \"Podaci nisu učitani\"}";
        return;
    }
    String year = Request->QueryFields->Values["year"];
    if (year.IsEmpty())
    {
        Response->Content = "{\"error\": \"Parametar year je obavezan\"}";
        return;
    }
    TJSONArray *result = new TJSONArray();
    for (int i = 0; i < FOscarData->Count; i++)
	{
		TJSONObject *item = dynamic_cast<TJSONObject*>(FOscarData->Items[i]);
		if (item && item->GetValue("year")->Value() == year)
		{
			TJSONObject *clone = dynamic_cast<TJSONObject*>(item->Clone());
			result->AddElement(clone);
		}
	}
    Response->Content = result->ToString();
    delete result;
}
//---------------------------------------------------------------------------
void __fastcall TWebModule1::GetWinnersByYearAction(TObject *Sender, TWebRequest *Request,
          TWebResponse *Response, bool &Handled)
{
    Response->ContentType = "application/json";
    if (FOscarData == nullptr)
    {
        Response->Content = "{\"error\": \"Podaci nisu učitani\"}";
        return;
    }
    String year = Request->QueryFields->Values["year"];
    if (year.IsEmpty())
    {
        Response->Content = "{\"error\": \"Parametar year je obavezan\"}";
        return;
    }
    TJSONArray *result = new TJSONArray();
    for (int i = 0; i < FOscarData->Count; i++)
	{
		TJSONObject *item = dynamic_cast<TJSONObject*>(FOscarData->Items[i]);
		if (item && item->GetValue("year")->Value() == year)
		{
			TJSONValue *won = item->GetValue("won");
			if (won && won->Value() == "true")
			{
				TJSONObject *clone = dynamic_cast<TJSONObject*>(item->Clone());
				result->AddElement(clone);
			}
		}
	}
    Response->Content = result->ToString();
    delete result;
}
