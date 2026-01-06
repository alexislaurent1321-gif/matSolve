/**
 * \file Rational.h
 * \brief Classe rationnelle
 * \author Alexis LAURENT
 * \author Killian DALLERAC
 * \date Décembre 2024
 */

#include <cassert>
#include <iostream>
#include <cmath>
#include <numeric>

#if !defined(RATIONAL_H)
#define RATIONAL_H

/**
 * \brief Classe de rationnelle servant à résoudre des systèmes entiers ou rationnels
 */
class Rational
{
    /**
     * \brief numérateur et dénominateur
     */
    long int a, b; 

    /**
     * \brief Simplifie la fraction rationnelle 
     */
    void simplify();

public:
    // Constructeurs
    /**
     * \brief Constructeur par défaut avec un entier
     */
    Rational(long int a_=0) : a(a_), b(1) {simplify();}

    /**
     * \brief Constructeur d'un rationnel quelconque
     */
    Rational(long int a_, long int b_) : a(a_), b(b_) {simplify();}

    /**
     * \brief Constructeur par copie
     */
    Rational(const Rational& q) : a(q.a), b(q.b) {simplify();}

    /**
     * \brief Retourne le numérateur
     */
    long int num() const {return a;}

    /**
     * \brief Retourne le dénominateur
     */
    long int denom() const {return b;}

    void num(long int num_){a = num_;}
    void denom(long int denom_){b = denom_;}

    /**
     * \brief Retourne la conversion en double du nombre rationnel
     */
    double value() const{return (double)a/b;}

    /**
     * \brief Retourne la fraction inverse
     */
    Rational inv() const{return Rational(b,a);}

    // Opérations binaires avec un entier
    Rational operator+(const long int& n) const;
    Rational operator-(const long int& n) const;
    Rational operator*(const long int& n) const;
    Rational operator/(const long int& n) const;

    // Opérations unaires avec un entier
    Rational& operator+=(const long int& n);
    Rational& operator-=(const long int& n);
    Rational& operator*=(const long int& n);
    Rational& operator/=(const long int& n);
    
    // Opérations binaires
    Rational operator+(const Rational& q) const;
    Rational operator-(const Rational& q) const;
    Rational operator*(const Rational& q) const;
    Rational operator/(const Rational& q) const;

    bool operator==(const Rational& q) const;
    bool operator!=(const Rational& q) const;
    bool operator<(const Rational& q) const;
    bool operator>(const Rational& q) const;
    bool operator<=(const Rational& q) const;
    bool operator>=(const Rational& q) const;

    // Opérations unaires
    Rational& operator+=(const Rational& q);
    Rational& operator-=(const Rational& q);
    Rational& operator*=(const Rational& q);
    Rational& operator/=(const Rational& q);
    Rational operator-() const;
 
    // Affichage

    /**
     * \brief Affichage d'une rationnel par l'instruction cout << 
     */
    friend std::ostream& operator<<(std::ostream &os, const Rational& q);

    /**
     * \brief Lecture d'un entier à partir d'un fichier par l'instruction cin >>. On attribue au dénominateur la valeur 1
     */
    friend std::istream& operator>>(std::istream& in, Rational& q);   
};

#endif