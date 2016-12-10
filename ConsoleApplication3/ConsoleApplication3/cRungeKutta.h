#include "cAbstractMethod.h"
#include "cAbstractFunction.h"

#ifndef DF_H
#define DF_H

class cRungeKutta : public cAbstractMethod
{
public:
    cRungeKutta(cAbstractFunction* f, double x0, double y0, double right, double step);
};

#endif // !DF_H


