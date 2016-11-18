#include <iostream>

#include "cSimpson.h"
#include "cGauss.h"

using namespace std;

class func : public cAbstractFunction {
    double operator()(double x);
};

int main() {
    func* f = new func();
    cSimpson* simpson = new cSimpson(1, 5, 10000, f);
    cout <<(*simpson)();
    vector<vector<double>> apr = simpson->apr(100);
    cout << "pass";
    return 0;
}

double func::operator()(double x) {
    return x*x + exp(x) + 1 / x;
}