// ************************************************************************ //
// Implementation class for interface IOscars
// ************************************************************************ //
#include <stdio.h>
#include <vcl.h>

#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Phys.MySQL.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Param.hpp>
#include "FormUnit1.h"
#pragma hdrstop

#if !defined(__Oscars_h__)
#include <Soap.SOAPHTTPClient.hpp>
#include "Oscars.h"
#endif

// ************************************************************************ //
//  TOscarsImpl implements interface IOscars
// ************************************************************************ //
class TOscarsImpl : public TInvokableClass, public IOscars
{
public:
    /* Sample methods of IOscars */
  SampleEnum     echoEnum(SampleEnum eValue);
  //TDoubleArray   echoDoubleArray(const TDoubleArray daValue);
  TSampleStruct* echoStruct(const TSampleStruct* pStruct);
  //double         echoDouble(double dValue);
  AnsiString     GetWinnerByYear(int godina);

  /* IUnknown */
  HRESULT STDMETHODCALLTYPE QueryInterface(const GUID& IID, void **Obj)
                        { return GetInterface(IID, Obj) ? S_OK : E_NOINTERFACE; }
  ULONG STDMETHODCALLTYPE AddRef() { return TInvokableClass::_AddRef();  }
  ULONG STDMETHODCALLTYPE Release() { return TInvokableClass::_Release();  }
};


SampleEnum TOscarsImpl::echoEnum(SampleEnum eValue)
{
  /* TODO : Implement method echoEnum */
  return eValue;
}


/*TDoubleArray TOscarsImpl::echoDoubleArray(TDoubleArray daValue)
{
  TODO : Implement method echoDoubleArray
  return daValue;
}  */

TSampleStruct* TOscarsImpl::echoStruct(const TSampleStruct* pEmployee)
{
  /* TODO : Implement method echoMyEmployee */
  return new TSampleStruct();
}
 /*
double TOscarsImpl::echoDouble(const double dValue)
{
   TODO : Implement method echoDouble
  return dValue;
}   */

// moje metode (tijela)
AnsiString TOscarsImpl::GetWinnerByYear(int godina)
{
    try
    {
        if (!Form1->FDConnection1->Connected)
            Form1->FDConnection1->Connected = true;

        Form1->FDQuery1->Close();
        Form1->FDQuery1->SQL->Text =
            "SELECT pobjednik FROM oscar WHERE godina = :god AND kategorija = 'Best Picture'";
        Form1->FDQuery1->ParamByName("god")->AsInteger = godina;
        Form1->FDQuery1->Open();

        if (!Form1->FDQuery1->Eof)
            return Form1->FDQuery1->FieldByName("pobjednik")->AsString;

        return "Nema podataka";
    }
    catch (Exception &e)
    {
        return "Greška: " + e.Message;
    }
}


static void __fastcall OscarsFactory(System::TObject* &obj)
{
  static _di_IOscars iInstance;
  static TOscarsImpl *instance = 0;
  if (!instance)
  {
    instance = new TOscarsImpl();
    instance->GetInterface(iInstance);
  }
  obj = instance;
}



// ************************************************************************ //
//  The following routine registers the interface and implementation class
//  as well as the type used by the methods of the interface
// ************************************************************************ //
static void RegTypes()
{
  InvRegistry()->RegisterInterface(__delphirtti(IOscars));
  InvRegistry()->RegisterInvokableClass(__classid(TOscarsImpl), OscarsFactory);
}
#pragma startup RegTypes 32

