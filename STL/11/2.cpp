#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){

    //2. Напиши програма со која сите зборови од текстуална датотека со големина помала од 10 знаци ќе ги запише во друга текстуална датотека.

    string zbor;
    ifstream file_in;
    ofstream file_out;

    file_in.open("dat1.dat");
    file_out.open("dat2.dat");

    if (!file_in || !file_out){
        cout << "Eden od fajlovite nemoze da se otvori" << endl;
        return 0;
    }

    while (file_in >> zbor){
        if (zbor.length() < 10){
            file_out << zbor << " ";
        }
    }

    file_in.close();
    file_out.close();

    return 0;
}
