#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QDebug>
#include <QVector>
#include <QTimer>

#include <cstdlib>
#include <ctime>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private:
	Ui::MainWindow *ui;
	QGraphicsScene *scene;
	QVector<QGraphicsItem*> items;
	QTimer timer;

	// QWidget interface
protected:
	void keyPressEvent(QKeyEvent *event);
};

#endif // MAINWINDOW_H
