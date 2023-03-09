#include <iostream>

using namespace std;

class Klasa {
public:
    Klasa() {
        cout << "Class konstruktor" << endl;
    }
    ~Klasa() {
        cout << "Class destruktor" << endl;
    }
};

int main(){

    //1. Напиши програма која демонстрира дека ако е фрлен покажувач на создаден објект, објектот нема да биде уништен.

    try {
        Klasa* klasa = new Klasa();
        throw klasa;
    } catch (Klasa* klasa) {
        cout << "Catch" << endl;
    }
    cout << "Kraj" << endl;

    return 0;
}