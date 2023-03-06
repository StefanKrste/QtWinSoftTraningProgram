#include <iostream>

using namespace std;

template<class T>
int printArrayBroj( const T *array, int count, int lowSubscript , int highSubscript){
    int brIspecateni = 0;
    if(highSubscript>count){
        return 0;
    }
    if(lowSubscript<=0){
        return 0;
    }
    for (int i = lowSubscript-1; i < highSubscript; i++){
        brIspecateni++;
        cout << array[i] << " ";
    }
    cout << endl;
    return brIspecateni;
}

template< class T >
void printArray( const T *array, const int count ){
    for ( int i = 0; i < count; i++ )
        cout << array[ i ] << " ";
    cout << endl;
}

int main(){

    //2. Преклопи го printArray така што ќе добие уште два целобројни аргументи lowSubscript и highSubscript. Повик на оваа функција треба да ги отпечати елементите помеѓу lowSubscript и highSubscript. Ако нивните вредности излегуваат од димензиите на полето, printArray треба да врати 0, во спротивно бројот на отпечатени елементи. Во main да се тестира функционирањето на двете верзии на printArray врз полињата a, b и c.

    const int aCount = 5;
    const int bCount = 7;
    const int cCount = 6;
    int pom;

    int a[ aCount ] = { 1, 2, 3, 4, 5 };
    double b[ bCount ] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7 };
    char c[ cCount ] = "HELLO";

    cout << "Poleto a sodrzi:" << endl;
    printArray( a, aCount );

    cout << "Poleto vo toj opseg gi ima el:" << endl;
    pom = printArrayBroj( a, aCount,1,3 );
    cout<< "Broj na ispecateni el: "<<  pom <<endl;

    cout << "Poleto b sodrzi:" << endl;
    printArray( b, bCount );

    cout << "Poleto vo tojopseg gi ima el:" << endl;
    pom = printArrayBroj( b, aCount,1,3 );
    cout<< "Broj na ispecateni el: "<< pom <<endl;

    cout << "Poleto c sodrzi:" << endl;
    printArray( c, cCount );

    cout << "Poleto vo tojopseg gi ima el:" << endl;
    pom = printArrayBroj( c, aCount,1,3 );
    cout<< "Broj na ispecateni el: "<< pom <<endl;

    return 0;
}