#ifndef C_PTICI_H
#define C_PTICI_H

#include "Zivotno.h"

class Ptici : Zivotno{
private:
    char letac;
public:
    static int brojPtici;
    char getTip();
    Ptici();
    Ptici(char Pol_in, string Ime_in, int datum_raganje_den, int datum_raganje_mesec, int datum_raganje_godina,
            int datum_donesuvanje_den, int datum_donesuvanje_mesec, int datum_donesuvanje_godina, int datum_vakciniranje_den,
            int datum_vakciniranje_mesec, int datum_vakciniranje_godina, char letac);
    void Prikazi_Podatoci();
    virtual bool Presmetaj_vakcinacija();
};

#endif
