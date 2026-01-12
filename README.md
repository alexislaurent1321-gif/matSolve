Simple bibliothèque de résolution de système linéaire pour des systèmes réels, complexes, et entiers. Le programme vérifie si la matrice est : diagonale, tridiagonale, triangulaire, symétrique et utilise une méthode adaptée en conséquence. 


# Démo
La bibliothèque peut-être testée via la démo suivante : 
https://github.com/alexislaurent1321-gif/test_matSolve
[](#https://github.com/alexislaurent1321-gif/test_matSolve)

# Introduction

Ce projet a pour objectif d'implémenter différentes méthodes de
résolution de systèmes linéaires $Ax = b$ en créant une bibliothèque
C++. Les matrices et vecteurs utilisés peuvent être définis sur
différents ensembles numériques : $\mathbb{R}$ pour les réels,
$\mathbb{C}$ pour les complexes et $\mathbb{Z}$ pour les entiers.\
Le projet est également documenté avec Doxygen (compilation sur
doxywizard).

# Structure générale du projet

Le projet est organisé autour des fichiers suivants :

-   `Mat.h` et `Mat.cpp` : gestion des matrices,

-   `Vec.h` et `Vec.cpp` : gestion des vecteurs,

-   `Complex.h` et `Complex.cpp` : gestion des nombres complexes,

-   `Rational.h` et `Rational.cpp` : gestion des nombres rationnels,

-   `Solver.h` et `solve.cpp`, `diag.cpp`, `tridiag.cpp`, `climb.cpp`,
    `descent.cpp`, `Gauss.cpp`, `LU.cpp`, `Cholesky.cpp`,`CG.cpp` :
    implémentation des méthodes de résolution,

-   `utils.h` et `utils.cpp` : fonctions utilitaires (racine carrée,
    valeur absolue, etc.),

-   `main.cpp` et `main2.cpp`: programmes principaux.

## Classe `Vec` 

La classe `Vec` dérive de std::vector\<\> et offre des fonctionnalités
telles que :

-   la lecture à partir d'un fichier

-   les opérations vectorielles (+, -, \*, /),

-   le calcul de la norme ou de la valeur absolue des éléments.

-   l'affichage

## Classe `Mat` 

La classe `Mat` est dérivée de la classe `std::vector<Vec<> >`. On peut
donc effectuer des opérations vectorielles sur les lignes et utiliser
les fonctions de `std::vector` notamment `swap` pour échanger des lignes
et `inner_product` afin d'effectuer un produit scalaire partiel. Cette
classe permet de :

-   lire à partir d'un fichier

-   vérifier les propriétés de la matrice (diagonale, tridiagonale,
    triangulaire supérieure/inférieure, symétrique, hermitienne, creuse)

-   caculer le déterminant en fonction des propriétés de la matrice

-   calculer l'adjointe

-   effectuer des opérations comme le produit matrice-vecteur

-   l'affichage

## Classe `Solver` 

La classe solver contient de les méthodes de résolutions d'un système
linéaire. Chaque méthode est statique et prend en paramètre une matrice
et un vecteur. Elle contient le calcul de la norme du résidu. La
fonction `solve` permet de sélectionner la bonne méthode en fonction de
la matrice.

## Classes `Complex` et `Rational` 

Les types de nombres supportés sont :

-   `double` pour les réels,

-   `Complex` pour les complexes (avec opérateurs surchargés pour les
    calculs),

-   `Rational` pour les rationnels (avec gestion automatique de la
    réduction des fractions) dans le contexte des opérations sur les
    entiers.

Les class `Complex` et `Rational` ont été écrite afin de gérer ces
types. Elles permettent d'éffectuer les calculs et comparaisons de base.

## Ensemble de fonctions `utils.h` 

Dans les méthodes de résolution, nous devons utiliser des fonctions non
compatibles avec tous les types de nombre. Or, ces méthodes sont
templatées. On surcharge donc des fonctions pour chaque type dans un
nouveau fichier afin d'éviter les conflits de type. On trouve dans ce
fichier :

-   `SQRT` : Retourne la racine d'un nombre. Pour les nombre réels et
    entiers, cette fonctions fait appel à `std::sqrt`. Pour un nombre
    complexe elle retourne la racine carrée définie dans le code et ne
    fait rien pour les rationnels car cela nécessiterait un conversion
    en double.

-   `ABS` : Retourne `fabs` pour un double, la valeur absolue codée dans
    `Rational` pour les rationnels et ne fais rien pour les complexes.

-   `dot` : Calcul le produit scalaire de deux vecteurs et le produit
    hermitien si ceux-ci complexes.

-   `norm` : Retourne un double positif. Dans le cas rationnel, il
    retourne la valeur absolue convertie en double et retourne le module
    pour un complexe.

-   `isNumRational` : Retourne vrai si un nombre est rationnel, faux
    sinon.

-   `conj` : Retourne le conjugué complexe si le nombre est complexe. Ne
    fait rien sinon.

