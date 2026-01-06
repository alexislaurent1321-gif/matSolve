/**
 * @file dot.cpp
 */

#include "utils.h"
#include "numbers/Complex.h"

// Produit scalaire

int dot(Vec<int>& v1, Vec<int>& v2){
    int result = 0;
    assert(v1.size()==v2.size());
    for(int i=0; i<v1.size(); i++)
        result += v1[i]*v2[i];
    return result;
}

Rational dot(Vec<Rational>& v1, Vec<Rational>& v2){
    Rational result = Rational(0);
    assert(v1.size()==v2.size());
    for(int i=0; i<v1.size(); i++)
        result += v1[i]*v2[i];
    return result;
}

double dot(Vec<double>& v1, Vec<double>& v2){
    double result = 0;
    assert(v1.size()==v2.size());
    for(int i=0; i<v1.size(); i++)
        result += v1[i]*v2[i];
    return result;
}

Complex dot(Vec<Complex>& v1, Vec<Complex>& v2){
    Complex result = Complex(0);
    assert(v1.size()==v2.size());
    for(int i=0; i<v1.size(); i++)
        result += v1[i]*v2[i].conj();
    return result;
}
