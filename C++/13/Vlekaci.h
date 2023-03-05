#ifndef C_VLEKACI_H
#define C_VLEKACI_H

#include "Datum.h"
#include "Zivotno.h"

class Vlekaci : Zivotno{
private:
    Datum Datum_na_sledna_vakcinacija;
public:
    static int brojVlekaci;
    char getTip();
    Vlekaci();
    Vlekaci(char Pol_in, string Ime_in, int datum_raganje_den, int datum_raganje_mesec, int datum_raganje_godina,
            int datum_donesuvanje_den, int datum_donesuvanje_mesec, int datum_donesuvanje_godina, int datum_vakciniranje_den,
            int datum_vakciniranje_mesec, int datum_vakciniranje_godina,int sledna_vakciniranje_den,
            int sledna_vakciniranje_mesec, int sledna_vakciniranje_godina);
    void Prikazi_Podatoci();
    virtual bool Presmetaj_vakcinacija();
};

#endif