#include "painter.h"

#include <QGraphicsScene>

painter::~painter(){
//	delete scene;
}

//painter::painter(std::vector<std::vector<double> > y,
//				 std::vector<double> x,
//				 std::vector<double> t,
//				 QGraphicsView *view)
//{
//	//TODO: exception
//}

void painter::print(int t, QGraphicsView* v){
	QGraphicsScene* scene = new QGraphicsScene();
	scene->addLine(-240,nullyplus,240,nullyplus,QPen(Qt::gray));
	scene->addLine(nullxplus,-120,nullxplus,120,QPen(Qt::gray));
	for(int x=0;x<xSize-1;++x){
		addPoint(_x[x],_y[x][t],_x[x+1],_y[x+1][t],scene);
	}
	v->setScene(scene);
}

void painter::addPoint(double x, double y, double secondx, double secondy, QGraphicsScene* scene){
	x*=power;
	x+=nullxplus;
	y*=power;
	y*=-1;
	y+=nullyplus;
	secondx*=power;
	secondx+=nullxplus;
	secondy*=power;
	secondy*=-1;
	secondy+=nullyplus;
	scene->addLine(x,y,secondx,secondy);
}
