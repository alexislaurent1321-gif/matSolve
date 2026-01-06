/**
 * \file Mat.h
 * \brief Classe de matrice dérivée de la classe std::vector<Vec<>>
 * \author Alexis LAURENT
 * \author Killian DALLERAC
 * \date Décembre 2024
 */

#include "Vec.h"

#if !defined(MAT_H)
#define MAT_H

using namespace std;

/**
 * \brief Classe de matrice dérivée de std::vector<Vec<>>
 */
template <class T>
class Mat : public vector<Vec<T>>{
    int nl, nc; // nombre de lignes et de colonnes

public:

    /**
     * \brief Construction d'une matrice avec le nombre de lignes et le nombre de colonnes
     */
    Mat(int nl_=1, int nc_=1);

    /**
     * \brief Construction par copie d'une matrice
     */
    Mat(const Mat& M);

    /**
     * \brief Construction d'une matrice à partir du nom d'un fichier
     */
    Mat(const char* fileName);


    /**
     * \brief Remplie la matrice avec un nombre
     */
    void init(T a);

    /**
     * \brief Créer la transposée de la matrice passée en paramètre
     */
    Mat<T> transpose();


    // Opérations
    
    /**
     * \brief Produit matrice vecteur
     */
    Vec<T> operator*(const Vec<T>& V) const;

    /**
     * \brief Deux vecteurs sont égaux si ils sont de même taille et ont les mêmes composantes
     */
    bool operator==(const Mat<T>& M) const;


    // get

    /**
     * \brief Retourne le vecteur colonne
     */
    Vec<T> col(int j) const;

    /**
     * \brief Retourne le nombre de lignes
     */
    inline int nRows() const { return nl; }

    /**
     * \brief Retourne le nombre de colonnes
     */
    inline int nCols() const { return nc; }

    // Propriétés
    /**
     * \brief Vérifie si la matrice est diagonale
     */
    bool isDiag() const;

    /**
     * \brief Vérifie si la matrice est tridiagonale
     */
    bool isTridiag() const;

    /**
     * \brief Vérifie si la matrice est triangulaire supérieure
     */
    bool isUpper() const;

    /**
     * \brief Vérifie si la matrice est triangulaire inféreure
     */
    bool isLower() const;

    /**
     * \brief Vérifie si la matrice est hermitienne
     */
    bool isHermitian() const;

    /**
     * \brief Vérifie si la matrice est inversible (déterminant non nul)
     */
    bool isInvertible() const;

    /**
     * \brief Vérifie si la matrice est rationelle
     */
    bool isRational() const;

    /**
     * \brief Vérifie si la matrice est LU décomposable
     */
    bool isLUDecomposable() const;

    /**
     * \brief Vérifie si la matrice est sparse
     */
    bool isSparse(double threshold = 0.7) const;

    // Déterminant
    /**
     * \brief Calcul du déterminant
     */
    T det() const;

    /**
     * \brief Affiche la matrice par l'instruction cout >>
     */
    friend std::ostream& operator<<(std::ostream& os, const Mat<T>& M) {
        os << "["; for(int i=0; i<M.nl-1; i++) os << M[i] << "\n"; os << M[M.nl-1] << "]";
        return os;
    }

    ~Mat(){}
};

#endif

