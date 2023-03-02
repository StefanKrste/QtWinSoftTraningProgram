#ifndef C_ZIVOTNO_H
#define C_ZIVOTNO_H

#include "Datum.h"
#include <string>

using namespace std;

class Zivotno{
private:
    Datum Datum_na_ragjanje;
    Datum Datum_na_donesuvanje_vo_zoo;
    char tip;
    char Pol;
    string Ime;
    Datum Datum_na_posledna_vakcinacija;
public:
    char getTip();
    Zivotno();
    Zivotno(char tip_in, char Pol_in, string Ime_in, int datum_raganje_den, int datum_raganje_mesec, int datum_raganje_godina,
            int datum_donesuvanje_den, int datum_donesuvanje_mesec, int datum_donesuvanje_godina, int datum_vakciniranje_den,
            int datum_vakciniranje_mesec, int datum_vakciniranje_godina);
    void Prikazi_Podatoci();
    bool Presmetaj_vakcinacija();
};

#endif

