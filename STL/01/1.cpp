#include <iostream>
#include <algorithm>

using namespace std;

template<typename T>
void sortNiza(T* pole, int size)
{
    sort(pole, pole + size);
}

int main(){

    //1. Напиши function template за сортирање и програма во која се врши внесување, сортирање и печатење на поле од int елементи и поле од double елементи. Може да се користи било кој алгоритам за сортирање.

    int brElementi;
    cout << "Vnesete broj na elementi vo nizata so celi broevi: ";
    cin >> brElementi;

    int intNiza[brElementi];
    for (int i = 0; i < brElementi; i++){
        cin >> intNiza[i];
    }

    sortNiza(intNiza,brElementi);
    cout << "Sortirana niza od celi broevi: ";
    for (int i = 0; i < brElementi; i++){
        cout << intNiza[i] << " ";
    }
    cout << endl;

    cout << "Vnesete broj na elementi vo nizata so decimalni broevi: ";
    cin >> brElementi;
    double doubleNiza[brElementi];
    for (int i = 0; i < brElementi; i++){
        cin >> doubleNiza[i];
    }

    sortNiza(doubleNiza,brElementi);
    cout << "Sortirana niza od decimalni broevi: ";
    for (int i = 0; i < brElementi; i++){
        cout << doubleNiza[i] << " ";
    }
    return 0;
}
