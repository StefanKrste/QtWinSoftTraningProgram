#ifndef C_CICACI_H
#define C_CICACI_H

#include "Zivotno.h"

class Cicaci : Zivotno{
private:
    char prezivar;
public:
    static int brojCicaci;
    char getTip();
    Cicaci();
    Cicaci(char Pol_in, string Ime_in, int datum_raganje_den, int datum_raganje_mesec, int datum_raganje_godina,
          int datum_donesuvanje_den, int datum_donesuvanje_mesec, int datum_donesuvanje_godina, int datum_vakciniranje_den,
          int datum_vakciniranje_mesec, int ,char prezivar);
    void Prikazi_Podatoci();
    virtual bool Presmetaj_vakcinacija();
};

#endif
