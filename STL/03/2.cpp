#include <iostream>
#include <cstring>

using namespace std;

template< class T >
class Mnozestvo{
    T pole[100];
public:
    static int BrElementi;
    Mnozestvo();
    void Dodadi(T el);
    void Prikazi();
    void Najgolem();
};

template<class T>
Mnozestvo<T>::Mnozestvo() {}

template< class T >
int Mnozestvo<T>::BrElementi = 0;

template <>
int Mnozestvo<int>::BrElementi = 0;

template <>
int Mnozestvo<double>::BrElementi = 0;

template <>
int Mnozestvo<char*>::BrElementi = 0;

template<class T>
void Mnozestvo<T>::Dodadi(T el){
    for(int i = 0; i < BrElementi; i++){
        if(el==pole[i]){
            cout << "Veke postoi vo nizata";
            return;
        }
    }
    pole[BrElementi++]=el;
}

template <>
void Mnozestvo<char*>::Dodadi(char* el){
    for(int i = 0; i < BrElementi; i++){
        if(strcmp(el, pole[i]) == 0){
            cout << "Veke postoi vo nizata";
            return;
        }
    }
    pole[BrElementi++] = el;
}

template<class T>
void Mnozestvo<T>::Prikazi() {
    for(int i = 0; i < BrElementi; i++){
        cout <<pole[i]<<" ";
    }
}

template<class T>
void Mnozestvo<T>::Najgolem(){
    if(BrElementi == 0){
        cout << "Nema elementi vo nizata";
        return;
    }
    T max_element = pole[0];
    for(int i = 1; i < BrElementi; i++){
        if(pole[i] > max_element){
            max_element = pole[i];
        }
    }
    cout << "Najgolem element vo nizata e: " << max_element;
}

template <>
void Mnozestvo<char*>::Najgolem(){
    if(BrElementi == 0){
        cout << "Nema elementi vo nizata";
        return;
    }
    char* max_element = pole[0];
    for(int i = 1; i < BrElementi; i++){
        if(strcmp(pole[i], max_element) > 0){
            max_element = pole[i];
        }
    }
    cout << "Najgolem element vo nizata e: " << max_element;
}

int main(){

    //2.      Креирај class template Mnozestvo<T> во со функции членки за додавање, прикажување на елементи на множеството и определување на најголем елемент во множеството. Како податочна структура за сместување на елементите на множеството може да се користи поле. Секој елемент може да се појави само еднаш. Секое множество содржи static компонента во која е сместен бројот на елементи на множеството. Креирај три множества: А од int, B од double и C од char*. Користи соодветна специјализација за коректно определување на најголем елемент во множеството од стрингови. Програмата треба да имплементира мени со следните опции:
    //      1.      Додај елемент во А
    //      2.      Додај елемент во B
    //      3.      Додај елемент во C
    //      4.      Прикажи го А
    //      5.      Прикажи го B
    //      6.      Прикажи го C
    //      7.      Прикажи најголеми елементи
    //      8.      Прикажи број на елементи во множествата
    //      9.      Крај

    int opcija;
    Mnozestvo<int> A;
    Mnozestvo<double> B;
    Mnozestvo<string> C;
    int intEl;
    double doubleEl;
    string stringEl;

    while(true) {
        cout<<"\nVnesi izbor:\n"
              "1 Dodaj element vo A\n"
              "2 Dodaj element vo B\n"
              "3 Dodaj element vo C\n"
              "4 Prikazi go A\n"
              "5 Prikazi go B\n"
              "6 Prikazi go C\n"
              "7 Prikazi najgolemi elementi\n"
              "8 Prikazi broj na elementi vo mnozestvoto\n"
              "9 Kraj\n";
        cin >> opcija;

        switch(opcija){
            case 1:
                cout<<"Vnesete element vo nizata INT";
                cin>>intEl;
                A.Dodadi(intEl);
                break;
            case 2:
                cout<<"Vnesete element vo nizata DOUBLE";
                cin>>doubleEl;
                B.Dodadi(doubleEl);
                break;
            case 3:
                cout<<"Vnesete element vo nizata STRING";
                cin>>stringEl;
                C.Dodadi(stringEl);
                break;
            case 4:
                cout<<"Elementite na nizata INT se:";
                A.Prikazi();
                break;
            case 5:
                cout<<"Elementite na nizata DOUBLE se:";
                B.Prikazi();
                break;
            case 6:
                cout<<"Elementite na nizata STRING se:";
                C.Prikazi();
                break;
            case 7:
                if(Mnozestvo<int>::BrElementi) {
                    cout << "Najgolem Element vo INT nizata e:";
                    A.Najgolem();
                    cout << endl;
                } else{
                    cout<<"Nizata INT e prazna";
                }
                if(Mnozestvo<double>::BrElementi) {
                    cout << "Najgolem Element vo DOUBLE nizata e:";
                    B.Najgolem();
                    cout << endl;
                }else{
                    cout<<"Nizata DOUBLE e prazna";
                }
                if(Mnozestvo<string>::BrElementi) {
                    cout << "Najgolem Element vo STRING nizata e:";
                    C.Najgolem();
                    cout << endl;
                }else{
                    cout<<"Nizata STRING e prazna";
                }
                break;
            case 8:
                cout<<"Mnozestvo INT ima: "<<Mnozestvo<int>::BrElementi<<" elementi"<< endl;
                cout<<"Mnozestvo DOUBLE ima: "<<Mnozestvo<double>::BrElementi<<" elementi"<< endl;
                cout<<"Mnozestvo STRING ima: "<<Mnozestvo<string>::BrElementi<<" elementi"<< endl;
                break;
            case 9:
                return 0;
            default:
                printf("Greshen izbor\n");
                break;
        }
    }
}
