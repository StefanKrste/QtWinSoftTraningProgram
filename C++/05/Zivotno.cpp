#include <iostream>
#include <string>
#include <ctime>
#include "Zivotno.h"

using namespace std;

Zivotno::Zivotno() : Datum_na_ragjanje() , Datum_na_donesuvanje_vo_zoo(),Datum_na_posledna_vakcinacija() {}

Zivotno::Zivotno(char tip_in, char Pol_in, string Ime_in, int datum_raganje_den, int datum_raganje_mesec, int datum_raganje_godina,
                 int datum_donesuvanje_den, int datum_donesuvanje_mesec, int datum_donesuvanje_godina, int datum_vakciniranje_den,
                 int datum_vakciniranje_mesec, int datum_vakciniranje_godina) :
        Datum_na_ragjanje(datum_raganje_den, datum_raganje_mesec, datum_raganje_godina),
        Datum_na_donesuvanje_vo_zoo(datum_donesuvanje_den, datum_donesuvanje_mesec, datum_donesuvanje_godina),
        Datum_na_posledna_vakcinacija(datum_vakciniranje_den, datum_vakciniranje_mesec, datum_vakciniranje_godina){

    if(tip_in == 'c' || tip_in == 'v' || tip_in == 'p'){
        tip=tip_in;
    } else{
        tip='c';
        cout<<"Vnesovte nevaliden vlez: "<<tip_in<<" ,tipot ke se postavi na c";
    }

    if(Pol_in == 'm' || Pol_in == 'z'){
        Pol=Pol_in;
    } else{
        Pol='m';
        cout<<"Vnesovte nevaliden vlez: "<<Pol_in<<" ,polot ke se postavi na m";
    }

    Ime=Ime_in;
}

char Zivotno::getTip() {
    return tip;
}

void Zivotno::Prikazi_Podatoci() {
    cout<<"Ime: "<<Ime<<endl;
    if(Pol=='m') {
        cout << "Pol: Masko" << endl;
    }
    else {
        cout << "Pol: Zensko" << endl;
    }
    if(tip=='c') {
        cout << "Tip: Cichac" << endl;
    }else if(tip=='v') {
        cout << "Tip: Vlekach" << endl;
    }else{
        cout << "Tip: Ptica" << endl;
    }
    cout<<"Datum na raganje: ";
    Datum_na_ragjanje.ispecatiDatum();
    cout<<"Datum na donesuvanje vo zooloskata: ";
    Datum_na_donesuvanje_vo_zoo.ispecatiDatum();
    cout<<"Datum na posledna vakcinacija: ";
    Datum_na_posledna_vakcinacija.ispecatiDatum();
}

bool Zivotno::Presmetaj_vakcinacija() {
    time_t now = time(0);

    tm tm{};
    tm.tm_year = Datum_na_posledna_vakcinacija.getGodina()-1900;
    tm.tm_mon = Datum_na_posledna_vakcinacija.getMesec()-1;
    tm.tm_mday = Datum_na_posledna_vakcinacija.getDen()-7;
    //za da proveram koj treba vo narednata nedela na site im odzemame 7 dena od poslednata vakcinacija
    time_t datum_na_vakcinacija = mktime(&tm); //tm->time_t

    if(tip=='c'){
        if(difftime(now, datum_na_vakcinacija)>=(365*24*60*60)){
            return true;
        }
    }else if(tip=='p'){
        if(difftime(now, datum_na_vakcinacija)>=((365/2)*24*60*60)){
            return true;
        }
    }else{
        if(difftime(now, datum_na_vakcinacija)>=((365/12)*8*24*60*60)){
            return true;
        }
    }
    return false;
}
