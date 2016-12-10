#include "cAlgMethod.h"

cAlgMethod::cAlgMethod(double x0, double y0, double right, double step) { 
    arr.push_back(y0);
    for (double x = x0;x < right;x += step) {
        arr.push_back((1 - step)*arr.back());
    }
}