/**
 * @file climb.cpp
 */

#include "solvers/solver.h"
#include "numbers/complex.h"
#include "numbers/rational.h"

template class Solver<double>;
template class Solver<Complex>;
template class Solver<Rational>;

template <class T>
Vec<T> Solver<T>::climb(const Mat<T>& A, const Vec<T>& b){
    int N = b.size();
    Vec<T> x(N,T(0));
    for (int i=N-1; i>=0; i--) {
        T sum = inner_product(A[i].begin()+i+1,A[i].end(),x.begin()+i+1,T(0));
        x[i] = (b[i]-sum)/A[i][i];
    }
    return x;
}
template Vec<double> Solver<double>::climb(const Mat<double>& A, const Vec<double>& b);
template Vec<Complex> Solver<Complex>::climb(const Mat<Complex>& A, const Vec<Complex>& b);
template Vec<Rational> Solver<Rational>::climb(const Mat<Rational>& A, const Vec<Rational>& b);


