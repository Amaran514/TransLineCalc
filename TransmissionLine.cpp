#define _USE_MATH_DEFINES

#include "TransmissionLine.h"

TransmissionLine::TransmissionLine() {
    this->z0 = 50;
    this->zl = Complex(50, 0);
    this->wavelength = 1;
    this->beta = 2 * M_PI / wavelength;
}

TransmissionLine::TransmissionLine(double z0, Complex zl, double wavelength) {
    this->z0 = z0;
    this->zl = zl;
    this->wavelength = wavelength;
    this->beta = 2 * M_PI / wavelength;
}

double TransmissionLine::getZ0() const {
    return z0;
}

Complex TransmissionLine::getZl() const {
    return zl;
}

double TransmissionLine::getWavelength() const {
    return wavelength;
}

Complex TransmissionLine::calZin(double z) {
    Complex res = z0 * (zl + Complex(0, z0 * tan(beta * z))) / (z0 + Complex(0, 1) * zl * tan(beta * z));
    return res;
}

Complex TransmissionLine::calReflectCoef(double z) {
    Complex res = (calZin(z) - z0) / (calZin(z) + z0);
    return res;
}

double TransmissionLine::calSwr() {
    Complex rcoef = calReflectCoef();
    double res = (1 + rcoef.getMagnitude()) / (1 - rcoef.getMagnitude());
    return res;
}
