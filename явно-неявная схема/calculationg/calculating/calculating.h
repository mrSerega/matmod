#include <vector>

#ifndef CALCULATIONG_H
#define CALCULATIONG_H


class calculating
{
private:
	int tSize;//количетсво дискретных значений t
	int xSize;//количесвто дискретных значений x

	std::vector<double> __t;//дискретное время
	std::vector<double> __x;//дискретный x
	std::vector<std::vector<double> > __y;//дискретный y

	double _a(int i);//начальное условие по t для x = 0
	double _b(int i);//начальное условие по x для t = 0
	double _t(int i);//возвращает значение времени на доанном дискретном промежутке
	double _h(int i);
	double _tau(int i);
	double _x(int i);//возвращает значение x на данном дискретном промежутке
	double _y(int n, int m);
	double _c(int n, int m);
	double _f(int n, int m);
	double _fi(int n,int m);
public:
	calculating(std::vector<double> t_vector, std::vector<double> x_vector):
		__t{t_vector},
		__x{x_vector},
		tSize{t_vector.size()},
		xSize{x_vector.size()}{}
};

#endif // CALCULATIONG_H
