#include <iostream>

using namespace std;

#include "Complex.h"

Complex::Complex( double r, double i )
        : real( r ), imaginary( i ) { }

Complex Complex::operator+( const Complex &operand2 ) const
{
    return Complex( real + operand2.real,
                    imaginary + operand2.imaginary );
}

Complex Complex::operator-( const Complex &operand2 ) const
{
    return Complex( real - operand2.real,
                    imaginary - operand2.imaginary );
}

const Complex& Complex::operator=( const Complex &right )
{
    real = right.real;
    imaginary = right.imaginary;
    return *this;
}

ostream &operator<<( ostream &output, const Complex &complex ){
    cout << '(' << complex.real << ", " << complex.imaginary << ')';
    return output;
}

istream &operator>>( istream &input, Complex &complex ){
    input >> complex.real >> complex.imaginary;
    return input;
}

Complex operator*(Complex complex, int broj){
    complex.real*=broj;
    complex.imaginary*=broj;
    return complex;
}

Complex operator*(int broj, Complex complex){
    complex.real*=broj;
    complex.imaginary*=broj;
    return complex;
}

Complex operator*(Complex complex1, Complex complex2){
    complex1.real*=complex2.real;
    complex1.imaginary*=complex2.imaginary;
    return complex1;
}

bool operator==(Complex complex1, Complex complex2){
    if(complex1.real==complex2.real && complex1.imaginary==complex2.imaginary) {
        return true;
    } else{
        return false;
    }
}

bool operator!=(Complex complex1, Complex complex2){
    if(complex1.real!=complex2.real || complex1.imaginary!=complex2.imaginary) {
        return true;
    } else{
        return false;
    }
}

Complex Complex::operator+=( const Complex &complex ){
    return Complex( real += complex.real,
                    imaginary += complex.imaginary );
}

Complex Complex::operator-=( const Complex &complex ){
    return Complex( real -= complex.real,
                    imaginary -= complex.imaginary );
}

Complex Complex::operator*=( const Complex &complex ){
    return Complex( real *= complex.real,
                    imaginary *= complex.imaginary );
}

