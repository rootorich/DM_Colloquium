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

    P p1;

    for(size_t i = 0; i < p.a.size(); ++i){
        p1.a[i] = p.a[i]*q;
    }

    return p1;

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
//P-8

P operator*(const P& p1, const P& p2){

    P product;
    product.a.emplace_back(0);

    if((p1.a.size() == 1 && p1.a[0].z == 0 )||
       (p2.a.size() == 1 && p2.a[0].z == 0 )){
        return product;
    }

    for (size_t i = 0; i < p2.a.size(); ++i) {
        if(p2.a[i].z != 0){
            product += (p1 *p2.a[i]) << i;
        }
    }

    return product;
}

P MUL_PP_P(const P& p1, const P& p2){

    return p1*p2;
}
//Efimova

