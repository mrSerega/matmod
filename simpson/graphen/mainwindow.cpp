#include <iostream>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "../simpson-x2/simpson-x2/cGauss.h"
#include "../simpson-x2/simpson-x2/cSimpson.h"

double yrange = 0;//sorry

class func: public cAbstractFunction{
public:
	double operator()(double x);
};

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_press_clicked()
{
	double left = ui->left->toPlainText().toDouble();
	double right = ui->right->toPlainText().toDouble();
	int n = ui->n->toPlainText().toInt();
	int nprint = ui->nprint->toPlainText().toInt();

	func* f = new func();
	cSimpson* simpson = new cSimpson(left, right, n, f);
	ui->answer->setText(std::to_string((*simpson)()).data());
	std::vector<std::vector<double>> apr = simpson->apr(nprint);

	qDebug(std::to_string(apr.size()).data());

	double h = (right-left)/nprint;
	h/=2;
	h/=1000;

	QVector<double> x;
	QVector<double> y;

	for(int i=0;i<apr.size();i++){
		for(double j = apr[i][3];j<apr[i][4];j+=h){
			x.push_back(j);
			y.push_back(simpson->parabola(apr[i][0],apr[i][1],apr[i][2],j));
		}
	}

	ui->widget->addGraph();
	ui->widget->graph(0)->setData(x,y);
	ui->widget->xAxis->setLabel("x");
	ui->widget->yAxis->setLabel("y");
	ui->widget->xAxis->setRange(left, right);
	ui->widget->yAxis->setRange(0, yrange);

	QVector<double> truex;
	QVector<double> truey;

	for(double j=left;j<right;j+=h){
		truex.push_back(j);
		truey.push_back((*f)(j));
	}

	ui->widget->addGraph();
	ui->widget->graph(1)->setData(truex,truey);
	ui->widget->graph(1)->setPen(QColor(255, 0, 0, 255));

	ui->widget->replot();
}

double func::operator()(double x) {
	return  1 / (x*x*x*x);
}

void MainWindow::on_verticalSlider_valueChanged(int value)
{
	yrange = value;
	ui->widget->yAxis->setRange(0,value);
	ui->widget->replot();
}
