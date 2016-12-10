#include <vector>
#include <QSlider>

#include "painter.h"
#include "calc.h"

using namespace std;

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	//create a slider
//	QSlider* slider = ui->ui_slider;
//	connect(slider,SIGNAL(valueChanged(int)),this,SLOT(on_slider_changed(int)));
	//code here
	xsize = 250;
	tsize = 100;
	t= tsize/2;
	vector<vector<double> > myy;
	vector<double> myt;
	vector<double> myx;

	//vector<double> emptyvector;

	for(int x=0;x<xsize;++x){
		myx.push_back(x);
	}

	for(int t=0;t<tsize;++t){
		myt.push_back(t);
	}

	calc* mycalc = new calc(myt,myx);
	myy = mycalc->getVec();

	mypainter = new painter(myy,myx,myt);
	//
	ui->setupUi(this);
}

MainWindow::~MainWindow()
{
	delete ui;
}


void MainWindow::on_left_clicked()
{
	if(t<=0){
		//pass
	}else{
		t--;
	}
	ui->tb->setText(to_string(t).data());
	mypainter->print(t,ui->view);
}

void MainWindow::on_right_clicked()
{
	if(t>=tsize){
		//pass
	}else{
		t++;
	}
	ui->tb->setText(to_string(t).data());
	mypainter->print(t,ui->view);
}

//void MainWindow::on_slider_changed(int value){
//	qDebug("well");
//	if((value>=0) && (value<=tsize)){
//		t=value;
//	}
//	ui->tb->setText(to_string(t).data());
//	mypainter->print(t,ui->view);
//}

void MainWindow::on_ui_slider_valueChanged(int value)
{
	ui->ui_slider->setMinimum(0);
	ui->ui_slider->setMaximum(tsize-1);
	//qDebug("well");
	if((value>=0) && (value<=tsize)){
		t=value;
	}
	ui->tb->setText(to_string(t).data());
	mypainter->print(t,ui->view);
}
