/**
 * @file descent.cpp
 */

#include "solvers/solver.h"
#include "numbers/complex.h"
#include "numbers/rational.h"

template class Solver<double>;
template class Solver<Complex>;
template class Solver<Rational>;

template <class T>
Vec<T> Solver<T>::descent(const Mat<T>& A, const Vec<T>& b){
    int N=b.size();
    Vec<T> x(N,T(0));
    for(int i=0; i<N; i++) {
        T sum = inner_product(A[i].begin(),A[i].begin()+i,x.begin(),T(0));
        x[i] = (b[i]-sum)/A[i][i];
    }
    return x;
}
template Vec<double> Solver<double>::descent(const Mat<double>& A, const Vec<double>& b);
template Vec<Complex> Solver<Complex>::descent(const Mat<Complex>& A, const Vec<Complex>& b);
template Vec<Rational> Solver<Rational>::descent(const Mat<Rational>& A, const Vec<Rational>& b);


