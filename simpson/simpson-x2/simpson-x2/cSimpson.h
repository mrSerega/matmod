#include <vector>

#include "cAbstractFunction.h"

#ifndef C_SIMPSON_H
#define C_SIMPSON_H

class cSimpson
{
public:
    cSimpson();
    cSimpson(double left, double right, unsigned int n, cAbstractFunction* function);
    ~cSimpson();

    double operator()();
    std::vector<std::vector<double> > apr(unsigned int n);

    double parabola(double a, double b, double c, double x);
private:
    cAbstractFunction* f;
    double _left;
    double _right;
    unsigned int _n;
};

#endif