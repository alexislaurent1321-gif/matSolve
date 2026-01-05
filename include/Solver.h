/** 
 * @file Solver.h
 * \brief classe Solver contenant les méthode de résolution de systèmes linéaires. 
 * \author Alexis LAURENT
 * \author Killian DALLERAC
 * \date Décembre 2024
 */

#include "Vec.h"
#include "Mat.h"

#ifndef SOLVER_H
#define SOLVER_H

/**
 * \brief Classe Solver contenant les méthode statiques de résolution de systèmes linéaires.
 */
template <class T>
class Solver {
public:

    /**
     * \brief Méthode de montée si la matrice est triangulaire supérieure
     */
    static Vec<T> climb(const Mat<T>& A, const Vec<T>& b);

    /**
     * \brief Méthode de descente si la matrice est triangulaire inférieure
     */
    static Vec<T> descent(const Mat<T>& A, const Vec<T>& b);
    
    /**
     * \brief Méthode de résolution pour une matrice diagonale
     */
    static Vec<T> diag(const Mat<T>& A, const Vec<T>& b);

    /**
     * \brief Méthode de résolution pour une matrice tridiagonale
     */
    static Vec<T> Thomas(const Mat<T>& A, const Vec<T>& b);
    template Vec<T> Thomas(const Mat<T>& A, const Vec<T>& b);

    /**
     * \brief Méthode de résolution pour une matrice inversible quelconque
     */
    static Vec<T> Gauss(const Mat<T>& A, const Vec<T>& b);

    /**
     * \brief Méthode de résolution pour une matrice LU décomposable
     */
    static Vec<T> LU(const Mat<T>& A, const Vec<T>& b);

    /**
     * \brief Méthode de résolution pour une matrice symétrique non rationnelle
     */
    static Vec<T> Cholesky(const Mat<T>& A, const Vec<T>& b);

    /**
     * \brief Descente de gradient conjugué pour une matrice suffisament creuse
     */
    static Vec<T> CG(const Mat<T>& A, const Vec<T>& b);

    /**
     * \brief Résout le système linéaire avec la meilleure méthode selon les propriétés de la matrice
     */
    static Vec<T> solve(const Mat<T>& A, const Vec<T>& b);

    /**
     * \brief Calcule et retourne le maximum du résidu Ax-b
     */
    static T computeResNormInf(const Mat<T>& A, const Vec<T>& x, const Vec<T>& b);
};

#endif