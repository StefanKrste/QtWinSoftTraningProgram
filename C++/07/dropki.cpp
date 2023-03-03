#include <iostream>

using namespace std;

#include "dropki.h"

int NZD(int a, int b){
    if (b == 0) {
        return a;
    }
    return NZD(b, a % b);
}

int NZS(int a, int b){
    return ((a*b)/NZD(a,b));
}

int Dropki::getBroitel(){
    return broitel;
}
int Dropki::getImenitel(){
    return imenitel;
}

Dropki::Dropki(){
    broitel=0;
    imenitel=1;
}

void Dropki::setDropki(int broitel1, int imenitel1){
    if(imenitel1!=0){
        broitel=broitel1;
        imenitel=imenitel1;
    }else{
        cout<<"Imenitelot treba da e razlicen od 0"<<endl;
    }
}

void Dropki::ispechati(){
    cout<<broitel<<"/"<<imenitel<<endl;
}

void Dropki::ispechatiRealenBroj(){
    cout<<"Dropkata kako realen broj e: "<<(float) broitel/imenitel<<endl;
}

Dropki Dropki::operator+(Dropki dropki){
    Dropki rez;
    int nzs_imeniteli = NZS(imenitel,dropki.getImenitel());
    int broitel1 = broitel * (nzs_imeniteli/imenitel);
    int broitel2 = dropki.getBroitel() * (nzs_imeniteli/dropki.getImenitel());
    int suma_broitel = broitel1+broitel2;
    rez.broitel=suma_broitel / NZD(suma_broitel, nzs_imeniteli);
    rez.imenitel=nzs_imeniteli / NZD(suma_broitel, nzs_imeniteli);
    return rez;
}

Dropki Dropki::operator-(Dropki dropki){
    Dropki rez;
    int nzs_imeniteli = NZS(imenitel,dropki.getImenitel());
    int broitel1 = broitel * (nzs_imeniteli/imenitel);
    int broitel2 = dropki.getBroitel() * (nzs_imeniteli/dropki.getImenitel());
    int suma_broitel = broitel1-broitel2;
    rez.broitel=suma_broitel / NZD(suma_broitel, nzs_imeniteli);
    rez.imenitel=nzs_imeniteli / NZD(suma_broitel, nzs_imeniteli);
    return rez;
}

Dropki Dropki::operator*(Dropki dropki){
    Dropki rez;
    int rez_broitel = broitel*dropki.getBroitel();
    int rez_imenitel = imenitel*dropki.getImenitel();
    rez.broitel=rez_broitel/ NZD(rez_broitel, rez_imenitel);
    rez.imenitel=rez_imenitel/ NZD(rez_broitel, rez_imenitel);
    return rez;
}

Dropki Dropki::operator/(Dropki dropki){
    Dropki rez;
    int rez_broitel = broitel*dropki.getImenitel();
    int rez_imenitel = imenitel*dropki.getBroitel();
    rez.broitel=rez_broitel/ NZD(rez_broitel, rez_imenitel);
    rez.imenitel=rez_imenitel/ NZD(rez_broitel, rez_imenitel);
    return rez;
}

Dropki Dropki::operator+(int broj){
    Dropki rez;
    int nzs_imeniteli = NZS(imenitel,1);
    int broitel1 = broitel * (nzs_imeniteli/imenitel);
    int broitel2 = broj * nzs_imeniteli;
    int suma_broitel = broitel1+broitel2;
    rez.broitel=suma_broitel / NZD(suma_broitel, nzs_imeniteli);
    rez.imenitel=nzs_imeniteli / NZD(suma_broitel, nzs_imeniteli);
    return rez;
}

Dropki Dropki::operator-(int broj){
    Dropki rez;
    int nzs_imeniteli = NZS(imenitel,1);
    int broitel1 = broitel * (nzs_imeniteli/imenitel);
    int broitel2 = broj * nzs_imeniteli;
    int suma_broitel = broitel1-broitel2;
    rez.broitel=suma_broitel / NZD(suma_broitel, nzs_imeniteli);
    rez.imenitel=nzs_imeniteli / NZD(suma_broitel, nzs_imeniteli);
    return rez;
}

Dropki Dropki::operator*(int broj){
    Dropki rez;
    int rez_broitel = broitel*broj;
    rez.broitel=rez_broitel/ NZD(rez_broitel, imenitel);
    rez.imenitel=imenitel/ NZD(rez_broitel, imenitel);
    return rez;
}

Dropki Dropki::operator/(int broj){
    Dropki rez;
    int rez_imenitel = imenitel*broj;
    rez.broitel=broitel/ NZD(broitel, rez_imenitel);
    rez.imenitel=rez_imenitel/ NZD(broitel, rez_imenitel);
    return rez;
}
