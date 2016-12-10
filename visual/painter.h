#include <vector>
#include <QGraphicsView>

#ifndef PAINTER_H
#define PAINTER_H


class painter
{
private:
	int xSize;
	int tSize;
	std::vector<std::vector<double> > _y;
	std::vector<double> _x;
	std::vector<double> _t;
	double nullxplus;
	double nullyplus;
	double power;
public:
	painter(std::vector<std::vector<double> > y,
			std::vector<double> x,
			std::vector<double> t):
		_y{y},
		_x{x},
		_t{t},
		xSize{x.size()},
		tSize{t.size()},
		nullxplus{0},
		nullyplus{0},
		power{1}{}
	~painter();
	void print(int t,QGraphicsView* v);
	void addPoint(double x,double y,double secondx, double secondy ,QGraphicsScene* scene);
};

#endif // PAINTER_H
