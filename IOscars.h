// ************************************************************************ //
// The types declared in this file were generated from data read from the
// WSDL File described below:
// WSDL     : C:\Users\Jan\Desktop\4sem\NTP\SOAP_Oscari\IOscars.xml
//  >Import : C:\Users\Jan\Desktop\4sem\NTP\SOAP_Oscari\IOscars.xml>0
//  >Import : C:\Users\Jan\Desktop\4sem\NTP\SOAP_Oscari\IOscars.xml>1
// Version  : 1.0
// (25.5.2026. 17:13:55 - - $Rev: 122014 $)
// ************************************************************************ //

#ifndef   IOscarsH
#define   IOscarsH

#include <System.hpp>
#include <Soap.InvokeRegistry.hpp>
#include <Soap.XSBuiltIns.hpp>
#include <Soap.SOAPHTTPClient.hpp>

#if !defined(SOAP_REMOTABLE_CLASS)
#define SOAP_REMOTABLE_CLASS __declspec(delphiclass)
#endif

namespace NS_IOscars {

// ************************************************************************ //
// The following types, referred to in the WSDL document are not being represented
// in this file. They are either aliases[@] of other types represented or were referred
// to but never[!] declared in the document. The types from the latter category
// typically map to predefined/known XML or Embarcadero types; however, they could also 
// indicate incorrect WSDL documents that failed to declare or import a schema type.
// ************************************************************************ //
// !:int             - "http://www.w3.org/2001/XMLSchema"[]
// !:double          - "http://www.w3.org/2001/XMLSchema"[Gbl]
// !:string          - "http://www.w3.org/2001/XMLSchema"[Gbl]

class SOAP_REMOTABLE_CLASS TSampleStruct;

enum class SampleEnum   /* "urn:Oscars"[GblSmpl] */
{
  etNone, 
  etAFew, 
  etSome, 
  etALot
};

class SampleEnum_TypeInfoHolder : public TObject {
  SampleEnum __instanceType;
public:
  __fastcall ~SampleEnum_TypeInfoHolder() {};
__published:
  __property SampleEnum __propType = { read=__instanceType };
};



// ************************************************************************ //
// XML       : TSampleStruct, global, <complexType>
// Namespace : urn:@:Oscars
// ************************************************************************ //
class TSampleStruct : public TRemotable {
private:
  UnicodeString   FLastName;
  UnicodeString   FFirstName;
  double          FSalary;
__published:
  __property UnicodeString   LastName = { read=FLastName, write=FLastName };
  __property UnicodeString  FirstName = { read=FFirstName, write=FFirstName };
  __property double         Salary = { read=FSalary, write=FSalary };
};



// ************************************************************************ //
// Namespace : urn:Oscars-IOscars
// soapAction: urn:Oscars-IOscars#%operationName%
// transport : http://schemas.xmlsoap.org/soap/http
// style     : rpc
// use       : encoded
// binding   : IOscarsbinding
// service   : IOscarsservice
// port      : IOscarsPort
// URL       : http://localhost:4125/soap/IOscars
// ************************************************************************ //
__interface INTERFACE_UUID("{842F0662-5CE2-67FD-CB61-D29B9A027DA1}") IOscars : public System::IInvokable
{
public:
  virtual SampleEnum      echoEnum(const SampleEnum eValue) = 0; 
  virtual TSampleStruct*  echoStruct(const TSampleStruct* pEmployee) = 0; 
  virtual UnicodeString   GetWinnerByYear(const int godina) = 0; 
};
typedef DelphiInterface<IOscars> _di_IOscars;

_di_IOscars GetIOscars(bool useWSDL=false, System::String addr= System::String(), Soaphttpclient::THTTPRIO* HTTPRIO=0);


};     // NS_IOscars

#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using  namespace NS_IOscars;
#endif



#endif // IOscarsH
