#include "painter.h"

#include <QGraphicsScene>

painter::~painter(){
	delete scene;
}

painter::painter(std::vector<std::vector<double, double> > y,
				 std::vector<double> x,
				 std::vector<double> t,
				 QGraphicsView *view)
{
	//TODO: exception
}

void painter::print(int t){
	scene = new QGraphicsScene();
	for(int x=0;x<=xSize;++x){
		addPoint(x,data[x][t]);
	}
}

void painter::addPoint(double x, double y){
	x*=power;
	x+=nullxplus;
	y*=power;
	y*=-1;
	y+=nullyplus;
	scene->addLine(x,y,x,y);
}
