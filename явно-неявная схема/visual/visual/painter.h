#include <vector>
#include <QGraphicsView>

#ifndef PAINTER_H
#define PAINTER_H


class painter
{
private:
	int xSize;
	int tSize;
	std::vector<std::vector<double,double> > _y;
	std::vector<double> _x;
	std::vector<double> _t;
	QGraphicsView* _view;
	QGraphicsScene* _scene;
	double nullxplus;
	double nullyplus;
	double power;
public:
	painter(std::vector<std::vector<double,double> > y,
			std::vector<double> x,
			std::vector<double> t,
			QGraphicsView* view):
		_y{y},
		_x{x},
		_t{t},
		xSize{x.size()},
		tSize{t.size()},
		_view{view},
		_scene{nullptr},
		nullxplus{0},
		nullyplus{0},
		power{1}{}
	~painter();
	void print(int t);
};

#endif // PAINTER_H
