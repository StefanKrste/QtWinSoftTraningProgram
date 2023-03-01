#include <iostream>

using namespace std;

inline double circleArea(double radius) {
    return 3.14 * radius * radius;
}

int main()
{
    //1.	Напиши С++ програм кој користи inline функција circleArea која бара влез од корисникот за радиус на круг, ја пресметува и ја печати површината на кругот.

    double r;

    cout << "Vnesi radius na krugot:  ";
    cin >> r;
    cout << "Povrsinata na krugot so radius "<< r << " e " << circleArea( r ) << endl;

    return 0;
}

