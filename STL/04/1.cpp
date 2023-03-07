#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Imenik{
public:
    string ime;
    string tel_broj;
    Imenik();
    Imenik(string ime, string tel_broj);
};

Imenik::Imenik() {}

Imenik::Imenik(string ime, string tel_broj) {
    this->ime=ime;
    this->tel_broj=tel_broj;
}

int main(){

    //1. Напиши класа Imenik којa содржи ime и tel_broj. Креирај телефонски именик користејќи контејнер vector.   Прикажи го именикот во абецеден редослед.

    vector< Imenik > telImenik;
    Imenik imenik1 = Imenik("Stefan" , "070111000");
    telImenik.push_back(imenik1);
    imenik1 = Imenik("Marko" , "070222000");
    telImenik.push_back(imenik1);
    imenik1 = Imenik("Pero" , "070333000");
    telImenik.push_back(imenik1);
    imenik1 = Imenik("Kire" , "070444000");
    telImenik.push_back(imenik1);
    imenik1 = Imenik("Mile" , "070555000");
    telImenik.push_back(imenik1);
    sort( telImenik.begin(), telImenik.end(),[](Imenik x, Imenik y){
        return x.ime < y.ime;
    });
    vector< Imenik >::iterator i;
    for ( i = telImenik.begin(); i != telImenik.end(); ++i )
        cout << i->ime << " " << i->tel_broj << "\n";

    return 0;
}
