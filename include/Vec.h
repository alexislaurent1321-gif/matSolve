/**
 * \file Vec.h
 * \brief Classe de vecteurs dérivée de la classe std::vector<>
 * \author Alexis LAURENT
 * \author Killian DALLERAC
 * \date Décembre 2024
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cassert>
#include <fstream>
using namespace std;

#ifndef VEC_H
#define VEC_H

/**
 * \brief Classe de vecteurs dévirée de la classe std::vector avec opérations vectorielles de base
 */
template <class T>
class Vec : public vector<T>
{
public:

    /**
     * \brief Construit un vecteur avec sa taille
     */
    Vec(int N=1) : vector<T>(N) {}

    /**
     * \brief Construit un vecteur avec sa taille et remplissage avec un nombre
     */
    Vec(int N, T a) : vector<T>(N,a) {}

    /**
     * \brief Construit un vecteur par copie
     */
    Vec(const Vec<T>& V) : vector<T>(V) {}

    /**
     * \brief Construit un vecteur à partir du nom d'un fichier
     */
    Vec(const char* fileName);



    // Méthodes utiles

    /**
     * \brief Remplie un vecteur avec un nombre
     */
    void init(T a=0);

    /**
     * \brief Retourne un vecteur avec les valeurs absolues
     */
    Vec<T> abs() const; // Retourne la valeur absolue des éléments


    // Opérations vectorielles
    Vec<T> operator+(const Vec<T>& V) const;
    Vec<T> operator-(const Vec<T>& V) const;
    Vec<T>& operator+=(const Vec<T>& V);
    Vec<T>& operator-=(const Vec<T>& V);

    // Opérations avec un scalaire
    Vec<T> operator*(const T& a) const;
    Vec<T> operator/(const T& a) const;
    Vec<T>& operator*=(const T& a);
    Vec<T>& operator/=(const T& a);

    /**
     * \brief Deux vecteurs sont égaux si ils sont de même taille et ont les mêmes composantes
     */
    bool operator==(const Vec<T>& V) const;

    /**
     * \brief Affichage d'un vecteur par l'instruction cout << 
     */
    friend std::ostream& operator<<(std::ostream& os, const Vec<T>& V) {
        os << "["; for(int i=0; i<V.size()-1; i++) os << V[i] << " "; os << V[V.size()-1] << "]";
        return os;
    }
};

#endif