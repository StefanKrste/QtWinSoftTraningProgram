#include "Vlekaci.h"
#include <iostream>
using namespace std;

int Vlekaci::brojVlekaci = 0;

Vlekaci::Vlekaci() : Datum_na_sledna_vakcinacija() {}

Vlekaci::Vlekaci(char Pol_in, string Ime_in, int datum_raganje_den, int datum_raganje_mesec, int datum_raganje_godina,
                 int datum_donesuvanje_den, int datum_donesuvanje_mesec, int datum_donesuvanje_godina, int datum_vakciniranje_den,
                 int datum_vakciniranje_mesec, int datum_vakciniranje_godina,int sledna_vakciniranje_den,
                 int sledna_vakciniranje_mesec, int sledna_vakciniranje_godina) :
        Datum_na_sledna_vakcinacija( sledna_vakciniranje_den, sledna_vakciniranje_mesec, sledna_vakciniranje_godina),
        Zivotno(Pol_in, Ime_in, datum_raganje_den, datum_raganje_mesec, datum_raganje_godina, datum_donesuvanje_den, datum_donesuvanje_mesec,
                datum_donesuvanje_godina, datum_vakciniranje_den,datum_vakciniranje_mesec, datum_vakciniranje_godina){
    brojVlekaci++;
}

void Vlekaci::Prikazi_Podatoci() {
    Zivotno::Prikazi_Podatoci();
    cout<<"Datum na sledna vakcinacija: ";
    Datum_na_sledna_vakcinacija.ispecatiDatum();
}

bool Vlekaci::Presmetaj_vakcinacija() {
    time_t now = time(0);

    tm tm{};
    tm.tm_year = Datum_na_sledna_vakcinacija.getGodina()-1900;
    tm.tm_mon = Datum_na_sledna_vakcinacija.getMesec()-1;
    tm.tm_mday = Datum_na_sledna_vakcinacija.getDen()-7;
    //za da proveram koj treba vo narednata nedela na site im odzemame 7 dena od poslednata vakcinacija
    time_t datum_sledna_vakcinacija = mktime(&tm); //tm->time_t

    if(datum_sledna_vakcinacija < now){
        return true;
    }
    return false;
}