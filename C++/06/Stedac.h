#ifndef C_STEDAC_H
#define C_STEDAC_H

#include "string"
#include "Covek.h"

using namespace std;

class Stedac{
private:
    static int kamata;
    static int brojStedaci;
    Covek lice;
    int bilans;
    int kredit;
public:
    Stedac();
    ~Stedac();
    Stedac(string ime, string prezime, string adresa, string telefon , int bilans, int kredit);
    static int getKamata();
    static int getStedaci();
    Covek getLice();
    int getBilans();
    int getKredit();
    void ispecatiStedac();
};

#endif
