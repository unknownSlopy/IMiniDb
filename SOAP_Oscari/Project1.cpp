
//---------------------------------------------------------------------------

#include <vcl.h>
#ifdef _WIN32
#include <tchar.h>
#endif
#pragma hdrstop
#include <Web.WebReq.hpp>
#ifdef USEPACKAGES
#pragma link "IndySystem.bpi"
#pragma link "IndyCore.bpi"
#pragma link "IndyProtocols.bpi"
#else
#pragma comment(lib, "IndySystem")
#pragma comment(lib, "IndyCore")
#pragma comment(lib, "IndyProtocols")
#endif
#pragma link "IdHTTPWebBrokerBridge"

//---------------------------------------------------------------------------
UUSEFORM("..\..\..\..\Desktop\4sem\NTP\SOAP_Oscari\FormUnit1.cpp", Form1);
USEFORM("FormUnit1.cpp", Form1);
USEFORM("WebModuleUnit1.cpp", WebModule1); /* TWebModule: File Type */
//---------------------------------------------------------------------------
xtern PACKAGE TComponentClass WebModuleClass;
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
  try
  {
    if (WebRequestHandler() != NULL)
    {
      WebRequestHandler()->WebModuleClass = WebModuleClass;
    }
    Application->Initialize();
    AApplication->CreateForm(__classid(TForm1), &Form1);
		pplication->Run();
  }
  catch (Exception &exception)
  {
    Sysutils::ShowException(&exception, System::ExceptAddr());
  }
  return 0;
}
//---------------------------------------------------------------------------



