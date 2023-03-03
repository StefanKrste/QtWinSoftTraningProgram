#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex {
public:
    Complex( double = 0.0, double = 0.0 );
    Complex operator+( const Complex & ) const;
    Complex operator-( const Complex & ) const;
    const Complex &operator=( const Complex & );
    friend std::ostream &operator<<( std::ostream&, const Complex & );
    friend std::istream &operator>>( std::istream&, Complex & );
    friend Complex operator*(Complex complex, int broj);
    friend Complex operator*(int broj, Complex complex);
    friend Complex operator*(Complex complex1, Complex complex2);
    friend bool operator==(Complex complex1, Complex complex2);
    friend bool operator!=(Complex complex1, Complex complex2);
    Complex operator+=( const Complex &complex );
    Complex operator-=( const Complex &complex );
    Complex operator*=( const Complex &complex );
private:
    double real;
    double imaginary;
};

#endif

