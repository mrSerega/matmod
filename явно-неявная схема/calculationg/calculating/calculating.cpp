#include "calculating.h"

calculating::calculating(std::vector<double> t_vector, std::vector<double> x_vector)
{
	for(int x = 1;x<xSize;++x){
		for(int t = 1;t<tSize;++t){
			__y[x][t]=_f(x,t);
		}
	}
}

double calculating::_a(int i){
	//TODO
	return 0;
}

double calculating::_b(int i){
	//TODO
	return 0;
}

double calculating::_c(int n, int m){
	//TODO
	return 0;
}

double calculating::_h(int i){
	return _x(i+1)-_x(i);
}

double calculating::_t(int i){
	return __t[i];
}

double calculating::_tau(int i){
	return _t(i+1)-_t(i);
}

double calculating::_x(int i){
	return __x[i];
}

double calculating::_y(int n, int m){
	return __y[n][m];
}

double calculating::_c(int n, int m){
	//TODO
	return 0;
}

double calculating::_f(int n, int m){
	m-=1;
	if(_x(n)==0) return _a(m);
	if(_t(m)==0) return _b(n);
	//критерий куранта
	if(_c(n,m+1)*_tau(m)<=_h(n-1)){
		return (_fi(n,m)-_c(n,m+1)/h(n-1)*(_y(n,m)-_y(n-1,m)))*_tau(m)+_y(n,m);
	}else
	{
		return _y(n-1,m+1)-_h(n-1)/_c(n,m+1)*(1/_tau(m)*(_y(n-1,m+1)-_y(n-1,m))-_fi(n,m));
	}
}

double calculating::_fi(int n, int m){
	//TODO
	return 0;
}
