#include <iostream>
#include <vector>
#include <fstream>
#include <numeric>
#include <algorithm>

using namespace std;

class Invertar{
    int id;
    int kol;
    double cena;
public:
    Invertar();
    Invertar(int, int, double);
    double getCena();
    int getKol();
    int getId();
};

Invertar::Invertar() {}

Invertar::Invertar(int id, int kol, double cena) {
    this->id=id;
    this->kol=kol;
    this->cena=cena;
}

double Invertar::getCena() {
    return cena;
}

int Invertar::getKol() {
    return kol;
}
int Invertar::getId() {
    return id;
}


bool sortKol(Invertar& i1, Invertar& i2) {
    return i1.getKol() < i2.getKol();
}

int main(){

    //2. Во еден магацин се води евиденција за артикли. Во текстуална датотека inventar.txt се чуваат следните податоци за секој артикл: инвентарен број (int), количество (int) и цена (double) за секој артикл.  Креирај класа Inventar која содржи id, kolicestvo и cena.  Напиши програма во која се создава vector од артикли, а потоа прикажува вкупна вредност на артиклите во магацинот и листа на сите артикли за кои количеството е помало од 10. Пресметувањето на вкупната вредност и прикажувањето на артиклите изврши го со STL алгоритми. Ако не постои влезна датотека, програмата да фрли исклучок.

    vector<Invertar> invertar;
    ifstream file_in;
    string zbor;
    Invertar invertar1;
    int id;
    int kol;
    double cena;
    double vkupnaCena;

    file_in.open("inventar.txt");
    if (!file_in){
        throw logic_error("Fajlot nemoze da se otvori");
    }

    while (file_in >> id >> kol >> cena){
        invertar1 = Invertar(id,kol,cena);
        invertar.push_back(invertar1);
    }

    vkupnaCena = accumulate(invertar.begin(), invertar.end(), 0.0,
                            [](double total, Invertar& i) {
                                return total + i.getCena();
                            });
    cout<<"Vkupnata vrednost na artiklite e: "<<vkupnaCena<<endl;

    sort(invertar.begin(), invertar.end(), sortKol);

    cout<<"Artiklite so kol pomala od 10: "<<endl;
    for (auto x : invertar) {
        if(x.getKol()>10){
            break;
        }
        cout<<"ID: "<<x.getId()<<"  Kol: "<<x.getKol()<<"  Cena: "<<x.getCena()<<endl;
    }

    file_in.close();


    return 0;
}