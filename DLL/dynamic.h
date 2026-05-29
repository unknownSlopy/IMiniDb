// DLL/dynamic.h
#pragma once
#include <string>
#include <algorithm>

class __declspec(dllimport) TStringUtils
{
public:
    __declspec(dllimport) std::string Skrati(std::string tekst, int maxZnakova);
    __declspec(dllimport) std::string LokalniDecimal(std::string vrijednost);
};

extern "C" double __declspec(dllimport) __stdcall RadiDLL();
extern "C" void __declspec(dllimport) __stdcall PrikaziOAplikaciji();
extern "C" bool __declspec(dllimport) __stdcall PrikaziPotvrduBrisanja(const wchar_t* naslov);
