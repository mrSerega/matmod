#include "cSimpson.h"
#include <math.h>

#include "cGauss.h"


cSimpson::cSimpson()
{
}

cSimpson::cSimpson(double left, double right, unsigned int n, cAbstractFunction* function):
    _left{left},
    _right{right},
    _n{n},
    f{function}
{}

cSimpson::~cSimpson()
{
}

double cSimpson::operator()()
{
    double h = ((_right - _left)*1.0) / (_n*1.0);
    h /= 2;
    double _2i1 = 0;
    double _2i = 0;
    for (size_t i = 1; i < _n; ++i) {
        _2i1 += (*f)(_left + h*(2*i-1));
        _2i += (*f)(_left + h*(2 * i));
    }
    double _0 = (*f)(_left);
    double _2n = (*f)(_right);
    return (h/3 * (_0+4*_2i1+2*_2i+_2n));
}

std::vector<std::vector<double> > cSimpson::apr(unsigned int n) 
{
    std::vector<std::vector<double> > vec;
    std::vector < std::vector<double> > tmp_mat(3);
    std::vector<double> tmp_vec(3, 0);
    for (size_t i = 0; i < 3; i++) {
        tmp_mat[i].resize(3, 0);
    }
    double h = ((_right - _left)*1.0) / (n*1.0);
    h /= 2;
    for (size_t i = 1; i <= n; ++i) {
        double x2i2 = _left + (2 * i - 2)*h;
        double x2i1 = _left + (2 * i - 1)*h;
        double x2i = _left + 2 * i*h;
        tmp_mat[0][0] = pow(x2i2, 2.0); tmp_mat[0][1] = x2i2; tmp_mat[0][2] = 1; tmp_vec[0] = (*f)(x2i2);
        tmp_mat[1][0] = pow(x2i1, 2.0); tmp_mat[1][1] = x2i1; tmp_mat[1][2] = 1; tmp_vec[1] = (*f)(x2i1);
        tmp_mat[2][0] = pow(x2i, 2.0); tmp_mat[2][1] = x2i; tmp_mat[2][2] = 1; tmp_vec[2] = (*f)(x2i);
        cGauss* gauss = new cGauss(cMatrix(tmp_mat), tmp_vec);
        vec.push_back((*gauss)());
        vec.back().push_back(x2i2);
        vec.back().push_back(x2i);
    }
    return vec;
}

double cSimpson::parabola(double a, double b, double c, double x) {
    return a*x*x + b*x + c;
}
