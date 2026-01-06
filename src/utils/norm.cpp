/**
 * @file norm.cpp
 */

#include "utils.h"
#include "numbers/Complex.h"

// norme
double norm(const int& a){
    return abs(a);
}
double norm(const double& a){
    return fabs(a);
}
double norm(const Complex& a){
    return a.modulus();
}
double norm(const Rational& a){
    return fabs(a.value());
}

