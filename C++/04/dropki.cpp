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

void Dropki::sobiranje(Dropki dropki){
    int nzs_imeniteli = NZS(imenitel,dropki.getImenitel());
    int broitel1 = broitel * (nzs_imeniteli/imenitel);
    int broitel2 = dropki.getBroitel() * (nzs_imeniteli/dropki.getImenitel());
    int suma_broitel = broitel1+broitel2;
    cout<<"Rzultatot od sobiranjeto e: "<<suma_broitel / NZD(suma_broitel, nzs_imeniteli)<<"/"<<nzs_imeniteli / NZD(suma_broitel, nzs_imeniteli)<<endl;
}

void Dropki::odzemanje (Dropki dropki){
    int nzs_imeniteli = NZS(imenitel,dropki.getImenitel());
    int broitel1 = broitel * (nzs_imeniteli/imenitel);
    int broitel2 = dropki.getBroitel() * (nzs_imeniteli/dropki.getImenitel());
    int suma_broitel = broitel1-broitel2;
    cout<<"Rzultatot od odzemanjeto e: "<<suma_broitel / NZD(suma_broitel, nzs_imeniteli)<<"/"<<nzs_imeniteli / NZD(suma_broitel, nzs_imeniteli)<<endl;
}

void Dropki::mnozenje (Dropki dropki){
    int rez_broitel = broitel*dropki.getBroitel();
    int rez_imenitel = imenitel*dropki.getImenitel();
    cout<<"Rzultatot od mnozenjeto e: "<<rez_broitel/ NZD(rez_broitel, rez_imenitel)<<"/"<<rez_imenitel/ NZD(rez_broitel, rez_imenitel)<<endl;
}

void Dropki::delenje (Dropki dropki){
    int rez_broitel = broitel*dropki.getImenitel();
    int rez_imenitel = imenitel*dropki.getBroitel();
    cout<<"Rzultatot od delenjeto e: "<<rez_broitel/ NZD(rez_broitel, rez_imenitel)<<"/"<<rez_imenitel/ NZD(rez_broitel, rez_imenitel)<<endl;
}

void Dropki::ispechati(){
    cout<<"Dropkata e: "<<broitel<<"/"<<imenitel<<endl;
}

void Dropki::ispechatiRealenBroj(){
    cout<<"Dropkata e: "<<(float) broitel/imenitel<<endl;
}
