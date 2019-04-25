#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	this->scene = new MyScene(0, 0,
							  ui->graphicsView->width() - 2,
							  ui->graphicsView->height() - 2);
	ui->graphicsView->setScene(scene);
	antman = new QGraphicsPixmapItem(
				QPixmap(":/img/resources/antman.png").scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation)
				);
	daisy = new QGraphicsPixmapItem(
				QPixmap(":/img/resources/purple daisy.png").scaled(400, 400, Qt::KeepAspectRatio, Qt::SmoothTransformation)
				);

	scene->addItem(daisy);
	daisy->setPos(190, 60);
	scene->addItem(antman);
	antman->setZValue(100);

	timer.setInterval(20);
	timer.start();
	connect(&timer, &QTimer::timeout, [&](){
		if(antman->collidesWithItem(daisy, Qt::ContainsItemShape)){
			ui->label->setText("蟻人在紫色的菊花內");
		}else{
			ui->label->setText("蟻人不在紫色的菊花內");
		}
	});
}

MainWindow::~MainWindow()
{
	delete ui;
}
