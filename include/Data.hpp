#ifndef _DATA_HPP_
#define _DATA_HPP_

#define _USE_MATH_DEFINES
#include <cmath>

namespace Data
{
    const double H1 = 1E-4;
    const double H2 = 1E-5;

    const double t0 = 0 ;
    const double t1 = 20;

    const double P_atm = 1E+5;
    const double q0    = 1E-3;
    const double l     = 1   ;
    const double d     = 0.01;
    const double Ro    = 1000;
    const double C_snd = 1260;

    const double Alpha = M_PI / 4;
    const double Zeta  = 1 - cos(Alpha);
    const double S     = Alpha * d * d;
    const double C     = l * S / (Ro * C_snd * C_snd);
}

#endif // _DATA_HPP_