// ************************************************************************ //
// The types declared in this file were generated from data read from the
// WSDL File described below:
// WSDL     : C:\Users\Jan\Desktop\4sem\NTP\SOAP_Oscari\IOscars.xml
//  >Import : C:\Users\Jan\Desktop\4sem\NTP\SOAP_Oscari\IOscars.xml>0
//  >Import : C:\Users\Jan\Desktop\4sem\NTP\SOAP_Oscari\IOscars.xml>1
// Version  : 1.0
// (25.5.2026. 17:13:55 - - $Rev: 122014 $)
// ************************************************************************ //

#include <System.hpp>
#pragma hdrstop

#include "IOscars.h"



namespace NS_IOscars {

_di_IOscars GetIOscars(bool useWSDL, System::String addr, Soaphttpclient::THTTPRIO* HTTPRIO)
{
  static const char* defWSDL= "C:\\Users\\Jan\\Desktop\\4sem\\NTP\\SOAP_Oscari\\IOscars.xml";
  static const char* defURL = "http://localhost:4125/soap/IOscars";
  static const char* defSvc = "IOscarsservice";
  static const char* defPrt = "IOscarsPort";
  if (addr=="")
    addr = useWSDL ? defWSDL : defURL;
  Soaphttpclient::THTTPRIO* rio = HTTPRIO ? HTTPRIO : new Soaphttpclient::THTTPRIO(0);
  if (useWSDL) {
    rio->WSDLLocation = addr;
    rio->Service = defSvc;
    rio->Port = defPrt;
  } else {
    rio->URL = addr;
  }
  _di_IOscars service;
  rio->QueryInterface(service);
  if (!service && !HTTPRIO)
    delete rio;
  return service;
}


// ************************************************************************ //
// This routine registers the interfaces and types exposed by the WebService.
// ************************************************************************ //
static void RegTypes()
{
  /* IOscars */
  InvRegistry()->RegisterInterface(__delphirtti(IOscars), L"urn:Oscars-IOscars", L"");
  InvRegistry()->RegisterDefaultSOAPAction(__delphirtti(IOscars), L"urn:Oscars-IOscars#%operationName%");
  /* IOscars->echoEnum */
  InvRegistry()->RegisterParamInfo(__delphirtti(IOscars), "echoEnum", "return_", L"return", L"");
  /* IOscars->echoStruct */
  InvRegistry()->RegisterParamInfo(__delphirtti(IOscars), "echoStruct", "return_", L"return", L"");
  /* IOscars->GetWinnerByYear */
  InvRegistry()->RegisterParamInfo(__delphirtti(IOscars), "GetWinnerByYear", "return_", L"return", L"");
  /* TSampleStruct */
  RemClassRegistry()->RegisterXSClass(__classid(TSampleStruct), L"urn:@:Oscars", L"TSampleStruct");
  /* SampleEnum */
  RemClassRegistry()->RegisterXSInfo(GetClsMemberTypeInfo(__typeinfo(SampleEnum_TypeInfoHolder)), L"urn:Oscars", L"SampleEnum");
}
#pragma startup RegTypes 32

};     // NS_IOscars

