/**
 * @file SQRT.cpp
 */

#include "matSolve/utils/utils.h"
#include "matSolve/numbers/complex.h"

// Racine carré
double SQRT(const int& a){
    return std::sqrt((double)a);
}

Rational SQRT(const Rational& q){
    return Rational(0);
}

double SQRT(const double& a){
    return std::sqrt(a);
}

Complex SQRT(const Complex& z){
    return Complex(std::cos(z.angle()/2),std::sin(z.angle()/2)) * std::sqrt(z.modulus());
}

