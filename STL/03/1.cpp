#include <iostream>

using namespace std;

template< class T >
class Zapis{
public:
    T x;
    T y;
    T z;
    Zapis(T, T ,T);
};

template< class T >
Zapis<T>::Zapis(T x, T y,T z){
    this->x=x;
    this->y=y;
    this->z=z;
}

template< class T >
bool Kontroler(Zapis<T> t){
    if((t.x+t.y+t.z)>10000){
        return true;
    }
    return false;
}

int main(){

    //1. Напиши class template Zapis<T> кој содржи три приватни членки: x, y и z од тип Т. Креирај function template kontrolor кој ќе проверува дали збирот на елементите x, y и z во Zapis надминува 10000. Напиши соодветна програма за демонстрација со инстанцирање на објекти од тип Zapis<int> и Zapis<double>.

    Zapis<int> zapis1 = Zapis(1000,2500,3000);
    if(Kontroler(zapis1)){
        cout<<"Zbirot e pogolem od 10000 na Zalpis<int>";
    }else{
        cout<<"Zbirot e pomal od 10000 na Zalpis<int>";
    }
    cout<<endl;
    Zapis<double> zapis2 = Zapis(1900.5,2500.6,30000.50);
    if(Kontroler(zapis2)){
        cout<<"Zbirot e pogolem od 10000 na Zalpis<double>";
    }else{
        cout<<"Zbirot e pomal od 10000 na Zalpis<double>";
    }
    return 0;
}
