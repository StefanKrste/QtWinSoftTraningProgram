#ifndef C_COVEK_H
#define C_COVEK_H

#include "string"

using namespace std;

class Covek{
private:
    string ime;
    string prezime;
    string adresa;
    string telefon;
public:
    Covek();
    Covek(string ime,string prezime,string adresa,string telefon);
    string getIme();
    string getPrezime();
    string getAdresa();
    string getTeleforn();
    void ispecatiCovek() const;
};

#endif
