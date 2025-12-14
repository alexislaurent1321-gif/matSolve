/**
 * @file climb.cpp
 */

#include "Solver.h"
#include "Complex.h"
#include "Rational.h"

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


template class Solver<double>;
template class Solver<Complex>;
template class Solver<Rational>;
