//   Important note about DLL memory management when your DLL uses the
//   static version of the RunTime Library:
//
//   If your DLL exports any functions that pass String objects (or structs/
//   classes containing nested Strings) as parameter or function results,
//   you will need to add the library MEMMGR.LIB to both the DLL project and
//   any other projects that use the DLL.  You will also need to use MEMMGR.LIB
//   if any other projects which use the DLL will be performing new or delete
//   operations on any non-TObject-derived classes which are exported from the
//   DLL. Adding MEMMGR.LIB to your project will change the DLL and its calling
//   EXE's to use the BORLNDMM.DLL as their memory manager.  In these cases,
//   the file BORLNDMM.DLL should be deployed along with your DLL.
//
//   To avoid using BORLNDMM.DLL, pass string information using "char *" or
//   ShortString parameters.
//
//   If your DLL uses the dynamic version of the RTL, you do not need to
//   explicitly add MEMMGR.LIB as this will be done implicitly for you.
//   If you are using the static version of the RTL, add #include<usebormm.h>
//   to one of the source files for your DLL

#pragma hdrstop
#pragma argsused

#include <string>
#include <algorithm>
#include <windows.h>
#include "O_aplikaciji.h"
#include <vcl.h>
#include <System.IniFiles.hpp>
#include <System.IOUtils.hpp>

#define IDB_LOGO 101

class __declspec(dllexport) TStringUtils
{
public:
    __declspec(dllexport) std::string Skrati(std::string tekst, int maxZnakova)
    {
        if ((int)tekst.length() <= maxZnakova)
            return tekst;
        return tekst.substr(0, maxZnakova) + "...";
    }

    __declspec(dllexport) std::string LokalniDecimal(std::string vrijednost)
    {
        std::replace(vrijednost.begin(), vrijednost.end(), '.', ',');
        return vrijednost;
    }
};


extern "C" void __declspec(dllexport) __stdcall PrikaziOAplikaciji()
{

    String info = "IMiniDb v1.0\n"
              "Mini Movie Database\n"
              "© 2026\n\n"
              "Autor: Jan Šlopar\n"
              "JMBAG: 0246123378\n"
              "Kolegij: Napredne Tehnike Programiranja";

    TFormOAplikaciji* form = new TFormOAplikaciji(NULL);
    try {
        form->LabelInfo->Caption = info;
        form->ShowModal();
    } __finally {
        delete form;
    }
}

extern "C" bool __declspec(dllexport) __stdcall PrikaziPotvrduBrisanja(const wchar_t* naslov)
{
    String poruka = "Jeste li sigurni da želite obrisati film:\n" + String(naslov) + "?";
    int rezultat = MessageBoxW(NULL,
        poruka.c_str(),
        L"Potvrda brisanja",
        MB_YESNO | MB_ICONWARNING);
    return rezultat == IDYES;
}


extern "C" double __declspec(dllexport) __stdcall RadiDLL(){
    return 1.0;
}

extern "C" int _libmain(unsigned long reason)
{
	return 1;
}

