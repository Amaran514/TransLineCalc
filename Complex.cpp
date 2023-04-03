#include "Complex.h"
#include <cmath>

Complex::Complex(double re, double im) {
    this->re = re;
    this->im = im;
    this->magnitude = sqrt(re * re + im * im);
    this->phase = atan2(im, re);
}

double Complex::getRe() const {
    return re;
}

double Complex::getIm() const {
    return im;
}

double Complex::getMagnitude() const {
    return magnitude;
}

double Complex::getPhase() const {
    return phase;
}

Complex operator+(const Complex &c1, const Complex &c2) {
    double new_re = c1.re + c2.re;
    double new_im = c1.im + c2.im;
    Complex res(new_re, new_im);
    return res;
}

Complex operator-(const Complex &c1, const Complex &c2) {
    double new_re = c1.re - c2.re;
    double new_im = c1.im - c2.im;
    Complex res(new_re, new_im);
    return res;
}

Complex operator*(const Complex &c1, const Complex &c2) {
    double new_re = c1.re * c2.re - c1.im * c2.im;
    double new_im = c1.re * c2.im + c1.im * c2.re;
    Complex res(new_re, new_im);
    return res;
}

Complex operator/(const Complex &c1, const Complex &c2) {
    double cm = c2.re * c2.re + c2.im * c2.im;
    double new_re = (c1.re * c2.re + c1.im * c2.im) / cm;
    double new_im = (c1.im * c2.re - c1.re * c2.im) / cm;
    Complex res(new_re, new_im);
    return res;
}

bool Complex::operator==(const Complex &c) const {
    return (re == c.re) && (im == c.im);
}

bool Complex::operator!=(const Complex &c) const {
    return !(*this == c);
}
