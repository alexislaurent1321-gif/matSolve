/**
 * @file conj.cpp
 */

#include "matSolve/utils/utils.h"
#include "matSolve/numbers/complex.h"

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

