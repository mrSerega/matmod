#include <iostream>
#include <vector>

using namespace std;

#ifndef AF_H
#define AF_H

class cAbstractMethod
{
public:
    cAbstractMethod();
    cAbstractMethod(cAbstractMethod* rhs);
    ~cAbstractMethod();
    double operator[](int index);
    size_t size();
protected:
    vector<double> arr;
};


#endif // !AF_H


