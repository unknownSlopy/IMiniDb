#ifndef StaticLibH
#define StaticLibH

#include <vcl.h>
#include <System.SysUtils.hpp>

class TOmdbParser
{
    public:
        int ParseTrajanje(AnsiString runtime);
        double ParseImdbRating(AnsiString rating);
};

double Radi();
void ShowUpisano(int upisano);

#endif
