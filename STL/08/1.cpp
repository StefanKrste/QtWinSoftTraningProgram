#include <iostream>
#include <list>
#include <numeric>

using namespace std;

class Vraboten{
    string ime;
    int bodobi;
public:
    Vraboten();
    Vraboten(string,int);
    string getIme();
    int getBodovi();
};

Vraboten::Vraboten(string ime, int bodobi) {
    this->ime=ime;
    this->bodobi=bodobi;
}

string Vraboten::getIme() {
    return ime;
}

int Vraboten::getBodovi() {
    return bodobi;
}

int main(){

    //1. Во една фирма платата на вработените се пресметува како производ од број на бодови и вредност на бод. Вредноста на бодот е иста за сите вработени.Имплементирај класа Vraboten која содржи податочни членови ime и bodovi. Напиши програма со која ќе се пресмета вкупната сума за да се исплати месечна плата за целата фирма. Програмата треба да ја прикаже вкупната сума и список на вработените сортиран според бројот на бодови. За пресметување на сумата да се употреби accumulate. За сортирање на листата да се употреби sort.

    list<Vraboten> lista;
    int vrednostNaBod = 51, vkupno=0;
    Vraboten vraboten1 = Vraboten("Stefan",100);
    Vraboten vraboten2 = Vraboten("Marko",150);
    Vraboten vraboten3 = Vraboten("Risto",10);
    Vraboten vraboten4 = Vraboten("Mirko",105);
    Vraboten vraboten5 = Vraboten("Pero",135);
    Vraboten vraboten6 = Vraboten("Kiro",140);

    lista.push_back(vraboten1);
    lista.push_back(vraboten2);
    lista.push_back(vraboten3);
    lista.push_back(vraboten4);
    lista.push_back(vraboten5);
    lista.push_back(vraboten6);

    cout<<"Vo firmata ima: "<<lista.size()<< " vraboteni"<<endl;

    lista.sort([](Vraboten& v1, Vraboten& v2) {
        return v1.getBodovi() > v2.getBodovi();
    });

    for (auto x : lista) {
        cout<<"Ime: "<<x.getIme()<<"  Bodovi: "<<x.getBodovi()<<endl;
    }

    vkupno = accumulate(lista.begin(), lista.end(), 0, [&](int a, Vraboten& v) {
        return a + v.getBodovi() * vrednostNaBod;
    });

    cout<<"Vkupnata plata na site vraboteni e: "<<vkupno<<endl;
    return 0;
}