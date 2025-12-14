/**
 * @file descent.cpp
 */

#include "Solver.h"
#include "Complex.h"
#include "Rational.h"

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