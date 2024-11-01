#include "Z.h"

/*
 * Masha
 * Z-2
*/
uint8_t POZ_Z_D(const Z num) {
    if (num.digits.size() == 1 && num.digits[0] == 0)
        return 0;
    return num.sign + 1; 
}
/*
 * End Masha
*/