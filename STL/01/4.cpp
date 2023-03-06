#include <iostream>

using namespace std;

template< class T >
void printArray( const T *array, const int count ){
    for ( int i = 0; i < count; i++ )
        cout << array[ i ] << " ";
    cout << endl;
}

void printArray( const int *array, const int count ){
    for ( int i = 0; i < count; i++ ) {
        cout << array[i] << " ";
        if ((i+1)%4==0) {
            cout <<endl;
        }
    }
    cout << endl;
}

int main(){

    //4. Преклопи го function template-от printArray со non-template функција која печати поле од int во четири порамнети колони.

    const int aCount = 5;
    const int bCount = 7;
    const int cCount = 6;

    int a[ aCount ] = { 1, 2, 3, 4, 5 };
    double b[ bCount ] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7 };
    char c[ cCount ] = "HELLO";

    cout << "Poleto a sodrzi:" << endl;
    printArray( a, aCount );

    cout << "Poleto a ispecatneno so novata preklopena funkcija: " << endl;
    printArray(a, aCount);

    cout << "Poleto b sodrzi:" << endl;
    printArray( b, bCount );

    cout << "Poleto c sodrzi:" << endl;
    printArray( c, cCount );

    return 0;
}