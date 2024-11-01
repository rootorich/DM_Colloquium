#include <vector>
#include <cstdint>
#include <utility>

#ifndef DM_COLLOQUIUM_Z_H
#define DM_COLLOQUIUM_Z_H

//Efimova Z-4
struct Z : N {

    bool sign;
    Z& operator=(const N& n);

};

Z& Z:: operator=(const N& n);
Z TRANS_N_Z(const N& n);



