#ifndef ABSTRACT_FUNCTION_21102016
#define ABSTRACT_FUNCTION_21102016

class cAbstractFunction {
public:
    cAbstractFunction();
    ~cAbstractFunction();
    virtual double calc(double x, double y) = 0;
};

#endif