#ifndef TRANSLINECALC_TRANSMISSIONLINE_H
#define TRANSLINECALC_TRANSMISSIONLINE_H

#include "Complex.h"
#include <cmath>

class TransmissionLine {
    double z0, wavelength, beta;
    Complex zl;
public:
    TransmissionLine();

    TransmissionLine(double z0, Complex zl, double wavelength);

    double getZ0() const;

    Complex getZl() const;

    double getWavelength() const;

    Complex calZin(double z = 0);

    Complex calReflectCoef(double z = 0);

    double calSwr();
};


#endif //TRANSLINECALC_TRANSMISSIONLINE_H
