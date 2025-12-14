/**
 * @file diag.cpp
 */

#include "Solver.h"
#include "Mat.h"
#include "Vec.h"
#include "Complex.h"
#include "Rational.h"


template <class T>
Vec<T> Solver<T>::diag(const Mat<T>& A, const Vec<T>& b){
    int N = b.size();
    Vec<T> x(N);
    for (int i=0; i<N; ++i) {
        x[i] = b[i]/A[i][i];
    }
    return x;
}


template class Solver<double>;
template class Solver<Complex>;
template class Solver<Rational>;