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