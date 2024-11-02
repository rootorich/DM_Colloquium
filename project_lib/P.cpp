#include "P.h"

//Efimova
P operator-(const P& p1){

    P p = p1;

    for (size_t i = 0; i < p.a.size(); ++i){
        p.a[i] = -p.a[i];
    }

    return p;

}


P operator+(const P& p1, const P& p2){


    P result = (p1.a.size() >= p2.a.size()) ? p1 : p2;
    P min = (p1.a.size() < p2.a.size()) ? p1: p2;

    for (size_t i = 0; i < min.a.size(); ++i) {
        result.a[i] = result.a[i] + min.a[i];
    }

    return result;

}


P operator-(const P& p1, const P& p2){
    
    return p1+(-p2);

}


P operator*(const P& p, const Q& q){

    P p;

    for(size_t i = 0; i < p.a.size(); ++i){
        p.a[i] = p.a[i]*q;
    }

    return p;

}

//P-1
P ADD_PP_P(const P& p1, const P& p2) {

    return p1+p2;

}

//P-2
P SUB_PP_P(const P& p1, const P& p2){

    return p1 - p2;
}

//P-3
P MUL_PQ_P(const P& p, const Q& q){

    return p*q;

}
//Efimova

