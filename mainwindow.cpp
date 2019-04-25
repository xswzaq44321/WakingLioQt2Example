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
	thanus[0] = new QGraphicsPixmapItem(
				QPixmap(":/img/resources/thanus_before.png").scaled(400, 400, Qt::KeepAspectRatio, Qt::SmoothTransformation)
				);
	thanus[1] = new QGraphicsPixmapItem(
				QPixmap(":/img/resources/thanus_after.png").scaled(600, 600, Qt::KeepAspectRatio, Qt::SmoothTransformation)
				);

	scene->addItem(thanus[0]);
	thanus[0]->setPos(190, 60);
	scene->addItem(antman);
	antman->setZValue(100);

	timer.setInterval(20);
	timer.start();
	connect(&timer, &QTimer::timeout, [&](){
		if(antman->collidesWithItem(thanus[0], Qt::ContainsItemShape)){
			ui->pushButton->setEnabled(true);
		}else{
			ui->pushButton->setEnabled(false);
		}
	});
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_pushButton_clicked()
{
	scene->removeItem(thanus[0]);
	scene->addItem(thanus[1]);
	thanus[1]->setPos(75, -35);
	antman->setPixmap(
				QPixmap(":/img/resources/antman.png").scaled(250, 250, Qt::KeepAspectRatio, Qt::SmoothTransformation)
				);
	antman->setPos(330, 140);
}
