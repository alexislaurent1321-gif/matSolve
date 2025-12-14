/**
 * @file utils.cpp
 */

#include "utils.h"
#include "Complex.h"

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


// Conjugué complexe pour les différents types

double conj(const double& a) {
    return a; // Pas de conjugaison pour les réels
}

Rational conj(const Rational& r) {
    return r; // Pas de conjugaison pour les rationnels
}

Complex conj(const Complex& z) {
    return z.conj(); // Appel de la méthode conj() de la classe Complex
}


// Détection de rationnel

bool isNumRational(const int& a){return true;}
bool isNumRational(const Rational& a){return true;}
bool isNumRational(const double& a){return false;}
bool isNumRational(const Complex& a){return false;}


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

