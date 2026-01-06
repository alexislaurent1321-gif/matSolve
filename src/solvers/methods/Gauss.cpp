#include <algorithm>
#include "solvers/solver.h"
#include "numbers/complex.h"
#include "numbers/rational.h"

template class Solver<double>;
template class Solver<Complex>;
template class Solver<Rational>;

template <class T>
Vec<T> Solver<T>::Gauss(const Mat<T>& A, const Vec<T>& b){

    Mat<T> U(A); // matrice échelonnée supérieure à partir de A
    Vec<T> y(b); // vecteur du système échelonné
    int N = b.size(); // taille du système

    for(int j=0; j<N-1; j++)
    {
        // Calcul du pivot maximal
        Vec<T> col = U.col(j).abs();    // première colonne non nulles en valeur absolue
        auto itPivot = max_element(col.begin()+j, col.end());   // maximum de cette colonne
        int index = distance(col.begin(), itPivot);     // indice de la ligne avec le plus grand pivot

        // Echange de ligne pour avoir le pivot max en haut
        U[index].swap(U[j]); 
        swap(y[index],y[j]);

        // Triangulation à partir du pivot maximal
        for(int i=j+1; i<N; i++){
            y[i] -= y[j]*U[i][j]/U[j][j];
            U[i] -= U[j]*U[i][j]/U[j][j];
        }
    }
    // Résolution du système triangulaire supérieur
    Vec<T> x = climb(U,y);
    
    return x;
}
template Vec<double> Solver<double>::Gauss(const Mat<double>& A, const Vec<double>& b);
template Vec<Complex> Solver<Complex>::Gauss(const Mat<Complex>& A, const Vec<Complex>& b);
template Vec<Rational> Solver<Rational>::Gauss(const Mat<Rational>& A, const Vec<Rational>& b);
