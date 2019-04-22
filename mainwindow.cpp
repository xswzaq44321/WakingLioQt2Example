#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	this->scene = new QGraphicsScene(0, 0, ui->graphicsView->width() - 2, ui->graphicsView->height() - 2);
	scene->addEllipse(0, 0, 60, 20);
	ui->graphicsView->setScene(scene);

	{
		QPixmap bar(100, 100);
		bar.fill(Qt::black);
		QPainter painter(&bar);
		painter.setPen(Qt::cyan);
		painter.drawArc(0, 0, 100, 100, 210*16, 120*16);
		auto item = scene->addPixmap(bar);
		item->setPos(100, 0);
	}
}

MainWindow::~MainWindow()
{
	delete ui;
}


void MainWindow::keyPressEvent(QKeyEvent *event)
{
	if(event->key() == Qt::Key_W)
		qDebug() << "key W pressed";
}
