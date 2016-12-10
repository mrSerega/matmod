#include "cAbstractMethod.h"

cAbstractMethod::cAbstractMethod() {
    //TODO
}

cAbstractMethod::cAbstractMethod(cAbstractMethod* rhs) {
    for (int i = 0;i < rhs->size();++i) {
        arr[i] = (*rhs)[i];
    }
}

cAbstractMethod::~cAbstractMethod() {
    //TODO
}

size_t cAbstractMethod::size() {
    return arr.size();
}

double cAbstractMethod::operator[](int index) {
    if (index < 0) index += size();
    if (index > size()) throw "cRungeKutta::index out of range\n";
    if (index < 0) throw "cRungeKutta::index out of range\n";
    return arr[index];
}