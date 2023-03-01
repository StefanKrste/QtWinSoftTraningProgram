#include <iostream>

using namespace std;

template < class T >
T minimum( T value1, T value2)
{
    if ( value2 < value1 )
        return value2;
    return value1;
}


int main(){

    //1. Напиши програм кој кој користи функциски урнек min за да го определи помалиот од двата аргументи. Тестирај го прогамот со цели броеви, реални броеви и карактери.

    int int1, int2;

    cout << "Vnesi dva celi broja: ";
    cin >> int1 >> int2;
    cout << "Minimalniot cel broj e: " << minimum( int1, int2);

    double double1, double2;

    cout << "\nVnesi dva realni broja: ";
    cin >> double1 >> double2 ;
    cout << "Minimalnata realna vrednost e: " << minimum( double1, double2);

    char char1, char2;

    cout << "\nVnesi dva karakteri: ";
    cin >> char1 >> char2;
    cout << "Minimalniot karakter e: " << minimum( char1, char2) << endl;

    return 0;
}

