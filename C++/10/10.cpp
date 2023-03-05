#include <iostream>
#include <cstring>

using namespace std;

class Vraboten {
    char *ime;
    char *prezime;
    int godina_na_vrabotuvanje;
public:
    Vraboten();
    Vraboten(char *ime, char *prezime, int dos_vrabotuvanje);
    Vraboten postavi_vraboten();
    void prikazi_podatoci_vraboten();
    char* get_ime() const;
    char* get_prezime() const;
    int get_godina_na_vrabotuvanje() const;
};

Vraboten::Vraboten() {};

Vraboten::Vraboten(char *ime, char *prezime, int god_vrabotuvanje) {
    this->ime = new char[strlen(ime)+1];
    strcpy(this->ime, ime);

    this->prezime = new char[strlen(prezime)+1];
    strcpy(this->prezime, prezime);

    this->godina_na_vrabotuvanje=god_vrabotuvanje;
}

char* Vraboten::get_ime() const {
    return ime;
}

char* Vraboten::get_prezime() const {
    return prezime;
}

int Vraboten::get_godina_na_vrabotuvanje() const {
    return godina_na_vrabotuvanje;
}


Vraboten Vraboten::postavi_vraboten(){
    char ime[50];
    cout<<"Ime: ";
    cin>>ime;
    char prezime[50];
    cout<<"Prezime: ";
    cin>>prezime;
    int godina_na_vrabotuvanje;
    cout<<"Godina na vrabotuvanuje: ";
    cin>>godina_na_vrabotuvanje;
    return Vraboten(ime,prezime,godina_na_vrabotuvanje);
}

void Vraboten::prikazi_podatoci_vraboten(){
    cout<<"-----------------"<<endl;
    cout<<"Ime: "<<ime<<endl;
    cout<<"Prezime: "<<prezime<<endl;
    cout<<"Godina na vrabotuvanuje: "<<godina_na_vrabotuvanje<<endl;
}

//----------------------------------------------------------------------------------------------------------------------

class Profesor : Vraboten {
    char *zvanje;
    char *oblast;
    int br_predmeti;
public:
    static int brojProfesori;
    Profesor();
    Profesor(char *ime, char *prezime, int god_vrabotuvanje, char *zvanje, char*oblast, int br_predmeti);
    Profesor postavi_profesor();
    void prikazi_podatoci_profesor();
};

Profesor::Profesor() {}

int Profesor::brojProfesori=0;

Profesor::Profesor(char *ime, char *prezime, int god_vrabotuvanje, char *zvanje, char*oblast, int br_predmeti) : Vraboten(ime, prezime, god_vrabotuvanje) {
    this->zvanje = new char[strlen(zvanje)+1];
    strcpy(this->zvanje, zvanje);

    this->oblast = new char[strlen(oblast)+1];
    strcpy(this->oblast, oblast);

    this->br_predmeti=br_predmeti;
    brojProfesori++;
}

Profesor Profesor::postavi_profesor(){
    Vraboten vraboten = postavi_vraboten();
    char zvanje[50];
    cout<<"\nZvanje: ";
    cin>>zvanje;
    char oblast[50];
    cout<<"Oblast: ";
    cin>>oblast;
    int br_predmeti;
    cout<<"Broj na predmeti: ";
    cin>>br_predmeti;
    return Profesor(vraboten.get_ime(),vraboten.get_prezime(),vraboten.get_godina_na_vrabotuvanje(),zvanje,oblast,br_predmeti);
}

void Profesor::prikazi_podatoci_profesor(){
    prikazi_podatoci_vraboten();
    cout<<"Zvanje: "<<zvanje<<endl;
    cout<<"Oblast: "<<oblast<<endl;
    cout<<"Broj na predmeti: "<<br_predmeti<<endl;
}

//----------------------------------------------------------------------------------------------------------------------

class Asistent : Vraboten{
    char *zvanje;
    char *mentor;
    int br_predmeti;
public:
    static int brojAsistenti;
    Asistent();
    Asistent(char *ime, char *prezime, int god_vrabotuvanje, char *zvanje, char*mentor, int br_predmeti);
    Asistent postavi_asistent();
    void prikazi_podatoci_asistent();
};

Asistent::Asistent() {}

int Asistent::brojAsistenti=0;

Asistent::Asistent(char *ime, char *prezime, int god_vrabotuvanje, char *zvanje, char*mentor, int br_predmeti) : Vraboten(ime, prezime, god_vrabotuvanje) {
    this->zvanje = new char[strlen(zvanje)+1];
    strcpy(this->zvanje, zvanje);

    this->mentor = new char[strlen(mentor)+1];
    strcpy(this->mentor, mentor);

    this->br_predmeti=br_predmeti;
    brojAsistenti++;
}

Asistent Asistent::postavi_asistent(){
    Vraboten vraboten = postavi_vraboten();
    char zvanje[50];
    cout<<"\nZvanje: ";
    cin>>zvanje;
    char mentor[50];
    cout<<"Oblast: ";
    cin>>mentor;
    int br_predmeti;
    cout<<"Broj na predmeti: ";
    cin>>br_predmeti;
    return Asistent(vraboten.get_ime(),vraboten.get_prezime(),vraboten.get_godina_na_vrabotuvanje(),zvanje,mentor,br_predmeti);
}

void Asistent::prikazi_podatoci_asistent(){
    prikazi_podatoci_vraboten();
    cout<<"Zvanje: "<<zvanje<<endl;
    cout<<"Mentor: "<<mentor<<endl;
    cout<<"Broj na predmeti: "<<br_predmeti<<endl;
}

//----------------------------------------------------------------------------------------------------------------------

class Demonstrator : Vraboten{
    int rabotno_vreme_od;
    int rabotno_vreme_do;
public:
    static int brojDenostratori;
    Demonstrator();
    Demonstrator(char *ime, char *prezime, int god_vrabotuvanje, int rabotno_vreme_od, int rabotno_vreme_do);
    Demonstrator postavi_demonstrator();
    void prikazi_podatoci_demonstrator();
};

Demonstrator::Demonstrator() {}

int Demonstrator::brojDenostratori=0;

Demonstrator::Demonstrator(char *ime, char *prezime, int god_vrabotuvanje, int rabotno_vreme_od, int rabotno_vreme_do) : Vraboten(ime, prezime, god_vrabotuvanje) {
    this->rabotno_vreme_od=rabotno_vreme_od;

    this->rabotno_vreme_do=rabotno_vreme_do;
    brojDenostratori++;
}

Demonstrator Demonstrator::postavi_demonstrator(){
    Vraboten vraboten = postavi_vraboten();
    int rabotno_vreme_od;
    cout<<"\nRabotno vreme od: ";
    cin>>rabotno_vreme_od;
    int rabotno_vreme_do;
    cout<<"Rabotno vreme do: ";
    cin>>rabotno_vreme_do;
    return Demonstrator(vraboten.get_ime(),vraboten.get_prezime(),vraboten.get_godina_na_vrabotuvanje(),rabotno_vreme_od,rabotno_vreme_do);
}

void Demonstrator::prikazi_podatoci_demonstrator(){
    prikazi_podatoci_vraboten();
    cout<<"Rabotno vreme od: "<<rabotno_vreme_od<<endl;
    cout<<"Rabotno vreme do: "<<rabotno_vreme_do<<endl;
}

//----------------------------------------------------------------------------------------------------------------------

int main () {

    //Користејќи ги концептите на ООП да се моделираат соодветни класи според спецификациите дадени на слика 1, а потоа во функцијата main() да се констуира низа со објекти од долунаведените класи (професор, асистент, демонстратор) и имплементира кориснички посредник преку мени со следните опции:
    //
    //1.    Додавање на нов вработен во листата
    //2.    Прикажување на листата
    //3.    Крај

    int opcija;
    char tip;

    Profesor profesor[50];
    Asistent asistent[50];
    Demonstrator demonstrator[50];

    while(true) {
        cout<<"\nVnesi izbor:\n"
              "1 Dodavanje na nov vraboten vo listata\n"
              "2 Prikazuvanje na listata\n"
              "3 Kraj\n";
        cin >> opcija;

        switch(opcija){
            case 1:
                cout<<"Vnesete pozicija na noviot vraboten (p-profesor, a-asistent, d-demonstrator)";
                cin>>tip;
                if(tip=='p'){
                    Profesor profesor1 = profesor1.postavi_profesor();
                    profesor[Profesor::brojProfesori-1] = profesor1;
                } else if (tip=='a'){
                    Asistent asistent1 = asistent1.postavi_asistent();
                    asistent[Asistent::brojAsistenti-1] = asistent1;
                } else if (tip=='d'){
                    Demonstrator demonstrator1 = demonstrator1.postavi_demonstrator();
                    demonstrator[Demonstrator::brojDenostratori-1] = demonstrator1;
                } else {
                    cout<<"Vnesovte greshen vlez";
                    break;
                }
                cout<<"Uspesno vnesovte nov vraboten"<<endl;
                break;
            case 2:
                cout<<"Vnesete za koj tip na vraboteni sakate da vi se ispecati lista (p-profesor, a-asistent, d-demonstrator)";
                cin>>tip;
                if(tip=='p'){
                    for(int i = 0; i < Profesor::brojProfesori; i++){
                        profesor[i].prikazi_podatoci_profesor();
                    }
                } else if (tip=='a'){
                    for(int i = 0; i < Asistent::brojAsistenti; i++){
                        asistent[i].prikazi_podatoci_asistent();
                    }
                } else if (tip=='d'){
                    for(int i = 0; i < Demonstrator::brojDenostratori; i++){
                        demonstrator[i].prikazi_podatoci_demonstrator();
                    }
                } else {
                    cout<<"Vnesovte greshen vlez";
                    break;
                }
                break;
            case 3:
                return 0;
            default:
                printf("Greshen izbor\n");
                break;
        }
    }
}