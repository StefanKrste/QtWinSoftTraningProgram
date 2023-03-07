#include <iostream>
#include <vector>

using namespace std;

template<typename T>
bool Polindrom(vector<T>& v1, vector<T>& v2) {
    if (v1.size() != v2.size()) {
        return false;
    }
    for (int i = 0; i < v1.size(); i++) {
        if (v1[i] != v2[v2.size()-1-i]) {
            return false;
        }
    }
    return true;
}

int main(){

    //1. Напиши function template palindrom кој има параметар vector и враќа true ако векторот е палиндром, а false во спротивно.

    vector <char> v1 = {'o', 's', 'a'};
    vector <char> v2 = {'a', 's', 'o'};

    if (Polindrom(v1, v2)) {
        cout << "Vektorite se polindromi" << endl;
    } else {
        cout << "Vektorite ne se polindromi" << endl;
    }
    return 0;
}
