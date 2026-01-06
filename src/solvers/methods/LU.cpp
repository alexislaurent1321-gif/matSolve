/**
 * @file LU.cpp
 * \brief Méthode LU
 */

#include "solvers/solver.h"
#include "numbers/complex.h"
#include "numbers/rational.h"

template class Solver<double>;
template class Solver<Complex>;
template class Solver<Rational>;

// Implémentation de solveLU
template <class T>
Vec<T> Solver<T>::LU(const Mat<T>& A, const Vec<T>& b){
    int N = b.size();

    // Matrices triangulaires L et U
    Mat<T> L(N,N);
    Mat<T> U(N,N);
    L.init(T(0));
    U.init(T(0));

    // Décomposition LU
    for(int i=0; i<N; i++) {
        for(int j=i; j<N; j++) {
            T sum = T(0);
            for (int k=0; k<i; k++) {
                sum += L[i][k]*U[k][j];
            }
            U[i][j] = A[i][j]-sum;
        }

        for (int j=i; j<N; j++) {
            T sum = T(0);
            for (int k=0; k<i; k++) {
                sum += L[j][k]*U[k][i];
            }
            L[j][i] = (A[j][i]-sum)/U[i][i];
        }
    }

    // Résolution de Ly = b (substitution avant)
    Vec<T> y = descent(L,b);

    // Résolution de Ux = y (substitution arrière)
    Vec<T> x = climb(U,y);

    return  x;
}
template Vec<double> Solver<double>::LU(const Mat<double>& A, const Vec<double>& b);
template Vec<Complex> Solver<Complex>::LU(const Mat<Complex>& A, const Vec<Complex>& b);
template Vec<Rational> Solver<Rational>::LU(const Mat<Rational>& A, const Vec<Rational>& b);

