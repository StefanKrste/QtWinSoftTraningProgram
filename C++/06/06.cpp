#include <iostream>
#include <string>
#include "Stedac.h"

using namespace std;

int main () {

    //1. Создади класа Stedac во која ќе користиш статичка податочна членка kamata која ќе ја чува вредноста на годишната камата за сите штедачи и статична податочна членка brojStedaci кој во секој момент кажува колку штедачи има во банката. Останатите податочни членки се lice, bilans и kredit. Името, презимето, адресата и телефонот на секој објeкт од класата Stedac  се сместени во приватна податочна членка lice која е од класaта Covek.

    Stedac *stedac1 = new Stedac ("Stefan","Krstevski","Moja Adresa","Moj Tel",1000000,0);

    stedac1->ispecatiStedac();

    cout<<"Momentalno ima "<<Stedac::getStedaci()<<" stedaci"<<endl;

    Stedac *stedac2 = new Stedac ("StefanCopy","KrstevskiCopy","Moja AdresaCopy","Moj TelCopy",5000,5000);

    stedac1->ispecatiStedac();

    cout<<"Momentalno ima "<<Stedac::getStedaci()<<" stedaci"<<endl;

    delete stedac1;
    delete stedac2;

    return 0;
}

