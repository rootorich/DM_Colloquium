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

/*
 * Masha
 * P-11
*/
P GCF_PP_P(const P& poly1, const P& poly2) {
    P n1 = poly1;
    P n2 = poly2;
    P mod = n1%n2;
    while (mod != 0) {
        n1 = n2;
        n2 = mod;
        mod = n1%n2;
    }
    return n2;
}

/*
 P-12
*/
P DER_P_P(const P& poly) {
    std::vector<Q> new_coeffs;
    for (int i = 1; i < poly.a.size(); i++) {
        new_coeffs.emplace_back(poly.a[i]*i);
    }
    P new_poly{new_coeffs};
    return new_poly;
}

P NMR_P_P(const P& poly) {
    P gcf = GCF_PP_P(poly, DER_P_P(poly));
    // нод содержит в себе только кратные корни степени k-1
    P result = poly/gcf;
    return result;
}
/*
 * End Mash
*/