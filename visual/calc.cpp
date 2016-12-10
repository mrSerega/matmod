#include "calc.h"
#include <math.h>

double calc::_a(int i){
	//TODO
	return 0;
}

double calc::_b(int i){
	//TODO
	return 0;
}

double calc::_h(int i){
	return _x(i+1)-_x(i);
}

double calc::_t(int i){
	return __t[i];
}

double calc::_tau(int i){
	return _t(i+1)-_t(i);
}

double calc::_x(int i){
	return __x[i];
}

double calc::_y(int n, int m){
	return __y[n][m];
}

double calc::_c(int n, int m){
	//TODO
	return _x(n)*exp(_t(m));
}

double calc::_f(int n, int m){
	//qDebug("ok");
	m-=1;
	if(_x(n)==0) return _a(m);
	if(_t(m)==0) return _b(n);
	//критерий куранта
	if(_c(n,m+1)*_tau(m)<=_h(n-1)){
		return (_fi(n,m)-_c(n,m+1)/_h(n-1)*(_y(n,m)-_y(n-1,m)))*_tau(m)+_y(n,m);
	}else
	{
		return _y(n-1,m+1)-_h(n-1)/_c(n,m+1)*(1/_tau(m)*(_y(n-1,m+1)-_y(n-1,m))-_fi(n,m));
	}
}

double calc::_fi(int n, int m){
	//TODO
	return sin(_x(n))+_x(n)*exp(_t(m))*_t(m)*cos(_x(n));
	//return sin(_x(n));
}

std::vector<std::vector<double> > calc::getVec(){
	return __y;
}
