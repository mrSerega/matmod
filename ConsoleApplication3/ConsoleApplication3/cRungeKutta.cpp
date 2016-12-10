#include "cRungeKutta.h"

cRungeKutta::cRungeKutta(cAbstractFunction* f, double x0, double y0, double right, double step)
{
    arr.push_back(y0);
    for (double x = x0;x < right;x += step)
    {
        double yx = arr.back();
        double k1 = f->calc(x, yx);
        double k2 = f->calc(x + step / 2.0, yx + k1*step / 2.0);
        double k3 = f->calc(x + step / 2.0, yx + k2*step / 2.0);
        double k4 = f->calc(x + step, yx + k3*step);
        double det = step*(k1 + 2 * k2 + 2 * k3 + k4) / 6;
        arr.push_back(yx + det);
    }         
}
