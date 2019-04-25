#include "myscene.h"

MyScene::MyScene()
{

}

MyScene::MyScene(qreal x, qreal y, qreal width, qreal height):
	QGraphicsScene(x, y, width, height)
{
}

QPointF prevPos;
QGraphicsItem *obj = nullptr;

void MyScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	obj = this->itemAt(event->scenePos(), QTransform());
	prevPos = event->scenePos();
}

void MyScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	if(obj != nullptr){
		QPointF disp = event->scenePos() - prevPos;
		obj->setPos(obj->pos() + disp);
		prevPos = event->scenePos();
		qDebug() << obj->pos();
	}
}

void MyScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	obj = nullptr;
}
