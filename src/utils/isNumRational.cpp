/**
 * @file isNumRational.cpp
 */

#include "utils/utils.h"
#include "numbers/complex.h"

// Détection de rationnel

bool isNumRational(const int& a){return true;}
bool isNumRational(const Rational& a){return true;}
bool isNumRational(const double& a){return false;}
bool isNumRational(const Complex& a){return false;}


