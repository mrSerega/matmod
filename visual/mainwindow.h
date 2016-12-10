#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "painter.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

private slots:
	void on_left_clicked();

	void on_right_clicked();

	void on_slider_changed(int value);

	void on_ui_slider_valueChanged(int value);

private:
	painter* mypainter;
	int t;
	int tsize;
	int xsize;

	Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
