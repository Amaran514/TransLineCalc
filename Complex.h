#ifndef TRANSLINECALC_COMPLEX_H
#define TRANSLINECALC_COMPLEX_H

class Complex {
    double re, im, magnitude, phase;
public:
    explicit(false) Complex(double re = 0, double im = 0);

    double getRe() const;

    double getIm() const;

    double getMagnitude() const;

    double getPhase() const;

    friend Complex operator+(const Complex &c1, const Complex &c2);

    friend Complex operator-(const Complex &c1, const Complex &c2);

    friend Complex operator*(const Complex &c1, const Complex &c2);

    friend Complex operator/(const Complex &c1, const Complex &c2);

    bool operator==(const Complex &c) const;

    bool operator!=(const Complex &c) const;
};

#endif //TRANSLINECALC_COMPLEX_H
