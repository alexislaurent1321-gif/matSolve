/**
 * @file Mat.cpp
 */

#include "Mat.h"
#include "numbers/Complex.h"
#include "numbers/Rational.h"
#include "Vec.h"
#include "utils.h"


// Implémentations des méthodes de Mat
template <class T>
Mat<T>::Mat(int nl_, int nc_) : nl(nl_), nc(nc_), vector<Vec<T>>(nl_) {
    for (int i=0; i<nl; i++) (*this)[i] = Vec<T>(nc);
}

template <class T>
Mat<T>::Mat(const Mat<T>& M) : nl(M.nl), nc(M.nc), vector<Vec<T>>(M.nl) {
    for (int i=0; i<nl; i++) (*this)[i] = M[i];
}

template <class T>
Mat<T>::Mat(const char* fileName) : vector<Vec<T>>(0){
    std::string ficdon(fileName);
    std::ifstream fdon(ficdon.c_str());

    fdon >> nl;
    fdon >> nc;

    for(int i=0; i<nl; i++) 
        (*this).push_back(Vec<T>(nc));


    for(int i=0; i<nl; i++){
        for(int j=0; j<nc; j++){
            fdon >> (*this)[i][j];
        }
    }

    fdon.close();
}


template <class T>
Mat<T> Mat<T>::transpose(){
    Mat<T> Mt(nc,nl);
    for(int i=0; i<nc; i++){
        for(int j=0; j<nl; j++){
            Mt[i][j] = conj((*this)[j][i]);
        }  
    }
    return Mt;
}

template <class T>
void Mat<T>::init(T a) {
    for (int i=0; i<nl; i++) 
        (*this)[i].init(a);
}

template <class T>
Vec<T> Mat<T>::col(int j) const{
    Vec<T> column(nl,0);
    for(int i=0; i<nl; i++)
        column[i] = (*this)[i][j];
    return column;
}

// Opérations
template <class T>
Vec<T> Mat<T>::operator*(const Vec<T>& V) const{
    assert(nc ==  V.size());
    Vec<T> U(nl,0);
    for (int i=0; i<nl; i++){
        for (int j=0; j<nc; j++){
            U[i] += (*this)[i][j]*V[j];
        }
    } 
    return U;
}

template <class T> 
bool Mat<T>::operator==(const Mat<T>& M) const{
    if((*this).nc != M.nc || (*this).nl != M.nl) 
        return false;
    for(int i=0; i<M.size(); i++){
        if((*this)[i] != M[i]){
            return false;
        }
    }
    return true;
}



// Propriétés
template <class T>
bool Mat<T>::isDiag() const{
    for(int i=0; i<nl; i++){
        for(int j=0; j<nc; j++){
            if(i!=j && (*this)[i][j]!=T(0)){
                return false;
            }
        }
    }
    return true;
}

template <class T>
bool Mat<T>::isLUDecomposable() const {
    // Vérification des mineurs principaux
    for (int k=1; k<=nRows(); ++k) {
        // Extraction du sous-bloc k x k
        Mat<T> subMatrix(k,k);
        for (int i=0; i<k; ++i) {
            for (int j=0; j<k; ++j) {
                subMatrix[i][j] = (*this)[i][j];
            }
        }

        // Calcul du déterminant du sous-bloc
        T det = subMatrix.det();
        if (det == T(0)) {
            return false; // Un mineur principal est nul
        }
    }

    return true;
}

template <class T>
bool Mat<T>::isSparse(double threshold) const {
    int totalElements = nRows()*nCols();
    int zeroCount = 0;

    // Compte le nombre de zéros
    for (int i=0; i<nRows(); i++) {
        for (int j=0; j<nCols(); j++) {
            if ((*this)[i][j] == T(0)) {
                zeroCount++;
            }
        }
    }

    double sparsity = static_cast<double>(zeroCount) / totalElements;
    // Si au moins 70% des éléments sont nuls, on considère que la matrice est creuse
    return sparsity >= threshold;
}


template <class T>
bool Mat<T>::isHermitian() const{
    for (int i = 0; i < nRows(); i++) {
        for (int j = 0; j < nCols(); j++) {
            if ((*this)[i][j] != conj((*this)[j][i])) {
                return false;
            }
        }
    }
    return true;
}

template <class T>
bool Mat<T>::isTridiag() const{
    for(int i=0; i<nl; i++){
        for(int j=0; j<nc; j++){
            if(abs(i-j)>1 && (*this)[i][j]!=T(0))
                return false;
        }
    }
    return true;
}

template <class T>
bool Mat<T>::isUpper() const{
    for(int i=0; i<nl; i++){
        for(int j=i; j<nc; j++){
            if((*this)[i][j]!=T(0))
                return false;
        }
    }
    return true;
}

template <class T>
bool Mat<T>::isLower() const{
    for(int i=0; i<nl; i++){
        for(int j=0; j<=i; j++){
            if((*this)[i][j]!=T(0))
                return false;
        }
    }
    return true;
}

template <class T>
bool Mat<T>::isInvertible() const{
    T d = det();
    cout << "det =  " << d << endl;
    return d != T(0);
}

template <class T>
bool Mat<T>::isRational() const{
    return isNumRational((*this)[0][0]);
}


// Déterminant

// Méthode générale : élimination de Gauss
template <class T>
T Mat<T>::det() const{
    // Vérifie si la matrice est carrée
    if (nRows() != nCols()) {
        throw std::runtime_error("La matrice doit etre carree !");
    }
    int N = nRows();

    // Cas matrice diagonale
    if (isDiag()) {
        T det = T(1);
        for (int i=0; i<N; i++) {
            det *= (*this)[i][i];
        }
        return det;
    }

    if (isTridiag()){
        Vec<T> D(N,T(0)); // tableau contenant les déterminants successifs

        D[0] = (*this)[0][0];                
        D[1] = (*this)[1][1]*(*this)[0][0]-(*this)[1][0]*(*this)[0][1]; 
        // Calcul du déterminant de manière itérative
        for (int i=2; i<N; ++i) {
            D[i] = (*this)[i][i]*(*this)[i-1][i-1]-(*this)[i][i-1]*(*this)[i-1][i]*D[i-2];
        }
        return D[N-1];
    }
    

    // Cas matrice triangulaire supérieure
    if (isUpper()) {
        T det = T(1);
        for (int i=0; i<N; i++) {
            det *= (*this)[i][i];
        }
        return det;
    }

    // Cas matrice triangulaire inférieure
    if (isLower()) {
        T det = T(1);
        for (int i=0; i<N; i++) {
            det *= (*this)[i][i];
        }
        return det;
    }

    Mat<T> copy(*this); // Copie de la matrice pour ne pas modifier l'originale
    T result = T(1);

    for (int k=0; k<nl; k++) {
        // Vérification du pivot
        if (copy[k][k]==T(0)) return T(0); // Si un pivot est nul, le déterminant est nul

        // Élimination
        for (int i=k+1; i<N; i++) {
            T factor = copy[i][k]/copy[k][k];
            for (int j=k; j<N; j++) {
                copy[i][j] -= factor*copy[k][j];
            }
        }

        // Produit des pivots diagonaux
        result *= copy[k][k];
    }
    return result;
}

template class Mat<double>;
template class Mat<Complex>;
template class Mat<Rational>;
