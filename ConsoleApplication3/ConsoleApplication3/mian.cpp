#include "cRungeKutta.h"
#include "cAlgMethod.h"

class cF1 :public cAbstractFunction {
public:
    virtual double calc(double x, double y);
};


int main() 
{
    cF1* my_cF1 = new cF1();

    cRungeKutta my_cRungeKutta(my_cF1, 0.0, 24.0, 0.1, 0.001);
    cAlgMethod my_cAlgMethod(0.0, 24.0, 0.1, 0.001);

    for (size_t i = 0;i < my_cRungeKutta.size();i++) {
        cout << my_cRungeKutta[i] <<"\t"<<my_cAlgMethod[i]<< endl;
    }

    delete my_cF1;

    return 0;
}

double cF1::calc(double x, double y)
{
    return -1 * y;
}