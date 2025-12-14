/**
 * @file Complex.cpp
 */

#include "Complex.h"
#include <cmath>

const Complex Complex::i(0,1);

// Opérations avec un réel
Complex Complex::operator+(const double& a) const {return Complex(re+a, im);}
Complex Complex::operator-(const double& a) const {return Complex(re-a, im);}
Complex Complex::operator*(const double& a) const {return Complex(re*a, im*a);}
Complex Complex::operator/(const double& a) const {
    assert(a != 0);
    return Complex(re/a, im/a);
}

// Opérations binaires
Complex Complex::operator+(const Complex& z) const {return Complex(re+z.re, im+z.im);}
Complex Complex::operator-(const Complex& z) const {return Complex(re-z.re, im-z.im);}
Complex Complex::operator*(const Complex& z) const {return Complex(re*z.re - im*z.im, re*z.im + im*z.re); }
Complex Complex::operator/(const Complex& z) const {
    double denom = pow(z.modulus(),2);
    assert(denom != 0);
    return Complex((re*z.re + im*z.im),(im*z.re - re*z.im)) / denom;
}
bool Complex::operator==(const Complex& z) const {return (re==z.re && im==z.im);}
bool Complex::operator!=(const Complex& z) const {return !(*this == z);}   
bool Complex::operator<(const Complex& z) const {return (*this).modulus()<z.modulus();} 
bool Complex::operator>(const Complex& z) const {return (*this).modulus()>z.modulus();} 



// Opérations unaires

Complex& Complex::operator+=(const Complex& z) {
    re += z.re;
    im += z.im;
    return *this;
}

Complex& Complex::operator-=(const Complex& z) {
    re -= z.re;
    im -= z.im;
    return *this;
}

Complex& Complex::operator*=(const Complex& z) {
    double re_ = re * z.re - im * z.im;
    double im_ = re * z.im + im * z.re;
    re = re_;
    im = im_;
    return *this;
}

Complex& Complex::operator/=(const Complex& z) {
    double denom = pow(z.modulus(),2);
    assert(denom != 0);
    double re_ = (re*z.re + im*z.im) / denom;
    double im_ = (im*z.re - re*z.im) / denom;
    re = re_;
    im = im_;
    return *this;
}

Complex Complex::operator-() const { return Complex(-re,-im); }


// Affichage

std::ostream& operator<<(std::ostream& os, const Complex& z) {
    if(z.im==0)
        os << z.re;
    else if(z.re==0)
        os << z.im << "i";
    else
        os << z.re << (z.im >= 0 ? "+" : "") << z.im << "i";
    return os;
}

std::istream& operator>>(std::istream& in, Complex& z){
    in >> z.re >> z.im;
    return in;
}