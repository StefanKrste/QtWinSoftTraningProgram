#include <iostream>
#include "Complex.h"

using namespace std;

int main () {

    //1. Нека е дадена класата Complex со кодовите презентирани подолу (дефиниција на класа, дефиниција на функции цхленки и драјвер за класатa Complex). Оваа класа овозможува операции со комплексни броеви. Тоа се броеви од облик realenDel + imaginarenDel * i, каде i има вредност √1
    //
    //а) да се модифицира класата така да овозможи влез и излез на комплексни броеви преку преклопување на операторите << и >>. Ова треба да ја замени функцијата print() од класата, која во вашето решение не треба да постои.
    //б) да се преклопи оператор за множење кој ќе овозможи множење на: два комплексни броја, комплексен со цел број и цел број со комплексен број.
    //в) да се преклопат операорите == и != кои ќе овозможат споредување на два комплексни броја.
    //г) да се преклопат операторите +=, -= и *= со помош на ваќе направените функции за преклопување на +, - и *.

    Complex x, y( 4.3, 8.2 ), z( 3.3, 1.1 );
    int broj=3;
    bool ednakvost;

    cout << "x: "<< x;
    cout << "\ny: "<< y;
    cout << "\nz: "<< z;

    x = y + z;
    cout << "\n\nx = y + z:\n";
    cout << x << " = " << y << " + " << z;

    x = y - z;
    cout << "\n\nx = y - z:\n";
    cout << x << " = " << y << " - " << z;

    x = y * z;
    cout << "\n\nx = y * z:\n";
    cout << x << " = " << y << " * " << z;

    x = y * broj;
    cout << "\n\nx = y * broj:\n";
    cout << x << " = " << y << " * " << broj;

    x = broj * y;
    cout << "\n\nx = broj * y:\n";
    cout << x << " = " << broj << " * " << y;

    if(y==z){
        ednakvost=true;
    } else{
        ednakvost=false;
    }
    cout << "\n\ny == z:\n";
    cout << y << " == " << z << "-> " << ednakvost;

    if(y!=z){
        ednakvost=true;
    } else{
        ednakvost=false;
    }
    cout << "\n\ny != z:\n";
    cout << y << " != " << z << "-> " << ednakvost;

    cout << "\n\ny += z:\n";
    cout << y << " += " << z << " -> ";
    y+=z;
    cout<< "y = "<<y;


    cout << "\n\ny -= z:\n";
    cout << y << " -= " << z << " -> ";
    y-=z;
    cout<< "y = "<<y;

    cout << "\n\ny *= z:\n";
    cout << y << " *= " << z << " -> ";
    y*=z;
    cout<< "y = "<<y;

    return 0;

}