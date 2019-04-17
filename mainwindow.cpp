#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	this->scene = new QGraphicsScene();
	scene->addEllipse(0, 0, 60, 20);
	ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
	delete ui;
}
