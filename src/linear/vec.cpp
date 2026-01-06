/**
 * @file Vec.cpp
 */

#include "matSolve/linear/vec.h"
#include "matSolve/numbers/complex.h"
#include "matSolve/numbers/rational.h"
#include "matSolve/utils/utils.h"

// Constructeur

template <class T>
Vec<T>::Vec(const char* fileName) : vector<T>(0){
    std::string ficdon(fileName);
    std::ifstream fdon(ficdon.c_str());

    int N;
    fdon >> N;
    int m; fdon >> m;
  
    T a;
    for(int i=0; i<N; i++){
        fdon >> a;
        (*this).push_back(a);
    }

    fdon.close();
}

template <class T>
void Vec<T>::init(T a){
    for(int i=0; i<(*this).size(); i++) 
        (*this)[i]=a;
}

template <class T>
Vec<T> Vec<T>::abs() const{
    Vec<T> Vabs((*this).size());
    for(int i=0; i<(*this).size(); i++){
        Vabs[i] = ABS((*this)[i]);
    }
    return Vabs;
}

// Opérations vectorielles 

template <class T>
Vec<T> Vec<T>::operator+(const Vec<T>& V) const{
    assert((*this).size() == V.size());
    Vec<T> W(V.size(),0);
    for(int i=0; i<W.size(); i++)
        W[i] = (*this)[i]+V[i];
    return W;
}

template <class T>
Vec<T> Vec<T>::operator-(const Vec<T>& V) const{
    assert((*this).size() == V.size());
    Vec<T> W(V.size(),0);
    for(int i=0; i<W.size(); i++)
        W[i] = (*this)[i]-V[i];
    return W;
}

template <class T>
Vec<T>& Vec<T>::operator+=(const Vec<T>& V){
    assert((*this).size() == V.size());
    for(int i=0; i<V.size(); i++) 
        (*this)[i]+=V[i];
    return *this;
}

template <class T>
Vec<T>& Vec<T>::operator-=(const Vec<T>& V){
    assert((*this).size() == V.size());
    for(int i=0; i<V.size(); i++) 
        (*this)[i]-=V[i];
    return *this;
}


// Opérations scalaires

template <class T>
Vec<T> Vec<T>::operator*(const T& a) const{
    Vec W = *this;
    for(int i=0; i<(*this).size(); i++) 
        W[i]*=a;
    return W;
}

template <class T>
Vec<T> Vec<T>::operator/(const T& a) const{
    Vec W = *this;
    for(int i=0; i<(*this).size(); i++) 
        W[i]/=a;
    return W;
}

template <class T>
Vec<T>& Vec<T>::operator*=(const T& a){
    for(int i=0; i<(*this).size(); i++) 
        (*this)[i]*=a; 
    return *this;
}

template <class T>
Vec<T>& Vec<T>::operator/=(const T& a){
    for(int i=0; i<(*this).size(); i++) 
        (*this)[i]/=a; 
    return *this;
}

template <class T> 
bool Vec<T>::operator==(const Vec<T>& V) const{
    if((*this).size() != V.size()) 
        return false;
    for(int i=0; i<V.size(); i++){
        if((*this)[i] != V[i]){
            return false;
        }
    }
    return true;
}

template class Vec<double>;
template class Vec<Complex>;
template class Vec<Rational>;
