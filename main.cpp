#include <iostream>
#include "clipp.h"
#include "Complex.h"
#include "TransmissionLine.h"

using namespace clipp;
using std::cout;
using std::endl;

int main(int argc, char *argv[]) {
    enum class mode {
    zin, rcoef, swr
    };
    mode selected = mode::zin;
    double z0, wavelength, z = 0, zl_re, zl_im = 0;
    bool exp_format = false;
    auto cli = (
            (option("-zin").set(selected, mode::zin) |
             option("-rcoef").set(selected, mode::rcoef) |
             option("-swr").set(selected, mode::swr)) % "choose what to calculate",
            (required("-z0") & value("charaimpedance", z0)) % "specify line's characteristic impedance (Ω)",
            (required("-l") & value("wavelength", wavelength)) % "specify wavelength (m)",
            (required("-r") & value("realpart", zl_re)) % "specify load's real part (Ω)",
            (option("-i") & value("imaginarypart", zl_im)) % "specify load's imaginary part (Ω) (default is 0)",
            (option("-d") & value("distance", z)) % "specify distance from the end of the line (m) (default is 0)",
            option("-e").set(exp_format) % "use exponential format for complex number");

    if (!parse(argc, argv, cli)) {
        cout << make_man_page(cli, argv[0]);
        return 1;
    }

    TransmissionLine line(z0, Complex(zl_re, zl_im), wavelength);
    switch (selected) {
        case mode::zin: {
            Complex zin = line.calZin(z);
            if (exp_format) {
                cout << "Zin = " << zin.getMagnitude() << "+e^j" << zin.getPhase() << endl;
                return 0;
            } else {
                cout << "Zin = " << zin.getRe() << "+j" << zin.getIm() << endl;
            }
            break;
        }
        case mode::rcoef: {
            Complex rcoef = line.calReflectCoef(z);
            if (exp_format) {
                cout << "Reflect Coef = " << rcoef.getMagnitude() << "+e^j" << rcoef.getPhase() << endl;
                return 0;
            } else {
                cout << "Reflect Coef = " << rcoef.getRe() << "+j" << rcoef.getIm() << endl;
            }
            break;
        }
        case mode::swr: {
            double swr = line.calSwr();
            cout << "SWR = " << swr << endl;
            break;
        }
    }
    return 0;
}
