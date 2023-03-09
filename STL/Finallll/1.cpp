#include <iostream>

using namespace std;

template< class T>
class Pole{
    T pole[100];
public:
    static int BrElementi;
    void Dodadi(T el);
    T* GetPole() { return pole; }
};

template <class T>
int Pole<T>::BrElementi = 0;

template <>
int Pole<int>::BrElementi = 0;

template <>
int Pole<char>::BrElementi = 0;

template <>
int Pole<string>::BrElementi = 0;

template<class T>
void Pole<T>::Dodadi(T el){
    pole[BrElementi++]=el;
}

template<class T>
void max(Pole<T>& p){
    T* pole = p.GetPole();
    T max_element = pole[0];
    for(int i = 1; i < p.BrElementi; i++){
        if(pole[i] > max_element){
            max_element = pole[i];
        }
    }
    cout << max_element << endl;
}

template<class T>
void max(Pole<string>& p){
    T* pole = p.GetPole();
    string max_element = pole[0];
    for(int i = 1; i < p.BrElementi; i++){
        if(pole[i].length()>max_element.length()){
            max_element = pole[i];
        }
    }
    cout << max_element << endl;
}

int main(){

    //1. Креирај class temlate Pole што реализира поле од било кој тип. Имплементирај function template max за определување на најголем елемент во полето. Во main креирај полиња од int, char и string, пополни ги со по 5 произволни елементи и прикажи најголем елемент за секое поле.

    Pole<int> A;
    Pole<char> B;
    Pole<string> C;
    int intEl;
    char charEl;
    string stringEl;

    cout<<"Vnesete element vo nizata INT";
    for (int i = 0; i < 5; ++i) {
        cin>>intEl;
        A.Dodadi(intEl);
    }

    cout<<"Vnesete element vo nizata CHAR";
    for (int i = 0; i < 5; ++i) {
        cin>>charEl;
        B.Dodadi(charEl);
    }

    cout<<"Vnesete element vo nizata STRING";
    for (int i = 0; i < 5; ++i) {
        cin>>stringEl;
        C.Dodadi(stringEl);
    }

    cout << "Najgolem Element vo INT nizata e:";
    max(A);
    cout << "Najgolem Element vo CHAR nizata e:";
    max(B);
    cout << "Najgolem(Najdolg) Element vo STRING nizata e:";
    max<string>(C);

    return 0;
}