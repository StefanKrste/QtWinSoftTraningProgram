#include <iostream>
#include <map>

using namespace std;

class Uplata{
    string imePrezime;
    double uplata;
public:
    Uplata();
    Uplata(string, double);
    double getuplata();
};

Uplata::Uplata(){}

Uplata::Uplata(string imePrezime, double uplata){
    this->imePrezime=imePrezime;
    this->uplata=uplata;
}

double Uplata::getuplata() {
    return uplata;
}

typedef multimap<string, Uplata, less<string>> mmid;

int main(){

    //1.  Во една банка пристигаат уплати за штедачи. Напиши програма во која ќе се внесуваат податоци за уплати и ќе се прикажува листа и вкупна уплата за даден штедач. Импламентирај класа Uplata која содржи податоци за штедач и големина на уплата. Користи контејнер multimap. Програмата треба да овозможува едноставно мени за внесување и прикажување на уплати.
    //      1.      Додај уплата
    //      2.      Прикажи уплати за даден штедач
    //      3.      Крај

    int opcija;
    string imePrezime;
    double uplata,vkupno=0;

    mmid Uplati;

    while(true) {
        cout<<"\nVnesi izbor:\n"
              "1 Dodadi uplata\n"
              "2 Prikazi uplata za daden stedac\n"
              "3 Kraj\n";
        cin >> opcija;
        vkupno=0;

        switch(opcija){
            case 1:
                cout<<"Vnesete ime i prezime: ";
                cin.ignore();
                getline(cin,imePrezime);
                cout<<"Dodadi ja uplatata: ";
                cin>>uplata;
                Uplati.insert(make_pair(imePrezime, Uplata(imePrezime,uplata)));
                break;
            case 2:
                cout << "Vnesete ime i prezime: ";
                cin.ignore();
                getline(cin, imePrezime);
                for(auto x : Uplati){
                    if(x.first == imePrezime){
                        vkupno+=x.second.getuplata();
                    }
                }
                cout << "Vkupno uplati: " << vkupno << endl;
                break;
            case 3:
                return 0;
            default:
                printf("Greshen izbor\n");
                break;
        }
    }
}