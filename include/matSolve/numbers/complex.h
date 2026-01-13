/**
 * \file complex.h
 * \brief Classe complexe
 * \author Alexis LAURENT
 * \author Killian DALLERAC
 * \date Décembre 2024
 */

#if !defined(COMPLEX_H)
#define COMPLEX_H

#include <cassert>
#include <iostream>
#include <cmath>

/**
 * \brief Classe basique de complexes
 */
class Complex {

private:
    double re, im;

public:
    // Constructeurs
    /**
     * \brief Constructeur par défaut avec un réel
     */
    Complex(double re_=0) : re(re_), im(0) {}

    /**
     * \brief Constructeur avec un réel et imaginaire
     */
    Complex(double re_, double im_) : re(re_), im(im_) {}

    /**
     * \brief Constructeur par copie
     */
    Complex(const Complex& z) : re(z.re), im(z.im) {}

    /**
     * \brief Nombre i statique
     */
    static const Complex i;

    // Accesseurs pour les parties réelle et imaginaire     
    double real() const { return re; }
    double imag() const { return im; }
    void real(double real_) { re = real_; }
    void imag(double imag_) { im = imag_; }

    // Méthodes sur les complexes
    /**
     * \brief Retourne le module
     */
    double modulus() const { return std::sqrt(re*re + im*im); }

    /**
     * \brief Retourne le conjugué
     */
    Complex conj() const { return Complex(re,-im); }

    /**
     * \brief Retourne l'argument
     */
    double angle() const { return std::atan2(im,re); }

    // Opérations avec un réel
    Complex operator+(const double& a) const;
    Complex operator-(const double& a) const;
    Complex operator*(const double& a) const;
    Complex operator/(const double& a) const;

    // Opérations binaires
    Complex operator+(const Complex& z) const;
    Complex operator-(const Complex& z) const;
    Complex operator*(const Complex& z) const;
    Complex operator/(const Complex& z) const;
    bool operator==(const Complex& z) const;
    bool operator!=(const Complex& z) const;  
    bool operator<(const Complex& z) const;  
    bool operator>(const Complex& z) const;   

    // Opérations unaires
    Complex& operator+=(const Complex& z);
    Complex& operator-=(const Complex& z);
    Complex& operator*=(const Complex& z);
    Complex& operator/=(const Complex& z);
    Complex operator-() const;

    /**
     * \brief Affichage d'une complexe par l'instruction cout << 
     */
    friend std::ostream& operator<<(std::ostream& os, const Complex& z);

    /**
     * \brief Lecture d'un complexe à partir d'un fichier par l'instruction cin >>. Lis deux réels espacés
     */
    friend std::istream& operator>>(std::istream& is, Complex& z);
};




#endif