#include <iostream>
#include "Datum.h"

using namespace std;

//----------------------------------------------------------------------------------------------------------------------

class Artikl {
    string Ime_na_artikl;
    string Golemina;
    float Cena;
    Datum Donesen_vo_prodavnica;
public:
    Artikl();
    Artikl(string Ime_na_artikl, string Golemina, float Cena, int denNabavka, int mesecNabavka, int godinaNabavka);
    void Prikazi_Podatoci_Artikl();
    float getCena();
};

Artikl::Artikl() {}

Artikl::Artikl(string Ime_na_artikl, string Golemina, float Cena, int denNabavka, int mesecNabavka, int godinaNabavka) : Donesen_vo_prodavnica(denNabavka, mesecNabavka, godinaNabavka){
    this->Ime_na_artikl=Ime_na_artikl;
    this->Golemina=Golemina;
    this->Cena=Cena;
}

float Artikl::getCena() {
    return Cena;
}

void Artikl::Prikazi_Podatoci_Artikl(){
    cout<<"Ime na artiklot: "<< Ime_na_artikl << endl;
    cout<<"Golemina: "<< Golemina << endl;
    cout<<"Cena: "<< Cena << endl;
    cout<<"Datum donesen vo prodavnica: ";
    Donesen_vo_prodavnica.ispecatiDatum();
}

//----------------------------------------------------------------------------------------------------------------------

class Pantaloni: public Artikl {
    Datum Donesen_na_sledna_nabavka;
public:
    static int brojPantaloni;
    Pantaloni();
    Pantaloni(string Ime_na_artikl, string Golemina, float Cena, int denNabavka, int mesecNabavka, int godinaNabavka, int denDonesen, int mesecDonesen, int godinaDonesen);
    void Prikazi_Podatoci_Pantaloni();
    float Presmetaj_nabavka();
};

Pantaloni::Pantaloni() {}

int Pantaloni::brojPantaloni=0;

Pantaloni::Pantaloni(string Ime_na_artikl, string Golemina, float Cena, int denNabavka, int mesecNabavka, int godinaNabavka, int denDonesen, int mesecDonesen, int godinaDonesen) :
Donesen_na_sledna_nabavka(denDonesen, mesecDonesen, godinaDonesen),
Artikl(Ime_na_artikl, Golemina, Cena, denNabavka, mesecNabavka, godinaNabavka){
    brojPantaloni++;
}

void Pantaloni::Prikazi_Podatoci_Pantaloni(){
    Prikazi_Podatoci_Artikl();
    cout<<"Datum na sledna nabavka: ";
    Donesen_na_sledna_nabavka.ispecatiDatum();
}

float Pantaloni::Presmetaj_nabavka() {
    time_t now = time(0);

    tm tm{};
    tm.tm_year = Donesen_na_sledna_nabavka.getGodina()-1900;
    tm.tm_mon = Donesen_na_sledna_nabavka.getMesec()-1;
    tm.tm_mday = Donesen_na_sledna_nabavka.getDen()-7;
    //za da proveram koj treba vo narednata nedela na site im odzemame 7 dena od datumot na sledna nabavka
    time_t datum_na_nabavka = mktime(&tm); //tm->time_t

    if(datum_na_nabavka < now){
        Prikazi_Podatoci_Pantaloni();
        return getCena();
    } else{
        return 0;
    }
}

//----------------------------------------------------------------------------------------------------------------------

class Kosuli: public Artikl {
public:
    static int brojKosuli;
    Kosuli();
    Kosuli(string Ime_na_artikl, string Golemina, float Cena, int denNabavka, int mesecNabavka, int godinaNabavka);
    void Prikazi_Podatoci_Kosuli();
};

Kosuli::Kosuli() {}

int Kosuli::brojKosuli=0;

Kosuli::Kosuli(string Ime_na_artikl, string Golemina, float Cena, int denNabavka, int mesecNabavka, int godinaNabavka) :
        Artikl(Ime_na_artikl, Golemina, Cena, denNabavka, mesecNabavka, godinaNabavka){
    brojKosuli++;
}

void Kosuli::Prikazi_Podatoci_Kosuli(){
    Prikazi_Podatoci_Artikl();
}

//----------------------------------------------------------------------------------------------------------------------

int main(){

    //1. Во една продавница се води евиденција за артиклите кои се продаваат во неа: пантолони и кошули. Користејќи ги концептите на ООП да се моделираат соодветни класи според спецификациите дадени на сликата. Пратката на пантолони доаѓа секој месец, а нарачки на кошули се прават по потреба. Во main() функцијата да се конструира низа од долунаведените класи (пантолони, кошули) и да се имплементира кориснички посредник преку мени со следните опции:
    //      1.  Додавање на артикл во листата
    //      2.  Прикажување на артикли од дадена група
    //      3.  Прикажување на целата листа (со вкупна цена)
    //      4.  Прикажување на сите артикли кои треба да се набават во рок од 1 недела и пари кои треба да се потрошат за да се набават потребните артикли
    //      5.  Излез од менито
    // Приватната членка Donesen_vo_prodavnica е од тип Datum кој треба да се дефинира во посебна класа.

    int opcija;
    Pantaloni pantaloni[50];
    Kosuli kosuli[50];
    char tip;
    string ime,golemina;
    float cena=0;
    int denD,mesecD,godinaD;
    int denN,mesecN,godinaN;

    while(true) {
        cout << "\nVnesi izbor:\n"
                "1 Dodavanje na artikl vo listata\n"
                "2 Prikazi artikl od dadena grupa\n"
                "3 Prikazi ja cela lista\n"
                "4 Prikazi gi site artikli koj treba da se nabavat vo rok od 1 nedela i vkupniot iznos za taa nabavka\n"
                "5 Kraj\n";
        cin >> opcija;
        cena=0;
        switch (opcija) {
            case 1:
                cout<<"Vnesete vnesete go tipot na artiklot (p-pantaloni, k-kosuli)";
                cin>>tip;
                if(tip=='p' || tip=='k'){
                    cout<<"Ime na artiklot: ";
                    cin>>ime;
                    cout<<"Golemina: ";
                    cin>>golemina;
                    cout<<"Cena: ";
                    cin>>cena;
                    cout<<"Datum na donesuvanje vo prodavnica (den mesec godina): ";
                    cin>>denD; cin>>mesecD; cin>>godinaD;
                    if(tip=='p'){
                        cout<<"Datum na sledna nabavka (den mesec godina): ";
                        cin>>denN; cin>>mesecN; cin>>godinaN;
                        Pantaloni *pantaloni1 = new Pantaloni(ime,golemina,cena,denD,mesecD,godinaD,denN,mesecN,godinaN);
                        pantaloni[Pantaloni::brojPantaloni-1] = *pantaloni1;
                    } else {
                        Kosuli *kosuli1 = new Kosuli(ime,golemina,cena,denD,mesecD,godinaD);
                        kosuli[Kosuli::brojKosuli-1] = *kosuli1;
                    }
                }else {
                    cout<<"Vnesovte greshen vlez";
                    break;
                }
                cout<<"Uspesno vnesovte nov artikl"<<endl;
                break;
            case 2:
                cout<<"Vnesete vnesete go tipot na artiklot (p-pantaloni, k-kosuli)";
                cin>>tip;
                if(tip=='p'){
                    if(Pantaloni::brojPantaloni==0){
                        cout<<"Nema pantaloni vo prodavnicata";
                        break;
                    }
                    for(int i = 0; i < Pantaloni::brojPantaloni; i++){
                        pantaloni[i].Prikazi_Podatoci_Pantaloni();
                    }
                } else if (tip=='k'){
                    if(Kosuli::brojKosuli==0){
                        cout<<"Nema kosuli vo prodavnicata";
                        break;
                    }
                    for(int i = 0; i < Kosuli::brojKosuli; i++){
                        kosuli[i].Prikazi_Podatoci_Kosuli();
                    }
                } else {
                    cout<<"Vnesovte greshen vlez";
                    break;
                }
                break;
            case 3:
                cout<<"Site artikli";
                if(Pantaloni::brojPantaloni==0 && Kosuli::brojKosuli==0){
                    cout<<"Nema artikli vo prodavnicata";
                    break;
                }
                for(int i = 0; i < Pantaloni::brojPantaloni; i++){
                    pantaloni[i].Prikazi_Podatoci_Pantaloni();
                    cena+=pantaloni[i].getCena();
                }
                for(int i = 0; i < Kosuli::brojKosuli; i++){
                    kosuli[i].Prikazi_Podatoci_Kosuli();
                    cena+=pantaloni[i].getCena();
                }
                cout<<"\nVKUPNATA CENA E: "<<cena<<endl;
                break;
            case 4:
                //Vo zadacata pisuva deka pratka od pantaloni doaga sekoj mesec (a isto taka imame i datum na sledn nabaska)
                //Taka da jas ke idam so sporedba na datumite dali denesniot datum epomal od datumot na sledna naracka + 7 dena
                //Za kosulite neznam kako bi presmetal poradi toa sto nema datum i vika se naracuvaat po potreba znaci samo za pantalonite ke e kejsov
                cout << "Artiklite koj treba da se nabavat vo tekot na narednata nedela se: ";
                for(int i = 0; i < Pantaloni::brojPantaloni; i++){
                    cena+=pantaloni[i].Presmetaj_nabavka();
                }
                cout<<"Nivniot vkupen iznos iznesuva: "<< cena << endl;
                break;
            case 5:
                return 0;
            default:
                printf("Greshen izbor\n");
                break;
        }
    }
}