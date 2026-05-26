// ************************************************************************ //
// The types declared in this file were generated from data read from the
// WSDL File described below:
// WSDL     : http://localhost:4125/wsdl/IOscars
//  >Import : http://localhost:4125/wsdl/IOscars>0
//  >Import : http://localhost:4125/wsdl/IOscars>1
// Version  : 1.0
// (26.5.2026. 17:15:30 - - $Rev: 122014 $)
// ************************************************************************ //

#include <System.hpp>
#pragma hdrstop

#include "IOscars.h"



namespace NS_IOscars {

_di_IOscars GetIOscars(bool useWSDL, System::String addr, Soaphttpclient::THTTPRIO* HTTPRIO)
{
  static const char* defWSDL= "http://localhost:4125/wsdl/IOscars";
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


