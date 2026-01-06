/**
 * @file diag.cpp
 */

#include "matSolve/solvers/solver.h"
#include "matSolve/linear/mat.h"
#include "matSolve/linear/vec.h"
#include "matSolve/numbers/complex.h"
#include "matSolve/numbers/rational.h"

template class Solver<double>;
template class Solver<Complex>;
template class Solver<Rational>;

template <class T>
Vec<T> Solver<T>::diag(const Mat<T>& A, const Vec<T>& b){
    int N = b.size();
    Vec<T> x(N);
    for (int i=0; i<N; ++i) {
        x[i] = b[i]/A[i][i];
    }
    return x;
}
template Vec<double> Solver<double>::diag(const Mat<double>& A, const Vec<double>& b);
template Vec<Complex> Solver<Complex>::diag(const Mat<Complex>& A, const Vec<Complex>& b);
template Vec<Rational> Solver<Rational>::diag(const Mat<Rational>& A, const Vec<Rational>& b);

