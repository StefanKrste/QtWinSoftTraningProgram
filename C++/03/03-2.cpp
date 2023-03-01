#include <iostream>
#include <list>

using namespace std;



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

    //2. Да се направи програма која ќе ја користи класата Штедач и ќе овозможи:
    //a)	Внесување на нов штедач во системот
    //b)	Приказ на податоците
    //c)	Уплата на средства
    //d)	Исплата на средства (со контрола дали е можна таква исплата)
    //e)	Приказ на салдото за даден штедач

    list<Stedac> lista;
    int opcija,broj;
    Stedac stedac;
    unsigned long vrednost;

    while(true) {
        cout<<"\nVnesi izbor:\n"
              "1 Kreiraj nov stedac i vnesi gi negovite podatoci\n"
              "2 Prikazi podatoci za site\n"
              "3 Uplata na sredstava za izbran stedac\n"
              "4 Isplata na sredstava za izbran stedac\n"
              "5 Prikaz na saldo na daden stedac\n"
              "6 za kraj.\n";

        cin >> opcija;
        switch(opcija){
            case 1:
                stedac.vnesi_podatoci(lista.size()+1);
                lista.push_back(stedac);
                break;
            case 2:
                for(auto i=lista.begin(); i!=lista.end(); ++i){
                    i->prikazi_podatoci();
                }
                break;
            case 3:
                cout<<"Vnesete broj na stedac na koj sakate da mu gi uplatite sredstvata: ";
                cin >> broj;
                cout<<"Vnesete vrednost za uplata: ";
                cin >> vrednost;
                for(auto i=lista.begin(); i!=lista.end(); ++i){
                    if(i->get_broj()==broj){
                        i->uplata(vrednost);
                        cout<<"Uspesno e napravena uplata";
                    }
                }
                break;
            case 4:
                cout<<"Vnesete broj na stedac na of koj sakate da izvrsite isplata: ";
                cin >> broj;
                cout<<"Vnesete vrednost za isplata: ";
                cin >> vrednost;
                for(auto i=lista.begin(); i!=lista.end(); ++i){
                    if(i->get_broj()==broj){
                        i->isplata(vrednost);
                    }
                }
                break;
            case 5:
                cout<<"Vnesete broj na stedac na koj sakate da ja videte sostojbata: ";
                cin >> broj;
                for(auto i=lista.begin(); i!=lista.end(); ++i){
                    if(i->get_broj()==broj){
                        cout<<"Sostojbata e:" << i->sostojba();
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

    return 0;
}