#pragma once

#include "cAbstractMethod.h"

#ifndef AM_H
#define AM_H

class cAlgMethod: public cAbstractMethod
{
public:
    cAlgMethod(double x0, double y0, double right, double step);
};

#endif

