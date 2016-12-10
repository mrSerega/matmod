#include <iostream>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "../simpson-x2/simpson-x2/cGauss.h"
#include "../simpson-x2/simpson-x2/cSimpson.h"

double yrange = 0;//sorry

int NUMOFFUNC = 0;

class func: public cAbstractFunction{
public:
	double operator()(double x);
};

class fi: public cAbstractFunction{
public:
	double _i;
	fi(double i):
		_i{i}
	{}
	double operator()(double x){
		return pow(x,_i);
		//return cos((_i+1)*x);
		//return sin((_i+1)*x);
	}
};

class sum_func: public cAbstractFunction
{
public:
	std::vector<double> _k;
	std::vector<cAbstractFunction*> _f;
	sum_func(std::vector<double> k, std::vector<cAbstractFunction*> f):
		_k{k},
		_f{f}
	{}
	double operator()(double x){
		double sum = 0;
		for(int i=0;i<_k.size();++i){
			sum+=_k[i]*(*_f[i])(x);
		}
		return sum;
	}
};



class to_Simpson: public cAbstractFunction{
public:
	cAbstractFunction* _f1;
	cAbstractFunction* _f2;
	to_Simpson(cAbstractFunction* f1, cAbstractFunction* f2):
		_f1{f1},
		_f2{f2}
	{}
	double operator()(double x){
		return (*_f1)(x)*(*_f2)(x);
	}
};

#define PWR 1000

double scalar(cAbstractFunction* left_func, cAbstractFunction* right_func, double left, double right){
	cSimpson simpson(left,right,PWR,new to_Simpson(left_func,right_func));
	return 1/(right-left)*simpson();
}

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



	std::vector<std::vector<double>> for_gaus(NUMOFFUNC);
	std::vector<double> free;


	for(int i=0;i<NUMOFFUNC;++i){
		for(int j=0;j<NUMOFFUNC;++j){
			for_gaus[i].push_back(scalar(new fi(i),new fi(j),left,right));
		}
		free.push_back(scalar(new fi(i),new func(),left,right));
	}

	func* f = new func();
//	cSimpson* simpson = new cSimpson(left, right, n, f);
//	ui->answer->setText(std::to_string((*simpson)()).data());
//	std::vector<std::vector<double>> apr = simpson->apr(nprint);

//	qDebug(std::to_string(apr.size()).data());

//	double h = (right-left)/nprint;
//	h/=2;
//	h/=1000;

	QVector<double> x;
	QVector<double> y;

	//####
//	for(int i=0;i<apr.size();i++){
//		for(double j = apr[i][3];j<apr[i][4];j+=h){
//			x.push_back(j);
//			y.push_back(simpson->parabola(apr[i][0],apr[i][1],apr[i][2],j));
//		}
//	}
	//###

	cGauss g(cMatrix(for_gaus),free);
	std::vector<double> ans = g();
	std::vector<cAbstractFunction*> ans_f;

	for(int i=0;i<NUMOFFUNC;++i){
		ans_f.push_back(new fi(i));
	}

	sum_func sf(ans,ans_f);

#define h 0.01

	for(double xx = left;xx<right;xx+=h){
		x.push_back(xx);
		y.push_back(sf(xx));
	}

	ui->widget->addGraph();
	ui->widget->graph(0)->setData(x,y);
	ui->widget->xAxis->setLabel("x");
	ui->widget->yAxis->setLabel("y");
	ui->widget->xAxis->setRange(left, right);
	ui->widget->yAxis->setRange(-yrange, yrange);

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
	return  x*sin(x)+cos(x);
}

void MainWindow::on_verticalSlider_valueChanged(int value)
{
	yrange = value;
	ui->widget->yAxis->setRange(-value,value);
	ui->widget->replot();
}

void MainWindow::on_numslider_valueChanged(int value)
{
	NUMOFFUNC = value;
	ui->num->setText(std::to_string(value).data());
}
