#include <iostream>

using namespace std;

template< class T >
class Lica{
    string imeiprezime;
    long long int mat_br;
    int vozrast;
    string adresa;
    T kod;
public:
    Lica();
    Lica(string, long long int, int, string ,T);
    string getImeprezime();
    long long int getMatBr();
    int getVozrast();
    string getAdreda();
    T getKod();
};

template< class T >
Lica<T>::Lica(){};

template< class T >
Lica<T>::Lica(string imeiprezime, long long int mat_br, int vozrast, string adresa,T kod){
    this->imeiprezime=imeiprezime;
    this->mat_br=mat_br;
    this->vozrast=vozrast;
    this->adresa=adresa;
    this->kod=kod;
};

template< class T >
string Lica<T>::getImeprezime(){
    return imeiprezime;
}

template< class T >
long long int Lica<T>::getMatBr(){
    return mat_br;
}

template< class T >
int Lica<T>::getVozrast(){
    return vozrast;
}

template< class T >
string Lica<T>::getAdreda(){
    return adresa;
}

template< class T >
T Lica<T>::getKod(){
    return kod;
}

//----------------------------------------------------------------------------------------------------------------------

template<class T>
void pecatiPole(T* niza, int dolzina){
    for(int i=0; i<dolzina; i++){
        cout<<"-------------------"<<endl;
        cout<<"Ime i prezime: "<<niza[i].getImeprezime()<<endl;
        cout<<"Adresa: "<<niza[i].getAdreda()<<endl;
        cout<<"Vozrast: "<<niza[i].getVozrast()<<endl;
        cout<<"Matichen broj: "<<niza[i].getMatBr()<<endl;
        cout<<"Kod: "<<niza[i].getKod()<<endl;
    }
    cout<<endl;
}

int main(){

    //3. Една фирма води евиденција за лица кои можат да бидат вработени или клиенти. За секое лице се чуваат следните податоци:  imeiprezime, mat_br, vozrast, adresa, kod. За вработените kod има целобројна вредност, а за клиентите е низа од знаци.
    //Креирај class template Lica во која ќе се сместуваат податоците за лица. Податоците кои се низи од знаци да се внесуваат преку динамичка алокација на меморија. Креирај две полиња од објекти, Vraboteni и Klienti. За печатење на двете полиња употреби ја pecatiPole од претходната задача.
    //Напиши тест програма која содржи мени:
    //
    //1.      Внесување на податоци за вработен
    //2.      Внесување на податоци за клиент
    //3.      Печетење на листа на вработени
    //4.      Печатење на листа на клиенти
    //5.      Крај

    int opcija;

    Lica <int> vraboteni[50];
    Lica <string> klienti[50];
    string ime,adresa,kodString;
    int vozrast,kodInt;
    int brVraboteni=0,brKlienti=0;
    long long int matBr;

    while(true) {
        cout<<"\nVnesi izbor:\n"
              "1 Vnesuvanje podatoci za vraboten\n"
              "2 Vnesuvanje podatoci ca klient\n"
              "3 Pechatenje na lista na vraboten\n"
              "4 Pecatenje na lista na klienti\n"
              "5 Kraj\n";
        cin >> opcija;

        switch(opcija){
            case 1:
                cout<<"Vnesete podatoci: ";
                cout<<"Ime i prezime: ";
                cin.ignore();
                getline(cin, ime);
                cout<<"Adresa: ";
                cin.ignore();
                getline(cin, adresa);
                cout<<"Vozrast: ";
                cin>>vozrast;
                cout<<"Matichen broj: ";
                cin>>matBr;
                cout<<"Kod: ";
                cin>>kodInt;
                vraboteni[brVraboteni] = Lica(ime,matBr,vozrast,adresa,kodInt);
                brVraboteni++;
                break;
            case 2:
                cout<<"Vnesete podatoci: ";
                cout<<"Ime i prezime: ";
                cin>>ime;
                cout<<"Adresa: ";
                cin>>adresa;
                cout<<"Vozrast: ";
                cin>>vozrast;
                cout<<"Matichen broj: ";
                cin>>matBr;
                cout<<"Kod: ";
                cin>>kodString;
                klienti[brKlienti] = Lica(ime,matBr,vozrast,adresa,kodString);
                brKlienti++;
                break;
            case 3:
                pecatiPole(vraboteni,brVraboteni);
                break;
            case 4:
                pecatiPole(klienti,brKlienti);
                break;
            case 5:
                return 0;
            default:
                printf("Greshen izbor\n");
                break;
        }
    }
}
