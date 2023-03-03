#include <iostream>
#include "dropki.h"

using namespace std;

int main () {

    //1. Создади класа Dropki која извршува операции со дропки. Напиши „драјвер“ за твојот програм да манипулира со оваа класа.
    //
    //Користи целоборјни променливи за броител и именител кои мора да се приватни. Обезбеди потребен број на контруктори кои нема да дозволат дефинирање на грешни вредности (со 0 не се дели). По секоја од наредните операции, дропката треба да се зачува во редуцирана форма, т.е дропката 2/4 треба да се зачува како 1/2. Обезбеди ги следните операторски функции членки:
    //	а) Собирање на два објекти од класа Dropki. Резултатот да се даде во редуцирана форма.
    //	б) Одземање на два објекти од класа Dropki. Резултатот да се даде во редуцирана форма
    //	в) Множење на два објекти од класа Dropki. Резултатот да се даде во редуцирана форма
    //	г) Делење на два објекти од класа Dropki. Резултатот да се даде во редуцирана форма
    //	д) Собирање на објект од  класа Dropki со цел број. Резултатот да се даде во редуцирана форма.
    //	ѓ) Одземање на објект од  класа Dropki со цел број. Резултатот да се даде во редуцирана форма.
    //	е) Множење на објект од  класа Dropki со цел број. Резултатот да се даде во редуцирана форма.
    //	ж) Делење на објект од  класа Dropki со цел број. Резултатот да се даде во редуцирана форма.
    //
    //Да се обезбедат и следните функции членки на класата:
    //	з) Печатење на објектот во форма a/b.
    //	ѕ) Печатење на објектот во форма на реален број.

    Dropki dropki1,dropki2,rez;
    int broitel,imenitel,broj;

    cout<<"Vnesi ja prvata dropka: ";
    cout<<"Broitel=";
    cin>>broitel;
    cout<<"Imenitel=";
    cin>>imenitel;
    dropki1.setDropki(broitel,imenitel);
    cout<<"Vnesenata dropka e: ";
    dropki1.ispechati();
    dropki1.ispechatiRealenBroj();

    cout<<"Vnesi ja vtorata dropka: ";
    cout<<"Broitel=";
    cin>>broitel;
    cout<<"Imenitel=";
    cin>>imenitel;
    dropki2.setDropki(broitel,imenitel);
    cout<<"Vnesenata dropka e: ";
    dropki2.ispechati();
    dropki2.ispechatiRealenBroj();

    cout<<"Rezultati so preimena na preklopuvanje na operatori: ";
    rez=dropki1+dropki2;
    cout<<"\nSobiranje rez: ";
    rez.ispechati();
    rez=dropki1-dropki2;
    cout<<"\nOzdemanje rez: ";
    rez.ispechati();
    rez=dropki1*dropki2;
    cout<<"\nMnozenje rez: ";
    rez.ispechati();
    rez=dropki1/dropki2;
    cout<<"\nDelenje rez: ";
    rez.ispechati();

    cout<<"\nRezultati so preimena na preklopuvanje na operatori so cel broj: ";
    cout<<"\nVnesete cel broj so koj ke se napravat operacii na prvata dropka: ";
    cin>>broj;
    rez=dropki1+broj;
    cout<<"\nSobiranje rez: ";
    rez.ispechati();
    rez=dropki1-broj;
    cout<<"\nOzdemanje rez: ";
    rez.ispechati();
    rez=dropki1*broj;
    cout<<"\nMnozenje rez: ";
    rez.ispechati();
    rez=dropki1/broj;
    cout<<"\nDelenje rez: ";
    rez.ispechati();

    return 0;
}