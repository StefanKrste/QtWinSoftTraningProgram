#include <iostream>

using namespace std;

class Motor{
public:
    Motor();
    ~Motor();
};

Motor::Motor() {
    cout << "Motor konstruktor" << endl;
    throw exception();
}

Motor::~Motor() {
    cout << "Motor destruktor" << endl;
}

//----------------------------------------------------------------------------------------------------------------------

class Avtomobil{
    Motor *motor;
public:
    Avtomobil();
    ~Avtomobil();
};

Avtomobil::Avtomobil() {
    cout << "Avtomobil konstruktor" << endl;
    motor = new Motor();
}

Avtomobil::~Avtomobil() {
    cout << "Avtomobil destruktor" << endl;
    delete motor;
}

//----------------------------------------------------------------------------------------------------------------------

class Garaza{
    Avtomobil *avtomobil;
public:
    Garaza();
    ~Garaza();
};

Garaza::Garaza() {
    try {
        cout << "Garaza konstruktor" << endl;
        avtomobil = new Avtomobil();
    }catch (exception &e){
        cout << "Catch Garaza konstruktor" << endl;
        throw exception();
    }
}

Garaza::~Garaza() {
    cout << "Garaza destruktor" << endl;
    delete avtomobil;
}



int main(){

    //2.  Креирај класа Garaza во која има Avtomobil што може да има проблеми со својот Motor. Употреби try блок во конструкторот на Garaza за фаќање на исклучокот од Motor кога се иницијализира Avtomobil. Фрли друг исклучок од catch блокот во конструкторот на  Garaza и фати го во main( ).

    try{
        Garaza garaza;
    }catch(exception &e){
        cout << "Catch main\n";
    }
    return 0;
}