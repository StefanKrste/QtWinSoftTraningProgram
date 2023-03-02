#include <iostream>
#include <list>
#include <string>
#include "Zivotno.h"

using namespace std;

int main () {

    //1. Во една зоолошка градина се води евиденција за различни типови животни кои се чуваат во неа: птици, влекачи, цицачи.... Користејќи ги концептите на ООП да се моделира класа според спецификациите дадени на слика 5.1. Цицачите се вакцинираат секоја година, птиците на секои 6 месеци, а влекачите на секои 8 месеци. Датумите да се дефинираат во посебна класа Datum со приватни податочни членки den, mesec и godina. Да се имплементира кориснички посредник преку мени со следните опции:
    //  1.	Додавање на животно во зоолошка градина
    //  2.	Прикажување на бројна состојба
    //  3.	Прикажување на животни од дадена група (тип: c- цицачи, v-влекачи, p-птици)
    //  4.	Прикажување на целата листа
    //  5.	Прикажување на сите животни кои треба да се вакцинираат во рок од 1 недела
    //  6.	Излез од менито
    //Klasa: Zivotno
    //Podatoci:
    //Datum_na_ragjanje
    //Datum_na_donesuvawe_vo_zoo
    //tip
    //Pol (m/z)
    //Ime
    //Datum_na_posledna_vakcinacija
    //Metodi:
    //Konstruktor()
    //Prikazi_Podatoci()
    //Presmetaj_vakcinacija()

    int opcija;
    string ime;
    char pol,tip;
    int dat_raganje_den,dat_raganje_mesec,dat_raganje_godina;
    int dat_donesuvanje_den,dat_donesuvanje_mesec,dat_donesuvanje_god;
    int dat_vakcinacija_den,dat_vakcinacija_mesec,dat_vakcinacija_god;
    list<Zivotno> lista;
    Zivotno zivotno;

    while(true) {
        cout<<"\nVnesi izbor:\n"
              "1 Dodadi zivotno vo zooloska\n"
              "2 Prikazi broj na zivotni vo zooloska\n"
              "3 Prikazi zivotni od dadena grupa\n"
              "4 Prikazi gi site zivotni\n"
              "5 Prikazi gi site koj treba da se vakciniraat vo rok od 1 nedela\n"
              "6 za kraj.\n";
        cin >> opcija;

        switch(opcija){
            case 1:
                cout<<"Vnesete go ime na zivotnoto: ";
                cin>>ime;
                cout<<"Vnesete go polot na zivotnot (m/z): ";
                cin>>pol;
                cout<<"Vnesete tipot na zivotnot (c-cichac v-vlekac p-ptica): ";
                cin>>tip;
                cout<<"Vnesete datum na raganje (d/m/g): ";
                cin>>dat_raganje_den;
                cin>>dat_raganje_mesec;
                cin>>dat_raganje_godina;
                cout<<"Vnesete datum na donesuvanje vo zooloskata (d/m/g): ";
                cin>>dat_donesuvanje_den;
                cin>>dat_donesuvanje_mesec;
                cin>>dat_donesuvanje_god;
                cout<<"Vnesete datum na posledna vakcinacija (d/m/g): ";
                cin>>dat_vakcinacija_den;
                cin>>dat_vakcinacija_mesec;
                cin>>dat_vakcinacija_god;

                zivotno = Zivotno(tip,pol,ime,dat_raganje_den,dat_raganje_mesec,
                                  dat_raganje_godina,dat_donesuvanje_den,dat_donesuvanje_mesec,
                                  dat_donesuvanje_god,dat_vakcinacija_den,dat_vakcinacija_mesec,
                                  dat_vakcinacija_god);

                lista.push_back(zivotno);
                break;
            case 2:
                cout<<"Monentalno ima "<< lista.size() <<"zivotno vo zooloskata";
                break;
            case 3:
                cout<<"Vnesete od koj grupa na zivotni sakata da vi bide prikazano(c-cichac v-vlekac p-ptica): ";
                cin>>tip;
                for(auto i=lista.begin(); i!=lista.end(); i++){
                    if(i->getTip()==tip) {
                        i->Prikazi_Podatoci();
                    }
                }
                break;
            case 4:
                for(auto i=lista.begin(); i!=lista.end(); i++){
                        i->Prikazi_Podatoci();
                }
                break;
            case 5:
                cout<<"Lista na zivotni koj treba da se vakciniraat vo rok od edna nedela: ";
                for(auto i=lista.begin(); i!=lista.end(); i++){
                    if(i->Presmetaj_vakcinacija()){
                        i->Prikazi_Podatoci();
                    }
                }
                break;
            case 6:
                return 0;
            default:
                printf("Greshen izbor\n");
                break;
        }
    }
}
