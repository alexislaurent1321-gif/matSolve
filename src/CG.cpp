#include "Solver.h"
#include "Complex.h"
#include "Rational.h"
#include "utils.h"
#include <cmath>
#include <cassert>

template class Solver<double>;
template class Solver<Complex>;
template class Solver<Rational>;

template <class T>
Vec<T> Solver<T>::CG(const Mat<T>& A, const Vec<T>& b) {
    int N = b.size();
    
    // Initialisation de x0, résidu intial et direction initiale
    Vec<T> x(N,T(0));         
    Vec<T> r = b-A*x;   
    Vec<T> p = r;           
    T rs_old = dot(r,r);
    double eps = 1e-16; 

    int count = 0;
    for (int k=0; k<N; ++k) {
        count++;

        Vec<T> Ap = A*p;      
        T alpha = rs_old/dot(p,Ap);
        // M-à-j de la solution et du résidu
        x += p*alpha;      
        r -= Ap*alpha;     

        T rs_new = dot(r,r);
        if (norm(rs_new) < pow(eps,2)) break;

        T beta = rs_new/rs_old;
        // M-à-j de la direction
        p = r+p*beta;       
        rs_old = rs_new;
    }
    cout << "Converge au bout de " << count << " itération(s)" << endl;

    return x;
}
template Vec<double> Solver<double>::CG(const Mat<double>& A, const Vec<double>& b);
template Vec<Complex> Solver<Complex>::CG(const Mat<Complex>& A, const Vec<Complex>& b);
template Vec<Rational> Solver<Rational>::CG(const Mat<Rational>& A, const Vec<Rational>& b);

