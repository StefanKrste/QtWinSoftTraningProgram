#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main(){

    //3. За текст внесен од тастатура прикажи ги сите зборови од кои се состои текстот по еднаш, во абецеден редослед.

    vector <string> Vtext;
    string text;
    cout << "Vnesete go tekstot: ";
    getline(cin, text);
    stringstream ss(text);
    while (ss >> text) {
        Vtext.push_back(text);
    }

    sort(Vtext.begin(), Vtext.end());

    auto it = unique(Vtext.begin(), Vtext.end());
    Vtext.erase(it, Vtext.end());

    for (auto i = Vtext.begin(); i != Vtext.end(); ++i ){
        cout << *i << "\n";
    }
    return 0;
}