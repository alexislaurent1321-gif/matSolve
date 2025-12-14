/**
 * @file solve.cpp
 */


#include "Solver.h"
#include "Complex.h"
#include "Rational.h"
#include "Mat.h"
#include <stdexcept>
#include <algorithm>
#include "utils.h"

using namespace std;


// Selectionne la méthode de résolution
template <class T>
Vec<T> Solver<T>::solve(const Mat<T>& A, const Vec<T>& b) {

    bool diag2 = A.isDiag();
    bool tridiag = A.isTridiag();
    bool upper = A.isUpper();
    bool lower = A.isLower();
    bool hermitian = A.isHermitian();
    bool invertible = A.isInvertible();
    bool LUcond = A.isLUDecomposable();
    bool sparse = A.isSparse(0.7);
    bool rational = A.isRational();

    /*
    Toutes les matrices sont supposées définies positives.
    Si la matrice est symétrique/hermitienne et inversible alors on peut utiliser la méthode de Cholesky ou du gradient conjugué.
    Pour choisir entre les deux, on vérifie si la matrice est creuse ou non.
    */

    if(diag2){
        cout << "Résolution diagonale.\n";
        return diag(A,b);
    }

    else if(tridiag){
        cout << "Résolution tridiagonale.\n";
        return Thomas(A,b);
    }

    else if(upper) {
        return climb(A,b);
    }

    else if(lower) {
        return descent(A,b);
    }

    else if (hermitian) {
        if(rational || sparse){
            cout << "Utilisation de la methode du Gradient Conjugué.\n";
            return CG(A,b);
        } else {
            cout << "Utilisation de la methode de Cholesky.\n";
            return Cholesky(A,b);
        }
    }
    
    else if (LUcond) {
        cout << "Utilisation de la méthode de LU.\n";
        return LU(A,b);
    }

    else {
        // Si aucune methode spécifique ne convient, on applique Gauss
        cout << "Utilisation de la méthode de Gauss.\n";
        return Gauss(A,b);
    } 
}

// Calcule le maximum du résidu
template <class T>
T Solver<T>::computeResNormInf(const Mat<T>& A, const Vec<T>& x, const Vec<T>& b) {
    Vec<T> r = (A*x-b).abs();
    return *max_element(r.begin(),r.end());
}


template class Solver<double>;
template class Solver<Complex>;
template class Solver<Rational>;
