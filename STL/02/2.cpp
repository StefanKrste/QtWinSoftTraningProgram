#include <iostream>
#include <algorithm>

using namespace std;

//----------------------------------------------------------------------------------------------------------------------

class Kvadrat{
    float strana;
public:
    Kvadrat(){strana=1;};
    Kvadrat(float);
    float Plostina() const;
};

Kvadrat::Kvadrat(float strana) {
    this->strana=strana;
}

float Kvadrat::Plostina() const{
    return strana*strana;
}

//----------------------------------------------------------------------------------------------------------------------

class Pravoagolnik{
    float strana;
    float dolzina;
public:
    Pravoagolnik(){strana=1;dolzina=1;};
    Pravoagolnik(float ,float);
    float Plostina() const;
};

Pravoagolnik::Pravoagolnik(float strana, float dolzina) {
    this->strana=strana;
    this->dolzina=dolzina;
}

float Pravoagolnik::Plostina() const {
    return strana*dolzina;
}

//----------------------------------------------------------------------------------------------------------------------

template<class T>
void sortiraj(T* niza, int dolzina){
    sort(niza, niza + dolzina, [](const T& a, const T& b) {
        return a.Plostina() < b.Plostina();
    });
}

template<class T>
void pecatiPole(T* niza, int dolzina){
    for(int i=0; i<dolzina; i++){
        cout<<niza[i].Plostina()<<" ";
    }
    cout<<endl;
}

int main(){

    //2. Креирај класа Kvadrat со податоци strana и класа Pravoagolnik со податоци sirina и dolzina.  Напиши function template sortirajPole со кој се врши сортирање на поле и function template pecatiPole со кој се врши печатење на поле. Во main креирај две полиња од квадрати и праваголници, прикажи ги со pecatiPole, сортирај ги според плоштина со sortirajPole и повторно отпечати ги.

    Kvadrat kvadrat[4];
    Pravoagolnik pravoagolnik[5];

    kvadrat[0] = Kvadrat(5);
    kvadrat[1] = Kvadrat(35);
    kvadrat[2] = Kvadrat(25);
    kvadrat[3] = Kvadrat(15);

    pravoagolnik[0]=Pravoagolnik(5,10);
    pravoagolnik[1]=Pravoagolnik(15,10);
    pravoagolnik[2]=Pravoagolnik(5,3);
    pravoagolnik[3]=Pravoagolnik(25,15);
    pravoagolnik[4]=Pravoagolnik(28,12);


    cout<<"Nesortirani plostini na kvadratite se: ";
    pecatiPole(kvadrat,4);

    cout<<"Nesortirani plostini na pravoagolnicite se: ";
    pecatiPole(pravoagolnik,5);

    sortiraj(kvadrat,4);
    sortiraj(pravoagolnik,5);

    cout<<"Sortirani plostini na kvadratite se: ";
    pecatiPole(kvadrat,4);

    cout<<"Sortirani plostini na pravoagolnicite se: ";
    pecatiPole(pravoagolnik,5);

    return 0;
}
