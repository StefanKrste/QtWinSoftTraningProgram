#include <iostream>
#include "dropki.h"

using namespace std;

int main (){

    //1. Создади класа Dropki која извршува операции со дропки. Напиши „драјвер“ за твојот програм да манипулира со оваа класа.
    //Користи целоборјни променливи за броител и именител кои мора да се приватни. Обезбеди потребен број на контруктори кои нема да дозволат дефинирање на грешни вредности (со 0 не се дели!). По секоја од наредните операции, дропката треба да се зачува во редуцирана форма, т.е дропката 2/4 треба да се зачува како 1/2. Обезбеди ги следните јавни функции членки:
    //	а) Собирање на два објекти од класа Dropki. Резултатот да се даде во редуцирана форма.
    //	б) Одземање на два објекти од класа Dropki. Резултатот да се даде во редуцирана форма
    //	в) Множење на два објекти од класа Dropki. Резултатот да се даде во редуцирана форма
    //	г) Делење на два објекти од класа Dropki. Резултатот да се даде во редуцирана форма
    //	д) Печатење на објектот во форма a/b.
    //	ѓ) Печатење на објектот во форма на реален број.

    Dropki dropki1,dropki2;
    int broitel,imenitel;

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

    dropki1.sobiranje(dropki2);
    dropki1.odzemanje(dropki2);
    dropki1.mnozenje(dropki2);
    dropki1.delenje(dropki2);

    return 0;
}