#include <cstdio>
#include "Complex.h"
#include "TransmissionLine.h"

int main() {
    Complex c1(1, 2);
    Complex c2(3, 6);
    Complex c3 = c2 - c1;
    Complex c4 = c1 * c3;
    Complex c5 = c2 / c1;
    printf("c3 = %f+j%f  %fe^j%f\n", c3.getRe(), c3.getIm(), c3.getMagnitude(), c3.getPhase());
    printf("c4 = %f+j%f  %fe^j%f\n", c4.getRe(), c4.getIm(), c4.getMagnitude(), c4.getPhase());
    printf("c5 = %f+j%f  %fe^j%f\n", c5.getRe(), c5.getIm(), c5.getMagnitude(), c5.getPhase());

    Complex c6(2, 4);
    printf("c3 == c6 : %d\n", c3 == c6);
    printf("c3 != c4 : %d\n", c3 != c4);

    Complex c7 = c6 + 1;
    Complex c8 = c6 - 1;
    Complex c9 = c6 * 2;
    Complex c10 = c6 / 2;
    Complex c11 = 1 + c6;
    Complex c12 = 2 * c6;
    printf("c7 = %f+j%f  %fe^j%f\n", c7.getRe(), c7.getIm(), c7.getMagnitude(), c7.getPhase());
    printf("c8 = %f+j%f  %fe^j%f\n", c8.getRe(), c8.getIm(), c8.getMagnitude(), c8.getPhase());
    printf("c9 = %f+j%f  %fe^j%f\n", c9.getRe(), c9.getIm(), c9.getMagnitude(), c9.getPhase());
    printf("c10 = %f+j%f  %fe^j%f\n", c10.getRe(), c10.getIm(), c10.getMagnitude(), c10.getPhase());
    printf("c11 = %f+j%f  %fe^j%f\n", c11.getRe(), c11.getIm(), c11.getMagnitude(), c11.getPhase());
    printf("c12 = %f+j%f  %fe^j%f\n", c12.getRe(), c12.getIm(), c12.getMagnitude(), c12.getPhase());

    (c3 = c2) = c1;
    printf("c1 = %f+j%f  %fe^j%f\n", c1.getRe(), c1.getIm(), c1.getMagnitude(), c1.getPhase());
    printf("c2 = %f+j%f  %fe^j%f\n", c2.getRe(), c2.getIm(), c2.getMagnitude(), c2.getPhase());
    printf("c3 = %f+j%f  %fe^j%f\n", c3.getRe(), c3.getIm(), c3.getMagnitude(), c3.getPhase());

    TransmissionLine l1;
    TransmissionLine l2(50, Complex(75, 0), 0.5);
    printf("l1: z0 = %f, zl = %f+j%f, wavelength = %f\n", l1.getZ0(), l1.getZl().getRe(), l1.getZl().getIm(), l1.getWavelength());
    printf("l2: z0 = %f, zl = %f+j%f, wavelength = %f\n", l2.getZ0(), l2.getZl().getRe(), l2.getZl().getIm(), l2.getWavelength());
    printf("l2's zin: %f+j%f\n", l2.calZin(0.1).getRe(), l2.calZin(0.1).getIm());

    return 0;
}
