#include "Covek.h"
#include <iostream>
#include <string>

using namespace std;

Covek::Covek(){};

Covek::Covek(string ime,string prezime,string adresa,string telefon){
    this->ime=ime;
    this->prezime=prezime;
    this->adresa=adresa;
    this->telefon=telefon;
}

string Covek::getIme(){
    return ime;
}

string Covek::getPrezime(){
    return prezime;
}
string Covek::getAdresa(){
    return adresa;
}

string Covek::getTeleforn(){
    return telefon;
}

void Covek::ispecatiCovek() const{
    cout<<"Ime: "<<ime;
    cout<<"Prezime: "<<prezime;
    cout<<"Adresa: "<<adresa;
    cout<<"Telefon: "<<telefon;
}

