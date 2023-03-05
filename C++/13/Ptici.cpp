#include "Ptici.h"
#include <iostream>
using namespace std;

int Ptici::brojPtici = 0;

Ptici::Ptici() {}

Ptici::Ptici(char Pol_in, string Ime_in, int datum_raganje_den, int datum_raganje_mesec, int datum_raganje_godina,
                 int datum_donesuvanje_den, int datum_donesuvanje_mesec, int datum_donesuvanje_godina, int datum_vakciniranje_den,
                 int datum_vakciniranje_mesec, int datum_vakciniranje_godina,char letac) :
        Zivotno(Pol_in, Ime_in, datum_raganje_den, datum_raganje_mesec, datum_raganje_godina, datum_donesuvanje_den, datum_donesuvanje_mesec,
                datum_donesuvanje_godina, datum_vakciniranje_den,datum_vakciniranje_mesec, datum_vakciniranje_godina){
    this->letac=letac;
    brojPtici++;
}

void Ptici::Prikazi_Podatoci() {
    Zivotno::Prikazi_Podatoci();
    cout<<"Letach: ";
    if(letac=='d'){
        cout<<"DA";
    } else{
        cout<<"NE";
    }
}

bool Ptici::Presmetaj_vakcinacija() {
    time_t now = time(0);
    struct tm posledna_vakcinacija;

    posledna_vakcinacija.tm_year = getDatumNaVakcinacija().getGodina()-1900;
    posledna_vakcinacija.tm_mon = getDatumNaVakcinacija().getMesec()-1;
    posledna_vakcinacija.tm_mday = getDatumNaVakcinacija().getDen()-7;
    posledna_vakcinacija.tm_hour = 0;
    posledna_vakcinacija.tm_min = 0;
    posledna_vakcinacija.tm_sec = 0;
    //za da proveram koj treba vo narednata nedela na site im odzemame 7 dena od poslednata vakcinacija
    time_t datum_na_vakcinacija = mktime(&posledna_vakcinacija); //tm->time_t

    if(difftime(now, datum_na_vakcinacija)>=((365/2)*24*60*60)){
        return true;
    }

    return false;
}