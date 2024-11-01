#ifndef DM_COLLOQUIUM_Z_H
#define DM_COLLOQUIUM_Z_H

//Efimova Z-4
struct Z : N {

    bool sign;
    Z& operator=(const N& n);

};

Z& Z:: operator=(const N& n);
Z TRANS_N_Z(const N& n);

//Efimova Z-8
Z MUL_ZZ_Z(const Z& z1, const Z& z2);

#endif;


