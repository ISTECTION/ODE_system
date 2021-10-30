#ifndef _RUNGEKUTTA_HPP_
#define _RUNGEKUTTA_HPP_
#include "Data.hpp"
#include <filesystem>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <tuple>

namespace _vec {
    using _double = std::vector<double>;
}

const size_t N = 2;

int sign(double _n) { return (_n < 0 ? -1 : (_n > 0 ? 1 : 0)); }

std::tuple<double, double> f(double t, const _vec::_double &y) {
    double dq = t > 1 ?
                Data::q0     - y[1] :
                Data::q0 * t - y[1] ;

    double dp = y[0] - Data::P_atm;

    return {
        dq / Data::C,
        Data::B * sqrt(Data::Zeta * abs(dp)) * (Data::F * sqrt(2 * abs(dp)) * sign(dp) - y[1])
    };
}


class RungeKutta
{
public:
    RungeKutta() { };
    ~RungeKutta() { };

    void RungeKuttaSys(double _h = Data::H1);

private:
    std::tuple<double, double> RungeKutta4(double, double, const _vec::_double &);
    void writeFile(std::filesystem::path _Path, std::ostringstream &ostream, double h) const;


};

void RungeKutta::RungeKuttaSys(double _h) {

    std::ostringstream ostream;

    double t = Data::t0, h = _h;
    _vec::_double y { Data::P_atm, 0 };
    _vec::_double _y_next(N);


    ostream.precision(6); ostream << std::setw(8) << t;

    ostream << std::setw(20) << std::scientific << y[0]
            << std::setw(16) << std::fixed      << y[1] << std::endl;


    for (double _s = t + h; _s <= Data::t1; _s += h) {

        std::tie(_y_next[0], _y_next[1]) = RungeKutta4(_s - h, h, y);

        ostream.precision(6); ostream << std::setw(8) << _s;

        y[0] = _y_next[0];
        y[1] = _y_next[1];

        ostream << std::setw(20) << std::scientific << y[0]
                << std::setw(16) << std::fixed      << y[1] << std::endl;

    }
    writeFile("file", ostream, h);
}


std::tuple<double, double> RungeKutta::RungeKutta4(double t, double h, const _vec::_double &y) {

    _vec::_double k1(N), k2(N), k3(N), k4(N), _y(N);

    std::tie(k1[0], k1[1]) = f(t, y);
    for (size_t i = 0; i < N; i++)
        _y[i] = y[i] + 0.5 * h * k1[i];

    std::tie(k2[0], k2[1]) = f(t + 0.5 * h, _y);
    for (size_t i = 0; i < N; i++)
        _y[i] = y[i] + 0.5 * h * k2[i];

    std::tie(k3[0], k3[1]) = f(t + 0.5 * h, _y);
    for (size_t i = 0; i < N; i++)
        _y[i] = y[i] + 0.5 * h * k3[i];

    std::tie(k4[0], k4[1]) = f(t + h, _y);

    return {
        y[0] + h * (k1[0] + 2 * k2[0] + 2 * k3[0] + k4[0]) / 6,
        y[1] + h * (k1[1] + 2 * k2[1] + 2 * k3[1] + k4[1]) / 6
    };
}


void RungeKutta::writeFile(std::filesystem::path _Path, std::ostringstream &ostream, double h) const {

    std::ostringstream _stream;
    _stream.precision(0);
    _stream << std::scientific << h;

    std::ofstream fout(_Path / _stream.str().substr(0, 5).append(".txt"));
    fout << ostream.str();
    fout.close();
}

#endif // _RUNGEKUTTA_HPP_