/**
 * @file utils.h
 * \brief Ensemble de fonctions hors classe qui servent à éviter les conflits entre les types en faisant appel à une méthode de résolution
 * \author Alexis LAURENT
 * \author Killian DALLERAC
 * \date Décembre 2024
 */

#include "Complex.h"
#include "Rational.h"
#include "Vec.h"
#include "Mat.h"

/**
 * \brief Retourne la racine carrée pour chaque type
 */
double SQRT(const int& a);
Rational SQRT(const Rational& q);
double SQRT(const double& a);
Complex SQRT(const Complex& z);

/**
 * \brief retourne la valeur absolue pour chaque type (pas de changement pour les complexes)
 */
int ABS(const int& a);
Rational ABS(const Rational& q);
double ABS(const double& a);
Complex ABS(const Complex& z);

/**
 * \brief Vérifie si un nombre est rationnel
 */
bool isNumRational(const int& a);
bool isNumRational(const Rational& a);
bool isNumRational(const double& a);
bool isNumRational(const Complex& a);

/**
 * \brief Retourne le produit scalaire de deux vecteurs réels et le produit hermitien deux vecteurs complexes
 */
int dot(Vec<int>& v1, Vec<int>& v2);
Rational dot(Vec<Rational>& v1, Vec<Rational>& v2);
double dot(Vec<double>& v1, Vec<double>& v2);
Complex dot(Vec<Complex>& v1, Vec<Complex>& v2);

/**
 * \brief Retourne le conjugué complexe
 */
double conj(const double& a);
Rational conj(const Rational& r);
Complex conj(const Complex& z);

/**
 * \brief Convertie le nombre en un double positif en retournant la valeur absolue pour les réels et le module pour les complexes
 */
double norm(const int& a);
double norm(const double& a);
double norm(const Complex& a);
double norm(const Rational& a);
