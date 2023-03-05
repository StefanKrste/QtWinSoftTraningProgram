#include <iostream>
#include <string>
#include "Zivotno.h"

using namespace std;

Zivotno::Zivotno() : Datum_na_ragjanje() , Datum_na_donesuvanje_vo_zoo(),Datum_na_posledna_vakcinacija() {}

Zivotno::Zivotno(char Pol_in, string Ime_in, int datum_raganje_den, int datum_raganje_mesec, int datum_raganje_godina,
                 int datum_donesuvanje_den, int datum_donesuvanje_mesec, int datum_donesuvanje_godina, int datum_vakciniranje_den,
                 int datum_vakciniranje_mesec, int datum_vakciniranje_godina) :
        Datum_na_ragjanje(datum_raganje_den, datum_raganje_mesec, datum_raganje_godina),
        Datum_na_donesuvanje_vo_zoo(datum_donesuvanje_den, datum_donesuvanje_mesec, datum_donesuvanje_godina),
        Datum_na_posledna_vakcinacija(datum_vakciniranje_den, datum_vakciniranje_mesec, datum_vakciniranje_godina){

    if(Pol_in == 'm' || Pol_in == 'z'){
        Pol=Pol_in;
    } else{
        Pol='m';
        cout<<"Vnesovte nevaliden vlez: "<<Pol_in<<" ,polot ke se postavi na m";
    }
    Ime=Ime_in;
}

Datum Zivotno::getDatumNaVakcinacija(){
    return this->Datum_na_posledna_vakcinacija;
}

void Zivotno::Prikazi_Podatoci() {
    cout<<"\nIme: "<<Ime<<endl;
    if(Pol=='m') {
        cout << "Pol: Masko" << endl;
    }
    else {
        cout << "Pol: Zensko" << endl;
    }
    cout<<"Datum na raganje: ";
    Datum_na_ragjanje.ispecatiDatum();
    cout<<"Datum na donesuvanje vo zooloskata: ";
    Datum_na_donesuvanje_vo_zoo.ispecatiDatum();
    cout<<"Datum na posledna vakcinacija: ";
    Datum_na_posledna_vakcinacija.ispecatiDatum();
}

bool Zivotno::Presmetaj_vakcinacija() {
    return false;
}
