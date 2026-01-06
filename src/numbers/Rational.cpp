/**
 * @file Rational.cpp
 */

#include "numbers/rational.h"
#include <cmath>

void Rational::simplify(){
    long int div = std::gcd(abs(a),abs(b));
    a/=div;
    b/=div;
}

// Opérations binaires avec un entier
Rational Rational::operator+(const long int& n) const{return Rational(a+n*b, b);}
Rational Rational::operator-(const long int& n) const{return Rational(a-n*b, b);}
Rational Rational::operator*(const long int& n) const{return Rational(a*n, b);}
Rational Rational::operator/(const long int& n) const{return Rational(a, b*n);}

// Opérations inaires avec un entier
Rational& Rational::operator+=(const long int& n){
    a+=n*b; 
    simplify();
    return *this;
}
Rational& Rational::operator-=(const long int& n){
    a-=n*b; 
    simplify();
    return *this;
}
Rational& Rational::operator*=(const long int& n){
    a*=n; 
    simplify();
    return *this;
}
Rational& Rational::operator/=(const long int& n){
    b*=n; 
    simplify();
    return *this;
}

// Opérations binaires
Rational Rational::operator+(const Rational& q) const{return Rational(a*q.b+q.a*b, b*q.b);}
Rational Rational::operator-(const Rational& q) const{return Rational(a*q.b-q.a*b, b*q.b);}
Rational Rational::operator*(const Rational& q) const{return Rational(a*q.a, b*q.b);}
Rational Rational::operator/(const Rational& q) const{
    assert(q.a!=0);
    return Rational(a*q.b, q.a*b);
}
bool Rational::operator==(const Rational& q) const{return (a*q.b == q.a*b);}
bool Rational::operator!=(const Rational& q) const{return (a*q.b != q.a*b);}
bool Rational::operator<(const Rational& q) const{return (a*q.b < q.a*b);}
bool Rational::operator>(const Rational& q) const{return (a*q.b> q.a*b);}
bool Rational::operator<=(const Rational& q) const{return (a*q.b <= q.a*b);}
bool Rational::operator>=(const Rational& q) const{return (a*q.b >= q.a*b);}



// Opérations unaires
Rational& Rational::operator+=(const Rational& q){
    long int a_=a, b_=b;
    a=a_*q.b+q.a*b_, b*=q.b; 
    simplify();
    return *this;
}
Rational& Rational::operator-=(const Rational& q){
    long int a_=a, b_=b;
    a=a_*q.b-q.a*b_, b*=q.b; 
    simplify();
    return *this;
}
Rational& Rational::operator*=(const Rational& q){
    a*=q.a, b*=q.b; 
    simplify();
    return *this;
}
Rational& Rational::operator/=(const Rational& q){
    assert(q.a!=0);
    a*=q.b, b*=q.a;
    simplify();
    return *this;
}
Rational Rational::operator-() const{return Rational(-a,b);}


// Affichage
std::ostream& operator<<(std::ostream &os, const Rational& q){
    if(q.b==1)
        os << q.a;
    else if(q.a*q.b < 0)
        os << "-" << abs(q.a) << "/" << abs(q.b);
    else
        os << abs(q.a) << "/" << abs(q.b);
    return os;
}

std::istream& operator>>(std::istream& in, Rational& q){
    in >> q.a;
    q.b = 1;
    return in;
}