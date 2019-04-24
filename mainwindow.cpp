#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	this->scene = new QGraphicsScene(0, 0, ui->graphicsView->width() - 2, ui->graphicsView->height() - 2);
	auto item = scene->addEllipse(0, 0, 60, 20);
	ui->graphicsView->setScene(scene);
	items.push_back(item);

	srand(time(NULL));
	timer.setInterval(100);
	timer.start();
	connect(&timer, &QTimer::timeout, [&](){
		ui->label->setText(QString().sprintf("item count: %d", items.count()));
	});
	connect(&timer, &QTimer::timeout, [&](){
		int x = rand() % (int)scene->width();
		int y = rand() % (int)scene->height();
		auto item = scene->addRect(x, y, 1, 1);
		items.push_back(item);
	});
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
