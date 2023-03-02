#include "Stedac.h"
#include <iostream>
#include <string>

using namespace std;

Stedac::Stedac(){};

int Stedac::brojStedaci=0;
int Stedac::kamata=0;

Stedac::~Stedac(){
    cout<<"Broj na stedaci po povikuvanje na destruktorot (brisenjeto) "<<--brojStedaci<<endl;
}

Stedac::Stedac(string ime, string prezime, string adresa, string telefon , int bilans, int kredit) : lice(ime, prezime, adresa, telefon){
    this->bilans=bilans;
    this->kredit=kredit;
    brojStedaci++;
}

int Stedac::getKamata(){
    return kamata;
}

int Stedac::getStedaci(){
    return brojStedaci;
}

Covek Stedac::getLice(){
    return lice;
}

int Stedac::getBilans(){
    return bilans;
}

int Stedac::getKredit(){
    return kredit;
}

void Stedac::ispecatiStedac(){
    cout<<"Ime: "<<lice.getIme()<<" Prezime: "<<lice.getPrezime()<<endl;
    cout<<"Adresa: "<<lice.getAdresa()<<" Telefon: "<<lice.getTeleforn()<<endl;
    cout<<"Bilans: "<<bilans<<" Kredit: "<<kredit<<endl;
}
