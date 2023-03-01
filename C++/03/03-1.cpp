#include <iostream>
#include <list>

using namespace std;

class Kvadar{
  int a;
  int b;
  int c;
public:
    void set();
    double getDolzhina() { return a; }
    double getShirina() { return b; }
    double getVisina() { return c; }
    double Ploshtina() {return 2*(getDolzhina()*getShirina()+getShirina()*getVisina()+getDolzhina()*getVisina());}
    double Volumen() {return getDolzhina()*getShirina()*getVisina();}
    void Print();
};

void Kvadar::set () {
    cout<<"Dolzhina=";
    cin>>a;
    cout<<"Shirina=";
    cin>>b;
    cout<<"Visina=";
    cin>>c;
}

void Kvadar::Print(){
    cout<<"Dolzina="<<getDolzhina()<<
        " Shirina="<<getShirina()<<
        " Visina="<<getVisina()<<endl;
}

class Stedac
{
public:
    int get_broj() {return broj;}
    void vnesi_podatoci(int broj);
    void prikazi_podatoci();
    void uplata(unsigned long i) {saldo+=i;}
    void isplata(unsigned long i);
    long sostojba(){return saldo;}

private:
    int broj;
    char imeprezime[30], adresa[50];
    long saldo;
};

void Stedac::vnesi_podatoci (int br) {
    broj=br;
    cout<<"Ime i prezime=";
    std::cin >> std::ws;
    std::cin.getline(imeprezime, 30);
    cout<<"Adresa=";
    std::cin >> std::ws;
    std::cin.getline(adresa, 50);
    cout<<"Saldo=";
    cin>>saldo;
}

void Stedac::prikazi_podatoci(){
    cout<<"Broj="<<broj<<
        " Ime i prezime="<<imeprezime<<
        " Adresa="<<adresa<<endl;
}

void Stedac::isplata(unsigned long i){
    if(i>saldo){
        cout<<"Nemate dovolno sredstva";
    } else{
        saldo-=i;
        cout<<"Uspesno e napravena isplata";
    }
}

int main() {

    //1. Да се формира класа Квадар (скриени елементи: должина, ширина и висина; јавни функции: плоштина, волумен). Од неа да се имплементира поле од објекти. Да се најде оној кој има најмала плоштина, а не е коцка. Да се креира мени:
    //a)	Креирај нов објект
    //b)	Постави ги димензиите
    //c)	Печати ги димензиите на сите објекти
    //d)	Печати ги димензиите за поедин објект
    //e)	Печати ги оние кои го задоволуваат условот

    int broj,opcija;
    double MaxP;
    list<Kvadar> lista;
    Kvadar kvadar;

    while(true) {
        cout<<"\nVnesi izbor:\n"
              "1 Kreiraj nov objekt i vnesi gi negovite dimenzii\n"
              "2 Pechati gi dimenziite za site objekti.\n"
              "3 Pechati gi dimenziite za poedin objekti.\n"
              "4 Pechati gi onie koi go zadovoluvaat uslovot.\n"
              "5 za kraj.\n";
        cin >> opcija;
        auto i = lista.begin();
        MaxP=0;
        switch(opcija){
            case 1:
                kvadar.set();
                lista.push_back(kvadar);
                break;
            case 2:
                for(i=lista.begin(); i!=lista.end(); ++i){
                    i->Print();
                }
                break;
            case 3:
                cout << "Vnesete go redniot broj na kvadratot koj sakate da go pecatite: ";
                cin >> broj;
                if (broj > lista.size()) {
                    cout << "Brojot e pogolem od brojot na elementi vo listata" << endl;
                    break;
                }
                std::advance(i, broj-1);
                i->Print();
                break;
            case 4:
                for(i=lista.begin(); i!=lista.end(); i++){
                    if((i->getDolzhina() != i->getShirina() || i->getShirina() != i->getVisina()) && MaxP < i->Ploshtina()) {
                        MaxP = kvadar.Ploshtina();
                    }
                }
                if(MaxP!=0) {
                    for (i = lista.begin(); i != lista.end(); i++) {
                        if ((i->getDolzhina() != i->getShirina() || i->getShirina() != i->getVisina()) && MaxP > i->Ploshtina()) {
                            kvadar = *i;
                            MaxP = kvadar.Ploshtina();
                        }
                    }
                    cout << "Kvadarot koj ima najmala plostina a ne e koca ima dimenzii\n";
                    kvadar.Print();
                    cout << "I plostina: " << kvadar.Ploshtina();
                } else{
                    cout << "Nikoj ne go zadovoluva uslovot";
                }
                break;
            case 5:
                return 0;
            default:
                printf("Greshen izbor\n");
                break;
        }
    }

    return 0;
}