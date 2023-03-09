#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <string>
#include <set>

using namespace std;

//----------------------------------------------------------------------------------------------------------------------

class Kvadrat{
    double strana;
public:
    Kvadrat(){strana=1;};
    Kvadrat(double);
    double getStrana();
    bool operator<(const Kvadrat &kvadrat) const { return strana < kvadrat.strana; }
};

Kvadrat::Kvadrat(double strana) {
    this->strana=strana;
}

double Kvadrat::getStrana(){
    return strana;
}

//----------------------------------------------------------------------------------------------------------------------

class Pravoagolnik{
    double strana;
    double dolzina;
public:
    Pravoagolnik(){strana=1;dolzina=1;};
    Pravoagolnik(double ,double);
    double getStrana();
    double getDolzina();
    bool operator<(const Pravoagolnik &pravoagolnik) const {
        if (strana == pravoagolnik.strana) {
            return dolzina < pravoagolnik.dolzina;
        }
        return strana < pravoagolnik.strana;
    }
};

Pravoagolnik::Pravoagolnik(double strana, double dolzina) {
    this->strana=strana;
    this->dolzina=dolzina;
}

double Pravoagolnik::getStrana() {
    return strana;
}

double Pravoagolnik::getDolzina(){
    return dolzina;
}

//----------------------------------------------------------------------------------------------------------------------



int main(){

    //1. Креирај класа Pravoagolnik која содржи double sirina и double dolzina, и класа Kvadrat која содржи double strana. Во две текстуални датотеки се сместени линии со чија содржина може да биде:
    //-	број 1 по кој следат два double броја
    //-	број 2 по кој следи еден double број.
    //Овие вредности треба да се вчитаат во програма и од нив да се создадат објекти. Ако првата вредност е 1 тогаш се создава Pravoagolnik чии димензии се двата броја што следуваат. Ако првата вредност е 2 тогаш се создава Kvadrat чија страна е бројот што следува.
    //На пример,
    //1 2.5 3.5
    //2 10.0
    //1 5 5
    //ќе значи дека ќе се создадат два правоаголника и еден квадрат.
    //Ако линија содржи вредности различни од пропишаните, програмата да генерира исклучок.
    //Определи ја унијата и пресекот на сите правоаголници и унијата и пресекот на сите квадрати што се дефинирани со датотеките.

    ifstream file_in1,file_in2;

    vector<Kvadrat> kvadrati1;
    vector<Kvadrat> kvadrati2;
    vector<Pravoagolnik> pravoagolnici1;
    vector<Pravoagolnik> pravoagolnici2;
    set<Kvadrat> unija_kvadrati;
    set<Pravoagolnik> unija_pravoagolnici;
    vector<Kvadrat> presek_kvadrati;
    vector<Pravoagolnik> presek_pravoagolnici;
    string zbor;
    double strana1;
    double strana2;
    string linija;

    file_in1.open("dat1.dat");
    if (!file_in1){
        throw logic_error("Fajlot nemoze da se otvori");
    }

    file_in2.open("dat2.dat");
    if (!file_in2){
        throw logic_error("Fajlot nemoze da se otvori");
    }

    while (getline(file_in1, linija)) {
        stringstream ss(linija);
        string zbor;
        ss >> zbor;
        if (stoi(zbor) == 1) {
            ss >> zbor;
            strana1 = stod(zbor);
            ss >> zbor;
            strana2 = stod(zbor);
            pravoagolnici1.push_back(Pravoagolnik(strana1,strana2));
        } else if (stoi(zbor) == 2) {
            ss >> zbor;
            strana1 = stod(zbor);
            kvadrati1.push_back(Kvadrat(strana1));
        } else {
            throw logic_error("vrednosta vo datotekata e razlicna od propisanata");
        }
    }

    while (getline(file_in2, linija)) {
        stringstream ss(linija);
        string zbor;
        ss >> zbor;
        if (stoi(zbor) == 1) {
            ss >> zbor;
            strana1 = stod(zbor);
            ss >> zbor;
            strana2 = stod(zbor);
            pravoagolnici2.push_back(Pravoagolnik(strana1,strana2));
        } else if (stoi(zbor) == 2) {
            ss >> zbor;
            strana1 = stod(zbor);
            kvadrati2.push_back(Kvadrat(strana1));
        } else {
            throw logic_error("vrednosta vo datotekata e razlicna od propisanata");
        }
    }

    file_in1.close();
    file_in2.close();

    for (int i = 0; i < kvadrati1.size(); i++) {
        unija_kvadrati.insert(kvadrati1[i]);
    }

    for (int i = 0; i < kvadrati2.size(); i++) {
        unija_kvadrati.insert(kvadrati2[i]);
    }

    for (int i = 0; i < pravoagolnici1.size(); i++) {
        unija_pravoagolnici.insert(pravoagolnici1[i]);
    }

    for (int i = 0; i < pravoagolnici2.size(); i++) {
        unija_pravoagolnici.insert(pravoagolnici2[i]);
    }

    cout << "Unijata na kvadratite e: ";
    for (auto x:unija_kvadrati) {
        cout << "(" << x.getStrana() << ") ";
    }
    cout << endl;

    cout << "Unijata na pravoagolnicite e: ";
    for (auto x:unija_pravoagolnici) {
        cout << "(" << x.getStrana() << " " << x.getDolzina() << ") ";
    }
    cout << endl;

    sort(kvadrati1.begin(), kvadrati1.end());
    sort(kvadrati2.begin(), kvadrati2.end());
    sort(pravoagolnici1.begin(), pravoagolnici1.end());
    sort(pravoagolnici2.begin(), pravoagolnici2.end());

    set_intersection(kvadrati1.begin(), kvadrati1.end(), kvadrati2.begin(), kvadrati2.end(),back_inserter(presek_kvadrati));
    set_intersection(pravoagolnici1.begin(), pravoagolnici1.end(), pravoagolnici2.begin(), pravoagolnici2.end(),back_inserter(presek_pravoagolnici));

    cout << "Presek na kvadratite e: ";
    for (auto x:presek_kvadrati) {
        cout << "(" << x.getStrana() << ") ";
    }
    cout << endl;

    cout << "Presek na pravoagolnicite e: ";
    for (auto x:presek_pravoagolnici) {
        cout << "(" << x.getStrana() << " " << x.getDolzina() << ") ";
    }
    cout << endl;


    return 0;
}