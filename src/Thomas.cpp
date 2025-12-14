/**
 * @file Thomas.cpp
 */

#include "Solver.h"
#include "Mat.h"
#include "Vec.h"
#include "Complex.h"
#include "Rational.h"

template <typename T>
Vec<T> Solver<T>::Thomas(const Mat<T>& A, const Vec<T>& b) {
    int N = b.size();

    Vec<T> cp(N-1), dp(N), x(N);
    
    cp[0] = A[0][1]/A[0][0];
    dp[0] = b[0]/A[0][0];

    for (int i=1; i<N-1; i++) {
        T denom = A[i][i]-A[i][i-1]*cp[i-1];
        cp[i] = A[i][i+1]/denom;
        dp[i] = (b[i]-A[i][i-1]*dp[i-1])/denom;
    }
    T denom = A[N-1][N-1]-A[N-1][N-2]*cp[N-2];
    dp[N-1] = (b[N-1]-A[N-1][N-2]*dp[N-2])/denom;

    // Substitution arrière
    x[N-1] = dp[N-1];
    for (int i=N-2; i>=0; i--) {
        x[i] = dp[i]-cp[i]*x[i+1];
    }

    return x;
}


template class Solver<double>;
template class Solver<Complex>;
template class Solver<Rational>;


