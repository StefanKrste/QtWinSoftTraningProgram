#include <iostream>

using namespace std;

template<class T>
T sum(T* niza, int pocetok, int kraj, T rez = T()){
    for(int i = pocetok; i <= kraj; ++i)    {
        rez+=niza[i];
    }
    return rez;
}

int main(){

    //1. Напиши function template кој има еден параметризиран тип (T) и прифаќа четири аргументи: поле од тип T, почетен индекс, краен индекс и опциона, почетна вредност. Функцијата трба да ја врати сумата на елементите во полето зададени со почетниот и крајниот индекс. За почетната вредност да се употреби конструкторот на T.

    int size,pocetok,kraj;
    cout << "Dolzina na nizata: ";
    cin >> size;

    int niza[size];

    cout << "Vnesi elementi vo nizata: ";
    for(int i = 0; i < size; ++i){
        cin >> niza[i];
    }

    cout<<"Pocetna vrednost";
    cin>>pocetok;
    cout<<"Krajna vrednost";
    cin>>kraj;
    if(kraj>pocetok && kraj<size && pocetok>0) {
        cout << "Suma: " << sum(niza, pocetok-1, kraj-1);
    } else{
        cout<<"Vnesenite parametri ne se vo opsegot na elementi na nizata";
    }
    return 0;
}
