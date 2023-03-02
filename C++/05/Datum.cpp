#include <iostream>
#include "Datum.h"

using namespace std;

int proveriDen( int den_in, int mesec_in, int godina_in  ){
    static const int daysPerMonth[ 13 ] =
            {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ( den_in > 0 && den_in <= daysPerMonth[ mesec_in ] )
        return den_in;
    if ( mesec_in == 2 && den_in == 29 && ( godina_in % 400 == 0 || ( godina_in % 4 == 0 && godina_in % 100 != 0 ) ) )
        return den_in;
    cout << "Denot " << den_in << " e greshen. Postavi vrednost za day na 1.\n";
    return 1;
}

Datum::Datum(){}

Datum::Datum( int den_in, int mesec_in, int godina1 ) {
    if (mesec_in > 0 && mesec_in <= 12)
        mesec = mesec_in;
    else {
        mesec = 1;
        cout << "Mesec " << mesec_in << " ne postoi. Postavi go month na 1.\n";
    }
    godina = godina1;
    den = proveriDen(den_in,mesec,godina);
}

int Datum::getDen(){
    return this->den;
}

int Datum::getMesec(){
    return this->mesec;
}

int Datum::getGodina(){
    return this->godina;
}

void Datum::ispecatiDatum() const {
    cout << den << '/' << mesec << '/' << godina <<endl;
}
