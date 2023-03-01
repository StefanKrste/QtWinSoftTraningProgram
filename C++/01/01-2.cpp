#include <iostream>

using namespace std;

double tripleCallByValue(double broj){
    return 3*broj;
}

void tripleCallByReference(double &broj){
    broj*=3;
}

int main()
{
    //2.	Нaпиши С++ програм со две посебни функции кои едноставно ја триплираат вредноста на променливата count дефинирана во main. Овие функции се:
    //a.	Функцијата tripleCallByValue која предава копија од count, ја триплира нејзината вредност и ја враќа новата вредност
    //b.	Функцијата tripleCallByReference која ja предава count како референцен параметар, ја триплира самата променлива и ја враќа новата вредност на count

    double broj;

    cout << "Vnesi Broj:  ";
    cin >> broj;
    cout << "brojx3= "<< tripleCallByValue(broj)<<endl;
    tripleCallByReference (broj);
    cout << "brojx3= "<< broj <<endl;

    return 0;
}