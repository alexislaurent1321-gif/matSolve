/*! \mainpage Project Title

\section intro_sec Introduction

Ce projet avait pour objectif d'implémenter différentes méthodes de résolution de systèmes 
linéaires $Ax = b$ en créant une bibliothèque C++. Les matrices et vecteurs utilisés peuvent 
être définis sur différents ensembles numériques : réels, complexes et entiers. Pour le traitement 
de ces derniers, on aura recours à une classe Rational qui gère les éléments de l'ensemble des nombres 
rationnels.
*/

#include "Mat.h"
#include <iostream>
#include "Rational.h"
#include "Complex.h"
#include "Vec.h"
#include "Solver.h"
#include "utils.h"

using namespace std;


int main()
{
    // Double

    Mat<double> Ad("Matrices2/matrice_int.txt");
    Vec<double> bd("Matrices2/vector_int.txt");

    cout << "\n=== Resolution pour les reels ===" << endl;
    Vec<double> xd = Solver<double>::Gauss(Ad, bd);

    double rd = Solver<double>::computeResNormInf(Ad, xd, bd);
    cout << "norme inf de Ax-b : " << rd << endl;


    // Complexe 1

    Mat<Complex> Ac("Matrices2/matrice_complex.txt");
    Vec<Complex> bc("Matrices2/vector_complex.txt");

    cout << "\n=== Resolution pour les complexes ===" << endl;
    Vec<Complex> xc = Solver<Complex>::Gauss(Ac, bc);

    Complex rc = Solver<Complex>::computeResNormInf(Ac, xc, bc);
    cout << "norme inf de Ax-b : " << rc << endl;


    // Rationnel
    
    Mat<Rational> Ai("Matrices2/matrice_int.txt");
    Vec<Rational> bi("Matrices2/vector_int.txt");

    cout << "\n=== Resolution pour les rationnels ===" << endl;
    Vec<Rational> xi = Solver<Rational>::Gauss(Ai, bi);

    Rational ri = Solver<Rational>::computeResNormInf(Ai, xi, bi);
    cout << "norme inf de Ax-b : " << ri.value() << endl;



    return 0;
}
