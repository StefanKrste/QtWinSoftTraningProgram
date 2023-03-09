#include <iostream>
#include <vector>

using namespace std;

class Bukva{
    char bukva;
    bool pogodok;
public:
    Bukva();
    Bukva(char, bool);
    char getBukva();
    bool getPogodok();
    void setBukva(char);
    void setPogodok(bool);
};

Bukva::Bukva() {}

Bukva::Bukva(char bukva, bool pogodok) {
    this->bukva=bukva;
    this->pogodok=pogodok;
}

char Bukva::getBukva(){
    return bukva;
}

bool Bukva::getPogodok(){
    return pogodok;
}

void Bukva::setBukva(char bukva){
    this->bukva=bukva;
}

void Bukva::setPogodok(bool pogodok){
    this->pogodok=pogodok;
}

int main(){

    //2. Напиши програма за играње на играта ’бесилка’. Креирај класа која содржи char и bool за индикација дали знак веќе бил погоден. Одбери збор и вчитај го во вектор со објекти од таа класа. Менувањето и прикажувањето на елементите од векторот изврши го со STL алгоритми. Играчот во циклус внесува збор кој смее да се состои само од мали букви. Ако зборот содржи и други знаци програмата да фрли исклучок. За секој збор се прикажуваат знаците што ги погодил и знак ’-’ за знаците што сеуште не ги погодил. Користи бројач на погодувања. Играчот победува ако го погоди зборот пред бројачот да добие вредност 0.

    vector<Bukva> zbor;
    char bukva;
    zbor.push_back(Bukva('m', false));
    zbor.push_back(Bukva('o', false));
    zbor.push_back(Bukva('r', false));
    zbor.push_back(Bukva('k', false));
    zbor.push_back(Bukva('o', false));
    zbor.push_back(Bukva('v', false));

    bool igra=true;
    int brojach = 10;
    cout<<"Preostanati shansi za pogodok: "<<brojach<<endl;
    while(igra){
        cout<<"Vnesete bukva (samo mali bukvi): ";
        cin>>bukva;
        if(!islower(bukva))
            throw logic_error("Vnesena e karakter koj ne e mala bukva");

        for (auto& x : zbor) {
            if (x.getBukva() == bukva) {
                x.setPogodok(true);
            }
        }
        cout<<endl;
        igra= false;
        for(auto x : zbor){
            if(x.getPogodok()){
                cout<<x.getBukva();
            } else{
                cout<<"_";
                igra= true;
            }
        }
        brojach--;
        cout<<endl;
        cout<<"Preostanati shansi za pogodok: "<<brojach<<endl;
        if(brojach==0){
            cout<<"Igrata zavrsi poradi toa sto gi iskoristivte sansite za pogodok"<<endl;
            igra=false;
        }
    }
    return 0;
}