#include <iostream>
#include "Vlekaci.h"
#include "Ptici.h"
#include "Cicaci.h"

using namespace std;

int main(){

    //Во една зоолошка градина се води евиденција за животните кои се чуваат во неа: птици, влекачи и цицачи. Користејќи ги концептите на ООП да се моделираат соодветни класи според спецификациите дадени на слика 1. Цицачите се вакцинираат секоја година, птиците на секои 6 месеци, а за влекачите овој податок варира. Во main() функцијата да се конструира низа од долунаведените класи (влекачи, птици и цицачи) и да се имплементира кориснички посредник преку мени со следните опции:
    //1.	Додавање на животно во листата
    //2.	Прикажување на бројна состојба
    //3.	Прикажување на животни од дадена група
    //4.	Прикажување на целата листа
    //5.	Прикажување на сите животни кои треба да се вакцинираат во рок од 1 недела
    //6.	Излез од менито

    int opcija;
    string ime;
    char pol,tip;
    int dat_raganje_den,dat_raganje_mesec,dat_raganje_godina;
    int dat_donesuvanje_den,dat_donesuvanje_mesec,dat_donesuvanje_god;
    int dat_vakcinacija_den,dat_vakcinacija_mesec,dat_vakcinacija_god;
    int sledna_vakcinacija_den,sledna_vakcinacija_mesec,sledna_vakcinacija_god;
    Vlekaci vlekaci[50];
    Cicaci cicaci[50];
    Ptici ptici[50];
    char let_pre;

    while(true) {
        cout<<"\n----------------------------------------\n";
        cout<<"Vnesi izbor:\n"
              "1 Dodadi zivotno vo zooloska\n"
              "2 Prikazi broj na zivotni vo zooloska\n"
              "3 Prikazi zivotni od dadena grupa\n"
              "4 Prikazi gi site zivotni\n"
              "5 Prikazi gi site koj treba da se vakciniraat vo rok od 1 nedela\n"
              "6 za kraj.\n";
        cin >> opcija;

        switch(opcija){
            case 1:
                cout<<"Vnesete tipot na zivotnot (c-cichac v-vlekac p-ptica): ";
                cin>>tip;
                if(tip=='c' || tip=='v' || tip=='p') {
                    cout << "Vnesete go ime na zivotnoto: ";
                    cin >> ime;
                    cout << "Vnesete go polot na zivotnot (m/z): ";
                    cin >> pol;
                    cout << "Vnesete datum na raganje (d/m/g): ";
                    cin >> dat_raganje_den;
                    cin >> dat_raganje_mesec;
                    cin >> dat_raganje_godina;
                    cout << "Vnesete datum na donesuvanje vo zooloskata (d/m/g): ";
                    cin >> dat_donesuvanje_den;
                    cin >> dat_donesuvanje_mesec;
                    cin >> dat_donesuvanje_god;
                    cout << "Vnesete datum na posledna vakcinacija (d/m/g): ";
                    cin >> dat_vakcinacija_den;
                    cin >> dat_vakcinacija_mesec;
                    cin >> dat_vakcinacija_god;
                    if(tip=='v') {
                        cout << "Vnesete datum na sledna vakcinacija (d/m/g): ";
                        cin >> sledna_vakcinacija_den;
                        cin >> sledna_vakcinacija_mesec;
                        cin >> sledna_vakcinacija_god;
                        Vlekaci *vlekaci1 = new Vlekaci(pol,ime,dat_raganje_den,dat_raganje_mesec,dat_raganje_godina
                        ,dat_donesuvanje_den,dat_donesuvanje_mesec,dat_donesuvanje_god
                        ,dat_vakcinacija_den,dat_vakcinacija_mesec,dat_vakcinacija_god
                        ,sledna_vakcinacija_den,sledna_vakcinacija_mesec,sledna_vakcinacija_god);
                        vlekaci[Vlekaci::brojVlekaci-1] = *vlekaci1;
                    } else if(tip=='p'){
                        cout << "Vnesete dali pticata leta (d/n): ";
                        cin >> let_pre;
                        Ptici *ptici1 = new Ptici(pol,ime,dat_raganje_den,dat_raganje_mesec,dat_raganje_godina
                                ,dat_donesuvanje_den,dat_donesuvanje_mesec,dat_donesuvanje_god
                                ,dat_vakcinacija_den,dat_vakcinacija_mesec,dat_vakcinacija_god
                                ,let_pre);
                        ptici[Ptici::brojPtici-1] = *ptici1;
                    } else{
                        cout << "Vnesete dali cicacot e prezivar (d/n): ";
                        cin >> let_pre;
                        Cicaci *cicaci1 = new Cicaci(pol,ime,dat_raganje_den,dat_raganje_mesec,dat_raganje_godina
                                ,dat_donesuvanje_den,dat_donesuvanje_mesec,dat_donesuvanje_god
                                ,dat_vakcinacija_den,dat_vakcinacija_mesec,dat_vakcinacija_god
                                ,let_pre);
                        cicaci[Cicaci::brojCicaci-1] = *cicaci1;
                    }
                } else {
                    cout<<"Gresen vlez";
                }
                break;
            case 2:
                cout<<"Monentalno ima "<< (Cicaci::brojCicaci+Ptici::brojPtici+Vlekaci::brojVlekaci) <<" zivotno vo zooloskata";
                break;
            case 3:
                cout<<"Vnesete od koj grupa na zivotni sakata da vi bide prikazano(c-cichac v-vlekac p-ptica): ";
                cin>>tip;
                if(tip=='v'){
                    for(int i = 0; i < Vlekaci::brojVlekaci; i++){
                        vlekaci[i].Prikazi_Podatoci();
                    }
                } else if (tip=='p'){
                    for(int i = 0; i < Ptici::brojPtici; i++){
                        ptici[i].Prikazi_Podatoci();
                    }
                } else if (tip=='c'){
                    for(int i = 0; i < Cicaci::brojCicaci; i++){
                        cicaci[i].Prikazi_Podatoci();
                    }
                } else {
                    cout<<"Vnesovte greshen vlez";
                    break;
                }
                break;
            case 4:
                for(int i = 0; i < Vlekaci::brojVlekaci; i++){
                    vlekaci[i].Prikazi_Podatoci();
                }
                for(int i = 0; i < Ptici::brojPtici; i++){
                    ptici[i].Prikazi_Podatoci();
                }
                for(int i = 0; i < Cicaci::brojCicaci; i++){
                    cicaci[i].Prikazi_Podatoci();
                }
                break;
            case 5:
                cout<<"Lista na zivotni koj treba da se vakciniraat vo rok od edna nedela: ";
                for(int i = 0; i < Vlekaci::brojVlekaci; i++){
                    if(vlekaci[i].Presmetaj_vakcinacija()) {
                        vlekaci[i].Prikazi_Podatoci();
                    }
                }
                for(int i = 0; i < Ptici::brojPtici; i++){
                    if(ptici[i].Presmetaj_vakcinacija()) {
                        ptici[i].Prikazi_Podatoci();
                    }
                }
                for(int i = 0; i < Cicaci::brojCicaci; i++){
                    if(cicaci[i].Presmetaj_vakcinacija()) {
                        cicaci[i].Prikazi_Podatoci();
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