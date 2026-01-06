/**
 * @file ABS.cpp
 */

#include "utils/utils.h"
#include "numbers/complex.h"

// Racine carré

int ABS(const int& a){
    return abs(a);
}

Rational ABS(const Rational& q){
    if(q.num()*q.denom()<0)
        return Rational(-q.num(),q.denom());
    return q;
}

double ABS(const double& a){
    return fabs(a);
}

Complex ABS(const Complex& z){
    return Complex(z.modulus(),0);
}

