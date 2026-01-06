/*! \mainpage Project Title

\section intro_sec Introduction

Ce projet a pour objectif d'implémenter différentes méthodes de résolution de systèmes 
linéaires $Ax = b$ en créant une bibliothèque C++. Les resources/matrices et vecteurs utilisés peuvent 
être définis sur différents ensembles numériques : réels, complexes et entiers. Pour le traitement 
de ces derniers, on aura recours à une classe Rational qui gère les éléments de l'ensemble des nombres 
rationnels.
*/

#include "matSolve/linear/mat.h"
#include <iostream>
#include "matSolve/numbers/rational.h"
#include "matSolve/numbers/complex.h"
#include "matSolve/linear/vec.h"
#include "matSolve/solvers/solver.h"
#include "matSolve/utils/utils.h"

using namespace std;


int main()
{
    // Double

    Mat<double> Ad("resources/matrices/matrice_reelle.txt");
    Vec<double> bd("resources/matrices/vecteur_b_reel.txt");

    cout << "\n=== Resolution pour les reels ===" << endl;
    Vec<double> xd = Solver<double>::solve(Ad, bd);
    cout << "Solution calculee : " << xd << endl;

    Vec<double> sold("resources/matrices/solution_x_reel.txt");
    cout << "Solution exacte   : " << sold << endl;

    double rd = Solver<double>::computeResNormInf(Ad, xd, bd);
    cout << "norme inf de Ax-b : " << rd << endl;


    // Complexe 1

    Mat<Complex> Ac("resources/matrices/matrice_complexe.txt");
    Vec<Complex> bc("resources/matrices/vecteur_b_complexe.txt");

    cout << "\n=== Resolution pour les complexes ===" << endl;
    Vec<Complex> xc = Solver<Complex>::solve(Ac, bc);
    cout << "Solution calculee : " << xc << endl;

    Vec<Complex> solc("resources/matrices/solution_x_complexe.txt");
    cout << "Solution exacte   : " << solc << endl;

    Complex rc = Solver<Complex>::computeResNormInf(Ac, xc, bc);
    cout << "norme inf de Ax-b : " << rc << endl;


    // Complexe 2

    Mat<Complex> Ac2("resources/matrices/matrice_complexe2.txt");
    Vec<Complex> bc2("resources/matrices/vecteur_b_complexe2.txt");

    cout << "\n=== Resolution pour les complexes ===" << endl;
    Vec<Complex> xc2 = Solver<Complex>::solve(Ac2, bc2);

    Complex rc2 = Solver<Complex>::computeResNormInf(Ac2, xc2, bc2);
    cout << "norme inf de Ax-b : " << rc2 << endl;


    // Rationnel
    
    Mat<Rational> Ai("resources/matrices/matrice_entier.txt");
    Vec<Rational> bi("resources/matrices/vecteur_b_entier.txt");

    cout << "\n=== Resolution pour les rationnels ===" << endl;
    Vec<Rational> xi = Solver<Rational>::solve(Ai, bi);
    cout << "Solution calculee : " << xi << endl;

    Vec<Rational> soli("resources/matrices/solution_x_entier.txt");
    cout << "Solution exacte   : " << soli << endl;

    Rational ri = Solver<Rational>::computeResNormInf(Ai, xi, bi);
    std::cout << "norme inf de Ax-b : " << ri << std::endl;


    // Rationnel2
    
    Mat<Rational> Ai2("resources/matrices/matrice_reelle.txt");
    Vec<Rational> bi2("resources/matrices/vecteur_b_reel.txt");

    cout << "\n=== Resolution pour les rationnels ===" << endl;
    Vec<Rational> xi2 = Solver<Rational>::solve(Ai2, bi2);

    Rational ri2 = Solver<Rational>::computeResNormInf(Ai2, xi2, bi2);
    std::cout << "norme inf de Ax-b : " << ri2.value() << std::endl;


    return 0;
}
