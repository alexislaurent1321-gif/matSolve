/**
 * @file Cholesky.cpp
 */

#include "solvers/solver.h"
#include "numbers/complex.h"
#include "utils/utils.h"
#include "numbers/rational.h"

template class Solver<double>;
template class Solver<Complex>;
template class Solver<Rational>;

template <class T>
Vec<T> Solver<T>::Cholesky(const Mat<T>& A, const Vec<T>& b){
    int N = b.size();
    Mat<T> L(N,N);
    L.init(0);

    for (int i=0; i<N; ++i){
        for (int j=0; j<=i; ++j){
            T sum = T(0);
            for (int k=0; k<j; ++k){
                sum += L[i][k]*conj(L[j][k]);
            }
            if (i==j){
                T diag = ((A[i][i]-sum)+conj(A[i][i]-sum))/2;
                L[i][j] = SQRT(diag);
            }else{
                L[i][j] = (A[i][j]-sum)/L[j][j];
            }
        }
    }
    // Résolution de Ly = b (substitution avant)
    Vec<T> y = descent(L,b);

    // Résolution de Lᵀx = y (substitution arrière)
    Vec<T> x = climb(L.transpose(),y);

    return  x;
}
template Vec<double> Solver<double>::Cholesky(const Mat<double>& A, const Vec<double>& b);
template Vec<Complex> Solver<Complex>::Cholesky(const Mat<Complex>& A, const Vec<Complex>& b);
template Vec<Rational> Solver<Rational>::Cholesky(const Mat<Rational>& A, const Vec<Rational>& b);

